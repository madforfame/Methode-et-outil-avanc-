CC=gcc
OBJS= appli.o niveau/niveau.o tableau/tableau.o save_load_highscore/save_load_highscore.o
EXEC= appli

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(OBJS) -o $(EXEC)

clean :
	rm $(OBJS)
