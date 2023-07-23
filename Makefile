CFLAGs=-Wall -Wextra -ggdb

all: matrix matrix.i matrix.s

matrix.o: main.cpp
		g++ $(CFLAGS) -Wa,-a=matrix.lst -c main.cpp

matrix: main.o
		g++ $(CFLAGS) -Bstatic -Wl,-Map=matrix.map -o matrix main.o

matrix.i: main.cpp
		g++ -E main.cpp >matrix.i

matrix.s: main.cpp
		g++ -S main.cpp

# adding verbose for seeing all command line
verbose:
		g++ -v $(CFLAGS) -Wextra -c main.cpp

# cleaning after compilation
clean:
		rm -f matrix matrix.i main.s main.o matrix.map matrix.lst