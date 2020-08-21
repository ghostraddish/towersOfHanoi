EXECUTABLES:= testGetProduct testLinearSearch testTowers
OBJS:= prog7.o towers.o
CC:= gcc
CFLAGS:= -Wall -Werror -g

all: $(EXECUTABLES)

testGetProduct: testGetProduct.c prog7.o
	$(CC) $(CFLAGS) $^ -o $@

testLinearSearch: testLinearSearch.c prog7.o
	$(CC) $(CFLAGS) $^ -o $@

testTowers: testTowers.c towers.o
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c %.h
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -f $(EXECUTABLES) $(OBJS)	
