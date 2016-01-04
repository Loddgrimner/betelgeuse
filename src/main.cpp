#define _XOPEN_SOURCE_EXTENDED

#include <stdlib.h>
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
	timeout(10);
	
	game test;

	while(int c = getch() != 'q')
	{
		if(rand()%100 == 0)
		{
			message msg;
			msg.set("dumbmover",1);
			msg.set("lifetimer",1);
			msg.set("pointdraw",1);
			msg.set("trail",1);
			msg.set("spawner",1);
			msg.set("changeposition",1);
			msg.set("x",20);
			msg.set("y",20);
			test.buildentity(msg);
		}
		//clear();
		erase();
		test.update();
		refresh();
	}
	endwin();
	return 0;
}
