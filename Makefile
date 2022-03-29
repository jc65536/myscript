HEADERS = $(wildcard src/*.h)
SOURCES = $(wildcard src/*.c)
OBJECTS = $(patsubst src/%.c, build/%.o, $(SOURCES))
OPTIONS = -std=c11 -Wall -g

build/%.o: src/%.c $(HEADERS)
	gcc $(OPTIONS) -o $@ -c $<

build/myscript: $(OBJECTS)
	gcc $(OPTIONS) -o $@ $^

all: build/myscript

.PHONY: all
