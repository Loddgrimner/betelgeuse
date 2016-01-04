#include "entitybuilder.h"
#include "dumbmover.h"
#include "lifetimer.h"
#include "pointdraw.h"
#include "smoke.h"
#include "spawner.h"
#include "trail.h"

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
	if(msg.get("spawner"))
	{
		e->insertcomponent(std::make_shared<spawner>());
	}
	if(msg.get("trail"))
	{
		e->insertcomponent(std::make_shared<trail>());
	}
	if(msg.get("pointdraw"))
	{
		e->insertcomponent(std::make_shared<pointdraw>());
	}
	if(msg.get("smoke"))
	{
		e->insertcomponent(std::make_shared<smoke>());
	}
	e->pumpmessage(msg);
	return e; 
}
