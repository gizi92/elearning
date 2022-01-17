# Template for binary build
CC = gcc
CFLAGS = -g -Wall
LIBFLAGS = -lxml2
# LDFLAGS = -L/usr/lib/gcc/x86_64-linux-gnu
SRCDIR=./src
OBJDIR=./obj
SRCS=$(wildcard $(SRCDIR)/*.c)
OBJS=$(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRCS))

BINDIR = ./bin
BIN = $(BINDIR)/02_02-xmlversion1

all: $(BINDIR) $(OBJDIR) $(BIN)

release: CFLAGS=-Wall -O2 -DNDEBUG 
release: clean
release: $(BIN)

$(BIN): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@ $(LIBFLAGS)

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(SRCDIR)/%.h
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@ $(LIBFLAGS)

$(OBJDIR):
	mkdir $@

$(BINDIR):
	mkdir $@

clean:
	$(RM) -r $(BINDIR)/* $(OBJDIR)/*