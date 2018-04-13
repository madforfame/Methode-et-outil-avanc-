CC=gcc
CFLAGS=-Wall -pg -Iinclude -fprofile-arcs -ftest-coverage
COVFLAGS= -fprofile-arcs -ftest-coverage

EXEC=appli
SRC = $(SRCDIR)/appli.c $(SRCDIR)/niveau.c $(SRCDIR)/save_load_highscore.c $(SRCDIR)/tableau.c $(SRCDIR)/redo.c $(SRCDIR)/player.c $(SRCDIR)/check.c
SRCDIR = src
OBJS = $(SRC:.c=.o)

TEST=AllTests
TSRC= $(SRCDIR)/AllTests.c $(SRCDIR)/CuTest.c $(SRCDIR)/checkUtil.c
TOBJS= $(TSRC:.c=.o)
AOBJC =$(SRC:.c=.o)

AFL=appli2


CLANG=clang

LLVM_LINK=llvm-link
PROF=/home/m/monniaud

KLEE = ${PROF}/packages/klee/2017-09-26_c7a1f9d/
KLEE_EXEC=/bin/klee
CFLAGS_KLEE=-Wall -Iinclude -g -I$(KLEE)/include
BCFILES=obj/appli.bc obj/niveau.bc obj/save_load_highscore.bc obj/tableau.bc obj/check.bc obj/player.bc obj/redo.bc 



all: $(EXEC)

test: $(TEST)

afl: $(AFL)


$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) -fprofile-arcs -ftest-coverage $(COVFLAGS) $(OBJS) -o $(EXEC)


$(TEST): $(TOBJS)
	$(CC) $(CFLAGS) $(TOBJS) -o $(TEST)
	./AllTests

$(AFL): $(AOBJC) 
	afl-gcc $(AOBJC) -Wall -pg -Iinclude -o $(AFL)
	AFL_I_DONT_CARE_ABOUT_MISSING_CRASHES=ON AFL_SKIP_CPUFREQ=1 afl-fuzz -m2G -n -i afl_in/ -o afl_out/ ./appli2 config1.xml

gprof:
	make 
	gprof appli gmon.out >res_gprof.txt
	cat res_gprof.txt

cov:
	lcov-1.13/bin/lcov --base-directory ./src/ --directory ./src/ -c -o rap.info
	lcov-1.13/bin/genhtml rap.info --output-directory out


missrate:
	make
	valgrind --tool=cachegrind --branch-sim=yes ./appli config1.xml


klee: appli.bc
	klee appli.bc config1.xml

$(BCFILES): include/util.h include/niveau.h include/tableau.h include/save_load_highscore.h include/check.h include/player.h include/redo.h

appli.bc: $(BCFILES)
	$(LLVM_LINK) $+ -o $@

obj/%.bc: src/%.c
	$(CLANG) $(CFLAGS_KLEE) -DKLEE -c -emit-llvm $< -o $@

clean:
	rm -f $(EXEC) $(SRCDIR)/*.o
	rm -f *.o
	rm -f $(EXEC) $(SRCDIR)/*.gcno
	rm -f $(EXEC) $(SRCDIR)/*.gcda
	-rm -f appli.bc $(BCFILES)
