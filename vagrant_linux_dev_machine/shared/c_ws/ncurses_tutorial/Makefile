# Template for binary build
CC = gcc
CFLAGS = -g -Wall
PROJ = hello
SRCDIR=./src
OBJDIR=./obj
SRCS=$(wildcard $(SRCDIR)/*.cpp)
OBJS=$(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, $(SRCS))

BINDIR = ./bin
BIN = $(BINDIR)/$(PROJ)

all: $(OBJDIR) $(BINDIR) $(BIN)

release: CFLAGS=-Wall -O2 -DNDEBUG 
release: clean
release: $(BIN)

$(BIN): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@ -lncurses

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp $(SRCDIR)/%.h
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR):
	mkdir $@

$(BINDIR):
	mkdir $@
	
clean:
	$(RM) -r $(BINDIR)/* $(OBJDIR)/*
