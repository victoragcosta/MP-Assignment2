IDIR =../include
CC=g++
EXT = c
CFLAGS=-Wall -g --coverage -I $(IDIR)


ODIR=obj
LDIR =../lib

LIBS=-lm /usr/lib/libgtest.a -lgtest -lpthread

_DEPS = romanos.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = teste.o romanos.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: %.$(EXT) $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

teste: $(OBJ)
	$(CC) -o $@ $^ $(LIBS) $(CFLAGS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 

.PHONY: reset

reset:
	make clean
	rm -f teste