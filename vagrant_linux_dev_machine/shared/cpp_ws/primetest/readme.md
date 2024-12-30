% clang -c -std=c17 -Wall -Wextra -pedantic -Werror isprime.c -o bin/isprime.o
% clang -c -std=c17 -Wall -Wextra -pedantic -Werror driver.c -o bin/driver.o
% ar rcs bin/libPrimalityUtilities.a bin/isprime.o
% clang bin/driver.o -Lbin -lPrimalityUtilities -o bin/primetest

tar -xf primetest.tar.gz -C /path/to/your/target/folder
