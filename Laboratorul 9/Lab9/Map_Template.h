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

	class Iterator
	{
	public:
		obj* p;
		int it_index = 0;
		Iterator& operator++()
		{
			p++;
			it_index++;
			return *this;
		}

		bool operator !=(Iterator& i)
		{
			return p != i.p;
		}

		obj operator*()
		{
			obj p2;
			p2.key = p->key;
			p2.value = p->value;
			p2.index = it_index;
			return p2;
		}
	};

	Iterator begin()
	{
		Iterator tmp;
		tmp.it_index = 0;
		tmp.p = &objects[0];
		return tmp;
	}
	Iterator end()
	{
		Iterator tmp;
		tmp.it_index = global_index;
		tmp.p = &objects[global_index];
		return tmp;
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

	void Set(const T1& key, const T2& value)
	{
		int i, ok = 0;
		for (i = 0; i < global_index; i++)
		{
			if (objects[i].key == key)
			{
				ok = 1;
				objects[i].value = value;
				break;
			}
		}
		if(!ok)
			cout << "Nu exista cheia aleasa!\n";
	}

	bool Get(const T1& key, T2& value)
	{
		for (int i = 0; i < global_index; i++)
		{
			if (objects[i].key == key)
			{
				value = objects[i].value;
				return true;
			}
		}
		return false;
	}

	int Count()
	{
		return this->global_index;
	}

	void Clear()
	{
		for (int i = 0; i < global_index; i++)
		{
			objects[i].key = NULL;
			objects[i].value = NULL;
			objects[i].index = 0;
		}
		global_index = 0;
	}

};