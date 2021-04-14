#pragma once
#include <iostream>

using namespace std;

class Compare {
public:
	bool operator() (pair<string, int> const& a, pair<string, int> const& b) const 
	{
		if (a.second != b.second)
			return a.second < b.second;
		else if (a.first.compare(b.first) > 0)
			return true;
		else
			return false;
	}
};