# Simplest possible Makefile
soccer_stats: main.c player.c player.h
	gcc -Wall main.c player.c -o soccer_stats

clean:
	rm -f soccer_stats