#pragma once
#include <iostream>
#define MAX_OBJ 100

using namespace std;

template <class T1, class T2>
class Map
{
public:
	struct obj {
		T1 key;
		T2 value;
		int index;
	};
	obj objects[MAX_OBJ];
	int global_index;
	
	Map(): global_index(0) {}

};