CC = gcc
CFLAGS = -c -std=gnu11 -Wall -Wextra
LDFLAGS = -Lbin
LIBS =
SOURCES = driver.c Makefile readme.md

# Create the 'bin' subfolder if not present
.PHONY: all
all: bin driver

# Create the 'bin' subfolder
bin:
	mkdir -p bin

# Compile driver.c (release build)
bin/driver.o: driver.c
	$(CC) $(CFLAGS) $< -o $@

# Link the driver with the library (release build)
driver: bin/driver.o 
	$(CC) $^ $(LDFLAGS) $(LIBS) -o bin/$@

clean:
	rm -f bin/*.o