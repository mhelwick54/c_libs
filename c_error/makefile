TARGET=liberror.a
DEST=../compiled_libs
STATIC=ar rcs
CFLAGS=-Wall
LDFLAGS=-I$(IDIR)

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

_DEPS=error.h error_defs.h
DEPS=$(patsubst %,$(IDIR)/%,$(_DEPS))

_SRC=error.c
SRC=$(patsubst %,$(SDIR)/%,$(_SRC))

_OBJ=error.o
OBJ=$(patsubst %,$(BDIR)/%,$(_OBJ))

all: $(BDIR)/$(TARGET)
	cp $(BDIR)/$(TARGET) $(DEST)

$(BDIR)/$(TARGET): $(OBJ)
	$(STATIC) $@ $^

$(BDIR)/%.o: $(SDIR)/%.c
	$(CC) $(CFLAGS) $(LDFLAGS) -MMD -c $< -o $@

.PHONY: clean

clean:
	rm -rf $(BDIR)/*
