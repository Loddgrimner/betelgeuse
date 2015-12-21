#pragma once
#include <memory>
#include <map>
#include <string>
#include "message.h"

class entity;

class component
{
public:
	component ();
	virtual ~component ();
	void sethost(entity* home);
	virtual void receivemessage(message msg) = 0;
	virtual void update() = 0;

protected:
	void sendmessage(message msg);
	void killhost();

private:
	entity* mhost = nullptr;
	/* data */
};
