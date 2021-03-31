#pragma once
#include <iostream>

using namespace std;

template <class T>
class vector
{
	T* vector;
	int size;
	int count;

public:
	vector(): size(0), vector(T()), count(0) {}
	void push(T* value);
	T& pop();
	void remove(int index);
	void insert(int index, T* value);
	const T& get(int index);
	void set(int index, T* value);
	int count();
	void print();
};