#include "entitybuilder.h"
#include "dumbmover.h"
#include "lifetimer.h"

entitybuilder::entitybuilder()
{
}
entitybuilder::~entitybuilder()
{
}

std::shared_ptr<entity> entitybuilder::build(message msg)
{
	std::shared_ptr<entity> e = std::make_shared<entity>();
	e->insertcomponent(std::make_shared<dumbmover>());
	e->insertcomponent(std::make_shared<lifetimer>());
	return e; 
}
