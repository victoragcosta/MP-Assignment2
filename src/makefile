IDIR =../include
CC=g++
EXT = c
CFLAGS= -I $(IDIR) -Wall

ODIR=obj
LDIR =../lib

GTESTLIBS = /usr/lib/libgtest.a -lgtest -lpthread
LIBS=$(GTESTLIBS) -lm

_DEPS = romanos.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = teste.o romanos.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: %.$(EXT) $(DEPS)
	$(CC) -g -c -o $@ $< $(CFLAGS)

teste.exe: $(OBJ)
	$(CC) -g -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 