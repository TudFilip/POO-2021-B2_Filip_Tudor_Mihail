#pragma once
#include "Template_Vector.h"

template<class T>
void vector<T>::push(T* value) 
{
	if (size == 0)
	{
		vector = (T*)malloc(2 * sizeof(T));
		size = 2;
	}
	else
		if (count == size)
			vector = (T*)malloc((2 * size) * sizeof(T));

	vector[count] = (*value);
	count++;
}

template<class T>
T& vector<T>::pop()
{
	count--;
	return vector[count];
}

template<class T>
void vector<T>::remove(int index)
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

template<class T>
void vector<T>::insert(int index, T* value)
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
	vector[index] = (*value);
	count++;
}

template<class T>
const T& vector<T>::get(int index)
{
	if (index >= count)
	{
		cout << "Wrond index!\n";
		return nullptr;
	}
	
	return vector[index];
}

template<class T>
void vector<T>::set(int index, T* value)
{
	if (index < count)
	{
		vector[index] = (*value);
	}
	else
		cout << "Wrond index!\n";
}

template<class T>
int vector<T>::count()
{
	return this->count - 1;
}

template<class T>
void vector<T>::print()
{
	if (count == 0)
		cout << "Vector has no elements!\n";
	else
		for (int i = 0; i < count; i++)
		{
			cout << get(i) << ' ';
		}
}