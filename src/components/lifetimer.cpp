#include "lifetimer.h"
lifetimer::lifetimer()
{
}
lifetimer::~lifetimer()
{
}
void lifetimer::update()
{
	time++;
	if(time >= killtime)
	{
		component::killhost();
	}
}
void lifetimer::receivemessage(message msg)
{
}
