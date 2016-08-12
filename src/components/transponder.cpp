#include "transponder.h"

transponder::transponder()
{
}
transponder::~transponder()
{
}
void transponder::update()
{
	if(!mregistered)
	{
		mid = getregistry()->registrate();
		mregistered = true;
		getregistry()->updateteam(mid,mteam);
	}
	getregistry()->updateposition(mid,mposition);
}
void transponder::receivemessage(message msg)
{
	if(msg.get("death"))
	{
		getregistry()->deregistrate(mid);
	}
	
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
