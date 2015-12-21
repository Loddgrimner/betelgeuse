#include <stdlib.h>
#include <ncurses.h>
#include "dumbmover.h"

dumbmover::dumbmover()
{
	dx = rand()%3-1;
	dy = rand()%3-1;
}
dumbmover::~dumbmover()
{
}
void dumbmover::update()
{
	x+=dx;
	y+=dy;
	mvprintw(x,y,"@");
}
void dumbmover::receivemessage(message msg)
{
}
