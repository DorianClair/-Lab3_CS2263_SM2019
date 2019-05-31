COMPILER = gcc

C_FLAGS = -Wall -Wextra

help:
	@printf "available command:\n"
	@printf "	make help               (this command)\n"
	@printf "	make Stack              (to build your C program)\n"
	@printf "	make test               (to run every test case)\n"
	@printf "	make test1              (to run test1)\n"
	@printf "	make test2              (to run test2)\n"
	@printf "	make test3              (to run test3)\n"
# TODO: add targets to compile LinkedList.c
Stack: Stack.o
	$(COMPILER) $(C_FLAGS) -o Stack Stack.o

Stack.o: Stack.c
	$(COMPILER) $(C_FLAGS) -c Stack.c

# The C flags to pass to gcc
C_FLAGS = -Wall -Wextra

test1: Stack
	./Stack < Data/test1.input > test1.result

test2: Stack
	./Stack < Data/test2.input > test2.result

test3: Stack
	./Stack < Data/test3.input > test3.result

# TODO: add a target that can run all the tests above.

test: test1 test2 test3
