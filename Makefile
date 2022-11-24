CC = gcc
CFLAGS = -std=c11 -Wall -g

src_dir = src
build_dir = build
headers = $(wildcard $(src_dir)/*.h)
sources = $(wildcard $(src_dir)/*.c)
objects = $(patsubst $(src_dir)/%.c, $(build_dir)/%.o, $(sources))

$(build_dir)/%.o: $(src_dir)/%.c $(headers)
	$(CC) -c $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

$(build_dir)/myscript: $(objects)
	$(CC) $(LDFLAGS) -o $@ $^ $(LOADLIBES) $(LDLIBS)

all: $(build_dir)/myscript

clean:
	rm -rf $(build_dir)/*

.PHONY: all clean
