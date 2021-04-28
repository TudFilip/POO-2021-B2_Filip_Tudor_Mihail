#pragma once
#include<iostream>

using namespace std;

template<class T>
class ArrayIterator
{
private:
	int Current; // mai adaugati si alte date si functii necesare pentru iterator

public:

	ArrayIterator();
	ArrayIterator& operator ++ ();
	ArrayIterator& operator -- ();
	bool operator= (ArrayIterator<T>&);
	bool operator!=(ArrayIterator<T>&);
	T* GetElement();
};