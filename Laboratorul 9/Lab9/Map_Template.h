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

	Map begin()
	{
		return &objects[0];
	}

	Map end()
	{
		return &objects[global_index];
	}

	T2& operator [](const T1& key)
	{
		for (int i = 0; i < global_index; i++)
		{
			if (objects[i].key == key)
				return objects[i].value;
		}

		objects[global_index].key = key;
		return objects[global_index++].value;
	}
};