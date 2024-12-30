CC = gcc
CFLAGS = -c -std=c17 -Wall -Wextra -pedantic -Werror
LDFLAGS = -Lbin
LIBS = -lPrimalityUtilities
SOURCES = driver.c isprime.c isprime.h Makefile readme.md

# Create the 'bin' subfolder if not present
.PHONY: all debug
all: bin primetest

# Create the 'bin' subfolder
bin:
	mkdir -p bin

# Compile isprime.c (release build)
bin/isprime.o: isprime.c
	$(CC) $(CFLAGS) $< -o $@

# Compile driver.c (release build)
bin/driver.o: driver.c
	$(CC) $(CFLAGS) $< -o $@

# Create the library
bin/libPrimalityUtilities.a: bin/isprime.o
	ar rcs $@ $<

# Link the driver with the library (release build)
primetest: bin/driver.o bin/libPrimalityUtilities.a
	$(CC) $^ $(LDFLAGS) $(LIBS) -o bin/$@

# Compile isprime.c (debug build)
bin/isprime_debug.o: isprime.c
	$(CC) $(CFLAGS) -g $< -o $@

# Compile driver.c (debug build)
bin/driver_debug.o: driver.c
	$(CC) $(CFLAGS) -g $< -o $@

# Link the driver with the library (debug build)
primetest_debug: bin/driver_debug.o bin/libPrimalityUtilities.a
	$(CC) $^ $(LDFLAGS) $(LIBS) -o bin/$@

archive:
	tar -czvf primetest.tar.gz $(SOURCES)

clean:
	rm -f bin/*.o bin/libPrimalityUtilities.a bin/primetest bin/primetest_debug primetest.tar.gz
