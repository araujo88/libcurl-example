CC=gcc
CFLAGS=-g -Wall

BIN=downloadex

all: $(BIN)

%: %.c
	$(CC) $(CFLAGS) $< -o $@ -lcurl

clean:
	$(RM) -rf #(BIN) *.dSYM