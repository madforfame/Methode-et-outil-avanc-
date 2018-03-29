CC=gcc
CFLAGS=-Wall -pg -Iinclude -fprofile-arcs -ftest-coverage

EXEC=appli
SRC = $(SRCDIR)/appli.c $(SRCDIR)/niveau.c $(SRCDIR)/save_load_highscore.c $(SRCDIR)/tableau.c $(SRCDIR)/redo.c $(SRCDIR)/player.c $(SRCDIR)/check.c
SRCDIR = src
OBJS = $(SRC:.c=.o)

TEST=AllTests
TSRC= $(SRCDIR)/AllTests.c $(SRCDIR)/CuTest.c $(SRCDIR)/StrUtil.c
TOBJS= $(TSRC:.c=.o)

all: $(EXEC)

test: $(TEST)



$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(EXEC)

$(TEST) : $(TOBJS)
	$(CC) $(CFLAGS) $(TOBJS) -o $(TEST)

clean: 
	
	rm -f $(EXEC) $(SRCDIR)/*.o
	rm -f *.o
	rm -f $(EXEC) $(SRCDIR)/*.gcno
	rm -f $(EXEC) $(SRCDIR)/*.gdca

