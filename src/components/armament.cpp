#include "armament.h"

armament::armament()
{
}

armament::~armament()
{
}

void armament::update()
{
	if(cooldown == 0)
	{
		int target = getregistry()->getclosest(mposition, mteam);
		ivec2 delta = getregistry()->getposition(target) - mposition;
		//delta.setx(rand()%10-5);
		//delta.sety(rand()%10-5);
		for(int i = 0; i< 1; i++)
		{
			message msg;
			msg.set("dumbmover",1);
			msg.set("lifetimer",1);
			msg.set("shotdraw",1);
			//msg.set("trail",1);
			msg.set("changeposition",1);
			msg.set("x",mposition.getx());
			msg.set("y",mposition.gety());
			msg.set("changedelta",1);
			msg.set("deltax",delta.getx());
			msg.set("deltay",delta.gety());
			buildentity(msg);
		}
		cooldown = 300;
	}
	cooldown--;
}

void armament::receivemessage(message msg)
{
	if(msg.get("changeposition"))
	{
		mposition.setx(msg.get("x"));
		mposition.sety(msg.get("y"));
	}
	if(msg.get("changeteam"))
	{
		mteam = msg.get("team");
	}
}
