# Template for static library build
CC = gcc
CFLAGS = -g -Wall
SRCDIR=./src
OBJDIR=./obj
SRCS=$(wildcard $(SRCDIR)/*.c)
OBJS=$(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRCS))

# build unit test using criterion framework
# https://github.com/Snaipe/Criterion
TESTDIR = ./tests
TESTS = $(wildcard $(TESTDIR)/*.c)
TESTBINS=$(patsubst $(TESTDIR)/%.c, $(TESTDIR)/bin/%, $(TESTS))
TFLAGS = --verbose

LIBDIR = ./lib
LIB = $(LIBDIR)/myqueue.a

all: $(OBJDIR) $(LIBDIR) $(LIB)

release: CFLAGS=-Wall -O2 -DNDEBUG 
release: clean
release: $(LIB)

$(LIB): $(LIBDIR) $(OBJDIR) $(OBJS)
	$(RM) $(LIB)
	ar -cvrs $(LIB) $(OBJS)

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(SRCDIR)/%.h
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(TESTDIR)/bin/%: $(TESTDIR)/%.c
	$(CC) $(CFLAGS) $< $(OBJS) -o $@ -lcriterion

$(TESTDIR)/bin:
	mkdir $@

$(OBJDIR):
	mkdir $@

$(LIBDIR):
	mkdir $@

test: $(LIB) $(TESTDIR)/bin $(TESTBINS)
	for test in $(TESTBINS) ; do ./$$test $(TFLAGS); done

clean:
	$(RM) -r $(LIBDIR)/* $(OBJDIR)/* $(TESTDIR)/bin/*
