CC=gcc
CFLAGS=-Wall -Iinclude 
EXEC=appli
SRC = $(SRCDIR)/appli.c $(SRCDIR)/niveau.c $(SRCDIR)/save_load_highscore.c $(SRCDIR)/tableau.c
SRCDIR = src
OBJS = $(SRC:.c=.o)

all: $(EXEC)

$(EXEC): $(OBJS)
	
	$(CC) $(OBJS) -o $(EXEC)

clean: 
	echo "$(OBJS)"
	rm -f $(EXEC) $(SRCDIR)/*.o