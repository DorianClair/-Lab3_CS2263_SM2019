
# compile with gcc, change this to clang if you prefer
COMPILER = gcc

# The C flags to pass to gcc
C_FLAGS = -Wall -Wextra

# link our .o files to make an executable
Stack: Stack.o
	$(COMPILER) $(C_FLAGS) -o Stack Stack.o

# compile the `Stack.o` file
Stack.o: Stack.c
	$(COMPILER) $(C_FLAGS) -c Stack.c

test1: Stack
	./Stack < Data/test1.input > test1.result
test2: Stack
	./Stack < Data/test2.input > test2.result
test3: Stack
	./Stack < Data/test3.input > test3.result

test: test1 test2 test3
