#pragma once
#include <map>
#include <string>

class message
{
public:
	message ();
	virtual ~message ();
	int get(const std::string key);
	void set(const std::string key, int value);
	void print();

private:
	std::map<std::string,int> data;
};
