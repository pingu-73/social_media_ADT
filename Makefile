CC := gcc
exe := run
obj := main.o comment.o platform.o post.o
SRC := src
CFLAGS := -Wall -Wextra -Werror -fsanitize=leak

all: $(exe)

$(exe): $(obj)
	$(CC) $(CFLAGS) -o $@ $^

%.o: $(SRC)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -f $(obj) $(exe)
