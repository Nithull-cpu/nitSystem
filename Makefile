CC     = gcc
CFLAGS = -Wall -Wextra

# Every program that has its own main()
PROGS = create find 

all: $(PROGS)

# Generic rule: build x from x.c
%: %.c
	$(CC) $(CFLAGS) -o $@ $<

# Programs that need other files: list them explicitly
# (this overrides the generic rule for that program)
find: find.c utils.c
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(PROGS)
