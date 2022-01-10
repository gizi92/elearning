# Template for binary build
CC = gcc
CFLAGS = -g -Wall
LIBS = -lxml2
SRCDIR=./src
OBJDIR=./obj
SRCS=$(wildcard $(SRCDIR)/*.c)
OBJS=$(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRCS))

BINDIR = ./bin
BIN = $(BINDIR)/00_03-xmltest1
SUBMITNAME = myproject.zip

all: $(BINDIR) $(OBJDIR) $(BIN) $(LIBS)

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

submit:
	$(RM) $(SUBMITNAME)
	zip $(SUBMITNAME) $(BIN)