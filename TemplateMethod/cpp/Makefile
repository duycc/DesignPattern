src = $(wildcard ./*.cpp)
inc = ./
target = test

ALL: $(target)

CC = g++

$(target): $(src)
	$(CC) $^ -o $@

clean: 
	-rm -rf $(target)

.PHONY: clean ALL