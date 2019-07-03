LIB_TARGET=libtest.a
TEST_TARGET=test
DEST=../compiled_libs
STATIC=ar rcs
LIBFLAGS=-L$(LDIR)
CFLAGS=-Wall
LDFLAGS=-I$(IDIR) -I../c_error/include -I../

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S), Darwin)
	ifeq ($(shell which gcc-8), /usr/local/bin/gcc-8)
		CC=gcc-8#MacOS GNU gcc, not clang
	else
		CC=clang
	endif
else
	CC=gcc#GNU gcc
endif

IDIR=include
SDIR=src
BDIR=bin
LDIR=lib

_DEPS=assert.h test.h
DEPS=$(patsubst %,$(IDIR)/%,$(_DEPS))

_SRC=assert.c test.c
SRC=$(patsubst %,$(SDIR)/%,$(_SRC))

_OBJ=assert.o test.o
OBJ=$(patsubst %,$(BDIR)/%,$(_OBJ))

_LIB=error
LIB=$(patsubst %,-l%,$(_LIB))

MOBJ=$(OBJ) $(BDIR)/main.o
MSRC=$(SRC) $(SDIR)/main.c

TDEPS=$(DEPS) $(IDIR)/internal_tests.h
TOBJ=$(OBJ) $(BDIR)/internal_tests.o $(BDIR)/test_main.o
TSRC=$(SRC) $(SDIR)/internal_tests.c $(SDIR)/test_main.c

all: $(LIB) $(BDIR)/$(LIB_TARGET)
	cp $(BDIR)/$(LIB_TARGET) $(DEST)

test: $(LIB) $(BDIR)/$(TEST_TARGET)

info:
	$(info DEPS is $(DEPS))
	$(info SRC is $(SRC))
	$(info OBJ is $(OBJ))
	$(info LIB is $(LIB))
	$(info MOBJ is $(MOBJ))
	$(info TOBJ is $(TOBJ))

$(BDIR)/$(LIB_TARGET): $(MOBJ)
	$(STATIC) $@ $^

$(BDIR)/$(TEST_TARGET): $(TOBJ)
	$(CC) $(CFLAGS) $(LDFLAGS) $(LIBFLAGS) $^ -o $@ $(LIB)

$(LIB):
	cp $(DEST)/liberror.a $(LDIR)

$(BDIR)/%.o: $(SDIR)/%.c
	$(CC) $(CFLAGS) $(LDFLAGS) $(LIBFLAGS) -MMD -c $< -o $@ $(LIB)

.PHONY: clean

clean:
	rm -rf $(BDIR)/*
