CFLAGS=-g -std=c89 -Wall -pedantic -Wextra

all: url_parser.c main.c
	$(CC) $(CFLAGS) url_parser.c main.c -o url_parse_test

