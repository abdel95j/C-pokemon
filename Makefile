c-pokemon : src/game.c src/physic.c src/talkbis.c src/talk.c src/main.c src/print.c
	gcc -o c-pokemon src/game.c src/talkbis.c src/talk.c src/physic.c src/main.c src/print.c -lncurses
	./c-pokemon
