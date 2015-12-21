#define _XOPEN_SOURCE_EXTENDED

#include <ncurses.h>
#include <locale.h>
#include <iostream>
#include <map>
#include <string>
#include "game.h"

int main()
{
	setlocale(LC_ALL,"");
	initscr();
	raw();
	keypad(stdscr, TRUE);
	mousemask(ALL_MOUSE_EVENTS | REPORT_MOUSE_POSITION, NULL);
	noecho();
	curs_set(0);
	timeout(1);
	
	game test;

	message msg;

	test.buildentity(msg);

	while(int c = getch() != 'q')
	{
		test.buildentity(msg);
		//clear();
		erase();
		test.update();
		refresh();
	}
	endwin();
	return 0;
}
