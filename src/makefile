NOME_SAIDA=conversor_romanos_teste

IDIR =../include
CC=g++
EXT = c
CFLAGS=-Wall -g -fprofile-arcs -ftest-coverage -I $(IDIR)

GCOVDIR=gcov_files
ODIR=obj
LDIR =../lib

LIBS=-lm /usr/lib/libgtest.a -lgtest -lpthread

_DEPS = conversor_romanos.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = conversor_romanos_teste.o conversor_romanos.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: %.$(EXT) $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(NOME_SAIDA): $(OBJ)
	$(CC) -o $@ $^ $(LIBS) $(CFLAGS)

.PHONY: clean
clean:
	rm -f $(ODIR)/* *~ core $(INCDIR)/*~ 

.PHONY: reset
reset:
	make clean
	rm -f teste
	rm -f $(GCOVDIR)/*
	rm -f ../valores.txt

.PHONY: mv_gcov_files
mv_gcov_files:
	mv $(ODIR)/*.gcda $(GCOVDIR)
	mv $(ODIR)/*.gcno $(GCOVDIR)
	cp *.c $(GCOVDIR)