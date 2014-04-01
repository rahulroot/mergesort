# Makefile to build driver program
# --- macros
CC=g++
CFLAGS=  -Wall -g
TEST_OBJ= merge_sort.o
#
#
# # --- targets

all:	msort 
msort:   $(TEST_OBJ) 
	$(CC)  -o msort  $(TEST_OBJ) 

merge_sort.o: merge_sort.cpp
	$(CC) $(CFLAGS) -c merge_sort.cpp

# --- remove binary and executable files
clean:
	rm -f msort $(TEST_OBJ) 
