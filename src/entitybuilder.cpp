#include "entitybuilder.h"
#include "dumbmover.h"
#include "lifetimer.h"
#include "pointdraw.h"
#include "spawner.h"

entitybuilder::entitybuilder()
{
}
entitybuilder::~entitybuilder()
{
}

std::shared_ptr<entity> entitybuilder::build(message msg)
{
	std::shared_ptr<entity> e = std::make_shared<entity>();
	if(msg.get("dumbmover"))
	{
		e->insertcomponent(std::make_shared<dumbmover>());
	}
	if(msg.get("lifetimer"))
	{
		e->insertcomponent(std::make_shared<lifetimer>());
	}
	if(msg.get("pointdraw"))
	{
		e->insertcomponent(std::make_shared<pointdraw>());
	}
	if(msg.get("spawner"))
	{
		e->insertcomponent(std::make_shared<spawner>());
	}
	e->pumpmessage(msg);
	return e; 
}
