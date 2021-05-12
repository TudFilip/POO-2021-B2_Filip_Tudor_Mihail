#pragma once
#include <iostream>
#include <stdarg.h>

using namespace std;

template <class T>
class Sort {

private:
	
	T* List;
	int size;
	int capacity;

public:

	Sort() : size(0), capacity(1) {
		List = new T[capacity];
	}

	Sort(int Capacity) {
		size = 0;
		capacity = Capacity;
		List = new T[capacity];
	}

	Sort(int nr_elements, ...) {
		size = nr_elements;
		capacity = 1;
		while (capacity <= size)
		{
			capacity *= 2;
		}
		List = new T[capacity];

		va_list ap;
		T val;
		va_start(ap, nr_elements);

		for (int i = 0; i < nr_elements; i++)
		{
			val = va_arg(ap, T);
			List[i] = val;
		}

		va_end(ap);
	}

	void AddElement(const T& new_item)
	{
		List[size] = new_item;
		size++;

		if (size == capacity)
		{
			capacity *= 2;
			List = (T*)realloc(List, sizeof(T) * capacity);
		}
	}

	T operator[](int index)
	{
		return List[index];
	}

	void Sorting()
	{
		for (int i = 1; i < size - 1; i++)
		{
			for (int j = i; j < size - 1; j++)
			{
				if(List[i] > 0)
					if (List[i] > List[j])
					{
						List[i] = List[i] + List[j];
						List[j] = List[i] - List[j];
						List[i] = List[i] - List[j];
					}
				if(List[i] < 0)
					if (List[i] < List[j])
					{
						T tmp = List[i];
						List[i] = List[j];
						List[j] = tmp;
						
						tmp = List[i];
						List[i] = List[j];
						List[j] = tmp;
					}
			}
		}
	}

	void Print()
	{
		for (int i = 0; i < size; i++)
		{
			cout << List[i] << " ";
		}
		cout << "\n\n";
	}

};
