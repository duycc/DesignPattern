src = $(wildcard ./*.cpp)
inc = ./
target = test

ALL: $(target)

CC = g++ -std=c++20

$(target): $(src)
	$(CC) $^ -o $@

run:
	./$(target)

clean: 
	-rm -rf $(target)

.PHONY: clean ALL