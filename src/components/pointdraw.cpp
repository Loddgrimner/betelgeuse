#include <stdlib.h>
#include <ncurses.h>
#include "pointdraw.h"

pointdraw::pointdraw()
{
}
pointdraw::~pointdraw()
{
}
void pointdraw::update()
{
	attron(COLOR_PAIR(1));
	mvprintw(x,y,"F");
}
void pointdraw::receivemessage(message msg)
{
	if(msg.get("changeposition"))
	{
		x = msg.get("x");
		y = msg.get("y");
	}
}

