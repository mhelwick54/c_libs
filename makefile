LIB_TARGET=
TEST_TARGET=
DEST=../compiled_libs
STATIC=ar rcs
LIBFLAGS=-L$(LDIR)
CFLAGS=-Wall
LDFLAGS=-I$(IDIR) -I../

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

_DEPS=
DEPS=$(patsubst %,$(IDIR)/%,$(_DEPS))

_SRC=
SRC=$(patsubst %,$(SDIR)/%,$(_SRC))

_OBJ=
OBJ=$(patsubst %,$(BDIR)/%,$(_OBJ))

_LIB=
LIB=$(patsubst %,-l%,$(_LIB))

MOBJ=$(OBJ)
MSRC=$(SRC)

TDEPS=$(DEPS)
TOBJ=$(OBJ)
TSRC=$(SRC)

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


$(BDIR)/%.o: $(SDIR)/%.c
	$(CC) $(CFLAGS) $(LDFLAGS) $(LIBFLAGS) -MMD -c $< -o $@ $(LIB)

.PHONY: clean

clean:
	rm -rf $(BDIR)/*
