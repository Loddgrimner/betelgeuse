#include <string.h>
#include <vector>
#include <stdlib.h>
#include <ncurses.h>
#include "smoke.h"

smoke::smoke()
{
}
smoke::~smoke()
{
}
void smoke::update()
{
	std::vector<const char*> a {
		"⚬",
		"⚪",
		"o",
		"◯",
		"O"
	};
	mvprintw(x,y,a[time%5]);
	time++;
}
void smoke::receivemessage(message msg)
{
	if(msg.get("changeposition"))
	{
		x = msg.get("x");
		y = msg.get("y");
	}
}

