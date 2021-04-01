#pragma once
#include <iostream>
#include <stdlib.h>

using namespace std;

template <class T>
class Vector
{
	T* vector;
	int size;
	int count;

public:
	Vector() : size(0), count(0) {}
	void push(const T& value)
	{
		if (size == 0)
		{
			vector = (T*)malloc(2 * sizeof(T));
			size = 2;
		}
		else
			if (count == size)
			{
				vector = (T*)realloc(vector, (2 * size) * sizeof(T));
				size *= 2;
			}

		vector[count] = value;
		count++;
	}
	
	T& pop()
	{
		count--;
		return vector[count];
	}

	void remove(int index)
	{
		if (index >= count)
			cout << "Wrong index!\n";
		else
		{
			for (int i = index; i < count; i++)
				vector[i] = vector[i + 1];
			count--;
		}
	}

	void insert(int index, const T& value)
	{
		if (index > count)
		{
			cout << "Wrond index!\n";
			break;
		}

		if (index == count)
		{
			push(value);
			break;
		}

		for (int i = index; i < count; i++)
			vector[i + 1] = vector[i];
		vector[index] = value;
		count++;
	}

	const T& get(int index)
	{
		if (index >= count)
		{
			cout << "Wrond index!\n";
		}
		else
			return vector[index];
	}

	void set(int index, const T& value)
	{
		if (index < count)
		{
			vector[index] = value;
		}
		else
			cout << "Wrond index!\n";
	}

	int counte()
	{
		return this->count - 1;
	}

	void print()
	{
		if (count == 0)
			cout << "Vector has no elements!\n";
		else
			for (int i = 0; i < count; i++)
			{
				cout << get(i) << ' ';
			}
	}
};