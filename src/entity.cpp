#include "entity.h"
#include "ncurses.h"
#include "component.h"
#include "game.h"

entity::entity()
{
}

entity::~entity()
{
}

void entity::pumpmessage(message msg)
{
	for (auto& i : components) {
		i->receivemessage(msg);
	}
}

void entity::buildentity(message msg)
{
	mgame->buildentity(msg);	
}

void entity::update()
{
	for (auto& i : components) {
		i->update();
	}
}

bool entity::isdead() const
{
	return dead;
}

void entity::die()
{
	dead = true;
}

void entity::insertcomponent(std::shared_ptr<component> c)
{
	c->sethost(this);
	components.push_back(c);
}

void entity::setgame(game* pgame)
{
	mgame = pgame;
}
