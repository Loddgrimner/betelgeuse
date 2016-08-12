#pragma once
#include <unordered_map>
#include "registration.h"
#include "message.h"

class registry
{
public:
	registry ();
	virtual ~registry ();
	void update();
	int registrate();
	void deregistrate(int id);
	void updateposition(int id, ivec2 position);
	void updateteam(int id, int team);
	int getclosest(ivec2 position, int team);
	ivec2 getposition(int id);
	int checkposition(ivec2 position);
	void sendmessage(int id, message msg);
	std::pair<std::unordered_multimap<int,message>::iterator, std::unordered_multimap<int,message>::iterator> getmessages(int id);
	void clearmessages();
	

private:
	std::unordered_map<int,registration> data;
	std::unordered_multimap<int,message> messages;
	int counter = 0;
};
