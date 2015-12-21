#include "component.h"
#include "entity.h"

component::component()
{
}

component::~component()
{
}

void component::sethost(entity* host)
{
	mhost = host;
}

void component::update()
{
}

void component::receivemessage(message msg)
{
}

void component::sendmessage(message msg)
{
	mhost->pumpmessage(msg);
}

void component::killhost()
{
	mhost->die();
}
