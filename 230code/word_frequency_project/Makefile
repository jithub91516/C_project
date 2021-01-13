CPP=g++
CPPFLAGS += -g -Wall -Wextra -pthread
CPPFLAGS += -isystem $(GTEST_DIR)/include -std=c++11

GTEST_DIR = gtest
GTEST_HEADERS = $(GTEST_DIR)/include/gtest/*.h \
                $(GTEST_DIR)/include/gtest/internal/*.h
GTEST_SRCS_ = $(GTEST_DIR)/src/*.cc $(GTEST_DIR)/src/*.h $(GTEST_HEADERS)

MKDIR_P = mkdir -p
OBJ_DIR = obj

INPUTS = $(wildcard books/*.txt)
OUTPUTS = $(patsubst books/%,output/%.out,$(INPUTS))

all: all_tests wordfreq wordfreq-fast
 # $(OUTPUTS)

${OBJ_DIR}:
	${MKDIR_P} ${OBJ_DIR}

submission:
	zip -r word_frequency_submit.zip src

output/%.txt.out: books/%.txt wordfreq-fast
	${MKDIR_P} output
	cat $< | ./wordfreq-fast > $@

wordfreq: obj/wset.o obj/words.o obj/wordfreq.o
	$(CPP) $(CPPFLAGS) $(CXXFLAGS) $^ -o $@

wordfreq-fast: obj/wset.o obj/words.o obj/wordfreq-fast.o
	$(CPP) $(CPPFLAGS) $(CXXFLAGS) $^ -o $@

obj/%.o: src/%.c ${OBJ_DIR}
	$(CPP) $(CPPFLAGS) $(CXXFLAGS) -c -o $@ $<

obj/all_tests.o: test/all_tests.c
	$(CPP) $(CPPFLAGS) $(CXXFLAGS) -c -o $@ $<

obj/gtest-all.o: $(GTEST_SRCS_)
	$(CPP) $(CPPFLAGS) -I$(GTEST_DIR) $(CPPFLAGS) -c $(GTEST_DIR)/src/gtest-all.cc -o $@

obj/gtest_main.o: $(GTEST_SRCS_)
	$(CPP) $(CPPFLAGS) -I$(GTEST_DIR) $(CPPFLAGS) -c $(GTEST_DIR)/src/gtest_main.cc -o $@

obj/gtest.a: obj/gtest-all.o
	$(AR) $(ARFLAGS) $@ $^

obj/gtest_main.a: obj/gtest-all.o obj/gtest_main.o
	$(AR) $(ARFLAGS) $@ $^

all_tests : obj/words.o obj/wset.o obj/all_tests.o obj/gtest_main.a
	$(CPP) $(CPPFLAGS) $(CXXFLAGS) $^ -o $@

clean:
	rm -f *~ *.xml obj/*.o obj/*.a *.zip
	rm -rf obj output
	rm -f all_tests wordfreq wordfreq-fast
#	$(MAKE) -C test clean
