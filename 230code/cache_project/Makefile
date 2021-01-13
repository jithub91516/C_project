CPP=g++
CPPFLAGS += -g -Wall -Wextra -pthread
CPPFLAGS += -isystem $(GTEST_DIR)/include -std=c++11

GTEST_DIR = gtest
GTEST_HEADERS = $(GTEST_DIR)/include/gtest/*.h \
                $(GTEST_DIR)/include/gtest/internal/*.h
GTEST_SRCS_ = $(GTEST_DIR)/src/*.cc $(GTEST_DIR)/src/*.h $(GTEST_HEADERS)

MKDIR_P = mkdir -p
OBJ_DIR = obj
OBJS = ${OBJ_DIR}/cache.o ${OBJ_DIR}/lru.o ${OBJ_DIR}/bits.o ${OBJ_DIR}/cpu.o 

all: all_tests cache_sim

${OBJ_DIR}:
	${MKDIR_P} ${OBJ_DIR}

submission:
	zip -r cache_submit.zip team.txt src > /dev/null

cache_sim: obj/cache_sim.o ${OBJS}
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

all_tests: ${OBJS} obj/all_tests.o obj/gtest_main.a
	$(CPP) $(CPPFLAGS) $(CXXFLAGS) $^ -o $@

# TODO: check if the traces are generated correctly
traces: tests/ls.trace tests/wc.trace tests/cat.trace

tests/ls.trace:
	valgrind -q --log-file=tests/ls.trace --tool=lackey --trace-mem=yes ls -l

tests/wc.trace:
	valgrind -q --log-file=tests/wc.trace --tool=lackey --trace-mem=yes wc -l src/cache-sim.c

tests/cat.trace:
	valgrind -q --log-file=tests/cat.trace --tool=lackey --trace-mem=yes cat src/cache-sim.c

clean:
	rm -f *~ *.xml obj/*.o obj/*.a *.zip
	rm -rf obj output
	rm -f all_tests cache_sim

