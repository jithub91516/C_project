CPP=g++
CPPFLAGS += -g -Wall -Wextra -pthread
CPPFLAGS += -isystem $(GTEST_DIR)/include -std=c++11

GTEST_DIR = gtest
GTEST_HEADERS = $(GTEST_DIR)/include/gtest/*.h \
                $(GTEST_DIR)/include/gtest/internal/*.h
GTEST_SRCS_ = $(GTEST_DIR)/src/*.cc $(GTEST_DIR)/src/*.h $(GTEST_HEADERS)

MKDIR_P = mkdir -p
OBJ_DIR = obj

all: extracting-fields packing-bytes print-bits print-char print-float print-int print-it unpacking-bytes updating-fields all_tests

${OBJ_DIR}:
	${MKDIR_P} ${OBJ_DIR}

submission:
	zip -r bits_and_bytes_submit.zip src

obj/%.o: src/%.c ${OBJ_DIR}
	$(CPP) $(CPPFLAGS) $(CPPFLAGS) -c -o $@ $<

obj/all_tests.o: test/all_tests.c
	$(CPP) $(CPPFLAGS) $(CPPFLAGS) -c -o $@ $<

obj/gtest-all.o: $(GTEST_SRCS_)
	$(CPP) $(CPPFLAGS) -I$(GTEST_DIR) $(CPPFLAGS) -c $(GTEST_DIR)/src/gtest-all.cc -o $@

obj/gtest_main.o: $(GTEST_SRCS_)
	$(CPP) $(CPPFLAGS) -I$(GTEST_DIR) $(CPPFLAGS) -c $(GTEST_DIR)/src/gtest_main.cc -o $@

obj/gtest.a: obj/gtest-all.o
	$(AR) $(ARFLAGS) $@ $^

obj/gtest_main.a: obj/gtest-all.o obj/gtest_main.o
	$(AR) $(ARFLAGS) $@ $^

extracting-fields: obj/extracting-fields.o obj/bits_and_bytes.o
	$(CPP) -o $@ $^

packing-bytes: obj/packing-bytes.o obj/bits_and_bytes.o
	$(CPP) -o $@ $^

print-bits: obj/print-bits.o obj/bits_and_bytes.o
	$(CPP) -o $@ $^

print-char: obj/print-char.o obj/bits_and_bytes.o
	$(CPP) -o $@ $^

print-float: obj/print-float.o obj/bits_and_bytes.o
	$(CPP) -o $@ $^

print-int: obj/print-int.o obj/bits_and_bytes.o
	$(CPP) -o $@ $^

print-it: obj/print-it.o obj/bits_and_bytes.o
	$(CPP) -o $@ $^

unpacking-bytes: obj/unpacking-bytes.o obj/bits_and_bytes.o
	$(CPP) -o $@ $^

updating-fields: obj/updating-fields.o obj/bits_and_bytes.o
	$(CPP) -o $@ $^

all_tests : obj/bits_and_bytes.o obj/all_tests.o obj/gtest_main.a
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $^ -o $@

clean:
	rm -f *~ *.xml obj/*.o obj/*.a *.zip
	rm -rf obj
	rm -f extracting-fields packing-bytes print-bits print-char print-float print-int print-it unpacking-bytes updating-fields all_tests
