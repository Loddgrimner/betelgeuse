#include <stdlib.h>
#include <ncurses.h>
#include <math.h>
#include <vector>
#include "shotdraw.h"

shotdraw::shotdraw()
{
}
shotdraw::~shotdraw()
{
}
void shotdraw::update()
{
	std::vector<const char*> a {
		"|",
		"\\",
		"-",
		"/",
		"|",
		"\\",
		"-",
		"/",
		"|"
	};
	std::vector<const char*> b {
		"↑",
		"↖",
		"←",
		"↙",
		"↓",
		"↘",
		"→",
		"↗",
		"↑"
	};
	int direction = round(4+1.2732*atan2(delta.gety(),delta.getx()));
	
	attron(COLOR_PAIR(2));
	mvprintw(position.getx(),position.gety(),b[direction]);
}
void shotdraw::receivemessage(message msg)
{
	if(msg.get("changeposition"))
	{
		position.setx(msg.get("x"));
		position.sety(msg.get("y"));
	}
	if(msg.get("changedelta"))
	{
		delta.setx(msg.get("deltax"));
		delta.sety(msg.get("deltay"));
	}
}

