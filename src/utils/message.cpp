#include <iostream>
#include "message.h"

message::message()
{
}

message::~message()
{
}

int message::get(const std::string key)
{
	std::map<std::string,int>::iterator it = data.find(key);

	if(it != data.end())
	{
		return it->second;
	}
	return 0;
}

void message::set(const std::string key, int value)
{
	data[key] = value;
}

void message::print()
{
	for(const auto& element : data)
	{
		std::cout << element.first << ' ';
		std::cout << element.second << '\n';
	}
}
