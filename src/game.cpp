#include <algorithm>
#include "game.h"
#include "entity.h"
#include "entitybuilder.h"

game::game()
{
	mentitybuilder = new entitybuilder;
}
game::~game()
{
	delete mentitybuilder;
}

void game::update()
{
	for (auto& i : entities) {
		i->update();
	}
	entities.erase(std::remove_if(entities.begin(), entities.end(), [](const std::shared_ptr<const entity> p) { return p->isdead(); }), entities.end());
	entities.insert(std::end(entities), std::begin(builtentities), std::end(builtentities));
	builtentities.clear();
}

void game::buildentity(message msg)
{
	builtentities.push_back(mentitybuilder->build(msg));
	builtentities.back()->setgame(this);
}
