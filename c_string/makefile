LIB_TARGET=libstring.a
TEST_TARGET=test
DEST=../compiled_libs
STATIC=ar rcs
LIBFLAGS=-L$(LDIR)
CFLAGS=-Wall
LDFLAGS=-I$(IDIR) -I../c_error/include -I../c_test/include -I../

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

_DEPS=c_string.h
DEPS=$(patsubst %,$(IDIR)/%,$(_DEPS))

_SRC=c_string.c
SRC=$(patsubst %,$(SDIR)/%,$(_SRC))

_OBJ=c_string.o
OBJ=$(patsubst %,$(BDIR)/%,$(_OBJ))

_LIB=error test
LIB=$(patsubst %,-l%,$(_LIB))

MOBJ=$(OBJ) $(BDIR)/main.o
MSRC=$(SRC) $(BDIR)/main.c

TDEPS=$(DEPS) $(IDIR)/c_string_tests.h
TOBJ=$(OBJ) $(BDIR)/test_main.o $(BDIR)/c_string_tests.o
TSRC=$(SRC) $(SDIR)/test_main.c $(BDIR)/c_string_tests.c

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
	cp $(DEST)/libtest.a $(LDIR)

$(BDIR)/%.o: $(SDIR)/%.c
	$(CC) $(CFLAGS) $(LDFLAGS) $(LIBFLAGS) -MMD -c $< -o $@ $(LIB)

.PHONY: clean

clean:
	rm -rf $(BDIR)/*
