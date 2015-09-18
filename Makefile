all: url_parser.c main.c
	clang -g --std=c89 url_parser.c main.c -o url_parse_test

