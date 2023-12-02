CC	?= gcc
RM	= rm -f

CFLAGS	= -Wall -Werror -Wextra -ansi
LDFLAGS	= 

all: solve.step1 solve.step2

solve.step1: solve.step1.o
	$(CC) -o $@ $^ $(LDFLAGS)

solve.step2: solve.step2.o
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	$(RM) $(OBJS) solve.step1 solve.step2

.PHONY: clean all
