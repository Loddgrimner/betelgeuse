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
	start_color();
	init_pair(1, COLOR_WHITE, COLOR_BLACK);
	init_pair(2, COLOR_YELLOW, COLOR_BLACK);
	attron(COLOR_PAIR(1));
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
			int team = rand()%2;
			message msg;
			msg.set("armament",1);
			msg.set("transponder",1);
			msg.set("randommover",1);
			msg.set("lifetimer",1);
			msg.set("pointdraw",1);
			//msg.set("trail",1);
			//msg.set("spawner",1);
			msg.set("changeposition",1);
			msg.set("x",20+rand()%20);
			msg.set("y",40+40*team);
			msg.set("changeteam",1);
			msg.set("team",team);
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
