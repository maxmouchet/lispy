repl: src/repl.c src/parser.c src/parser.h src/lval.h src/lval.c
	$(CC) -g -std=c99 -Wall -Iinclude/ src/repl.c src/parser.c src/lval.c include/mpc.c -ledit -lm -o $@