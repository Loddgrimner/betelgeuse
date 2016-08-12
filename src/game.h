#pragma once
#include <vector>
#include <memory>
#include <map>
#include <string>
#include "message.h"
#include "registry.h"

class entity;
class entitybuilder;
class game
{
public:
	game ();
	virtual ~game ();

	void update();
	void buildentity(message msg);
	registry* getregistry();
private:
	std::vector<std::shared_ptr<entity>> entities;
	std::vector<std::shared_ptr<entity>> builtentities;
	entitybuilder* mentitybuilder;
	registry* mregistry;
};
