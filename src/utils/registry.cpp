#include "registry.h"
#include "ivec2.h"
#include <ncurses.h>

registry::registry()
{
}

registry::~registry()
{
}

void registry::update()
{
	attron(COLOR_PAIR(1));
	mvprintw(0,0,"Registry update. Count: %i",data.size());
	mvprintw(1,0,"Closest id: %i", getclosest(ivec2(5,5),0));

	int n = 2;
	for (auto& i :data){
		mvprintw(
			n,
			0,
			"Id:%i Team:%i x:%i y:%i",
			i.first,
			i.second.mteam,
			i.second.mposition.getx(),
			i.second.mposition.gety()
		);
		n++;
	}
	
}

int registry::registrate()
{
	counter++;
	data.emplace(counter,registration());
	return counter;
}

void registry::deregistrate(int id)
{
	data.erase(id);
}

void registry::updateposition(int id, ivec2 position)
{
	if(data.count(id)){
		data[id].mposition = position;
	}
}

void registry::updateteam(int id, int team)
{
	if(data.count(id)){
		data[id].mteam = team;
	}
}

int registry::getclosest(ivec2 position, int team)
{
	int id = 0;
	int distance = 0;
	bool first = true;

	for (auto& i :data){
		ivec2 delta = i.second.mposition - position;
		int dist = abs(delta.getx())+abs(delta.gety());

		if(team != i.second.mteam && (dist < distance || first)){
			first = false;
			distance = dist;
			id = i.first;
		}
	}

	return id;
}

ivec2 registry::getposition(int id)
{
	if(data.count(id)){
		return data[id].mposition;
	}
	return ivec2(0,0);
}

int registry::checkposition(ivec2 position)
{
	for (auto& i :data){
		if(position == i.second.mposition){
			return i.first;
		}
	}
	return 0;
}
void registry::sendmessage(int id, message msg)
{
	messages.insert(std::pair<int, message>(id,msg));
}

std::pair<std::unordered_multimap<int,message>::iterator, std::unordered_multimap<int,message>::iterator> registry::getmessages(int id)
{
	return messages.equal_range(id);
}

void registry::clearmessages()
{
	messages.clear();
}
