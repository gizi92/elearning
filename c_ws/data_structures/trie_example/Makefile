# Template for binary build
CC = gcc
CFLAGS = -g -Wall
SRCDIR=./src
OBJDIR=./obj
SRCS=$(wildcard $(SRCDIR)/*.c)
OBJS=$(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRCS))

BINDIR = ./bin
BIN = $(BINDIR)/trie_example

all: $(BINDIR) $(OBJDIR) $(BIN)

release: CFLAGS=-Wall -O2 -DNDEBUG 
release: clean
release: $(BIN)

$(BIN): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(SRCDIR)/%.h
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR):
	mkdir $@

$(BINDIR):
	mkdir $@

clean:
	$(RM) -r $(BINDIR)/* $(OBJDIR)/*