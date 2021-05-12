#pragma once
#include <iostream>
#include <exception>
#include "clasa_compare.h"
#include "clasa_iterator.h"

using namespace std;

class index_exception: public exception {
	virtual const char* what() const throw ()
	{
		return "Indexul este dat gresit!\n";
	}
};

template<class T>
class Array
{
private:

	T** List; // lista cu pointeri la obiecte de tipul T*
	int Capacity; // dimensiunea listei de pointeri
	int Size; // cate elemente sunt in lista

public:

	Array() {
		this->Capacity = 0;
		this->Size = 0;
	}// Lista nu e alocata, Capacity si Size = 0
	~Array() {
		this->Capacity = 0;
		this->Size = 0;
		free(this->List);
	}// destructor
	Array(int capacity) {
		this->Capacity = capacity;
		this->Size = 0;
		this->List = (T**)malloc(sizeof(T*) * capacity);
	}// Lista e alocata cu 'capacity' elemente
	Array(const Array<T>& otherArray) {
		this->Capacity = otherArray.Capacity;
		this->Size = otherArray.Size;
		memcpy(this->List, otherArray.List, otherArray.Capacity);
	}// constructor de copiere

	T& operator[] (int index) {
		index_exception exc_index;
		try {
			if (index >= this->Size || index < 0)
				throw exc_index;
			return *List[index];
		}
		catch (exception& exc) {
			cout << "Exceptia este: " << exc.what() << '\n';
		}
	}// arunca exceptie daca index este out of range

	const Array<T>& operator+=(const T& newElem) {
		if (this->Capacity == 0)
		{
			this->Capacity = 1;
			this->List = (T**)malloc(sizeof(T*) * this->Capacity);
		}
		if (this->Size == this->Capacity)
		{
			this->List = (T**)realloc(List, sizeof(T*) * Capacity * 2);
			this->Capacity *= 2;
		}
		this->List[Size] = (T*)malloc(sizeof(newElem));
		memcpy(this->List[Size], &newElem, sizeof(newElem));
		this->Size++;
		return *this;
	}// adauga un element de tipul T la sfarsitul listei si returneaza this

	const Array<T>& Insert(int index, const T& newElem) {
		index_exception exc_index;
		try {
			if (index > this->Size || index < 0 || this->Size + 1 > this->Capacity)
				throw exc_index;
			
			this->List[Size] = (T*)malloc(sizeof(this->List[Size - 1]));
			
			for (int i = index; i < Size; i++)
			{
				realloc(this->List[i + 1], sizeof(this->List[i]));
				memcpy(this->List[i + 1], this->List[i], sizeof(this->List[i]));
			}
			realloc(this->List[index], sizeof(newElem));
			memcpy(this->List[index], &newElem, sizeof(newElem));
			this->Size++;
			return *this;
		}
		catch (exception& exc)
		{
			cout << "Exceptia este: " << exc.what() << '\n';
		}
		
	}// adauga un element pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie

	const Array<T>& Insert(int index, const Array<T> otherArray) {
		index_exception exc_index;
		try {
			if (index >= this->Size || index < 0 || this->Size + otherArray.Size > this->Capacity)
				throw exc_index;

			this->Size += otherArray.Size;

			for (int i = this->Size - 1; i > index + otherArray.Size - 1; i--)
			{
				realloc(this->List[i], sizeof(this->List[i - otherArray.Size]));
				memcpy(this->List[i], this->List[i - otherArray.Size], sizeof(this->List[i - otherArray.Size]));
			}

			for (int i = otherArray.Size - 1; i >= 0; i--)
			{
				realloc(this->List[index + i], sizeof(otherArray.List[i]));
				memcpy(this->List[index + i], otherArray.List[i], sizeof(otherArray.List[i]));
			}

			return *this;
		}
		catch (exception& exc)
		{
			cout << "Exceptia este: " << exc.what() << '\n';
		}
	}// adauga o lista pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie

	const Array<T>& Delete(int index) {
		index_exception exc_index;
		try {
			if (index >= this->Size || index < 0)
				throw exc_index;

			for (int i = index; i < this->Size; i++)
			{
				//this->List[i] = (T*)realloc(this->List[i], sizeof(this->List[i + 1]));
				List[i] = List[i + 1];
				//memcpy(this->List[i], this->List[i + 1], sizeof(this->List[i + 1]));
			}
			//free(this->List[this->Size - 1]);
			this->Size--;
			return *this;
		}
		catch (exception& exc)
		{
			cout << "Exceptia este: " << exc.what() << '\n';
		}
	}// sterge un element de pe pozitia index, returneaza this. Daca index e invalid arunca o exceptie

	bool operator=(const Array<T>& otherArray) {
		this->Size = otherArray.Size;
		this->Capacity = otherArray.Capacity;
		free(this->List);
		delete this->List;
		this->List = (T**)malloc(sizeof(T*) * otherArray.Capacity);
		for (int i = 0; i < otherArray.Size; i++)
		{
			this->List[i] = (T*)malloc(sizeof(otherArray.List[i]));
			memcpy(this->List[i], otherArray.List[i], sizeof(otherArray.List[i]));
		}
		return true;
	}

	void Sort(); // sorteaza folosind comparatia intre elementele din T
	void Sort(int(*compare)(const T&, const T&)); // sorteaza folosind o functie de comparatie
	void Sort(Compare* comparator); // sorteaza folosind un obiect de comparatie

	// functii de cautare - returneaza pozitia elementului sau -1 daca nu exista
	int BinarySearch(const T& elem); // cauta un element folosind binary search in Array
	int BinarySearch(const T& elem, int(*compare)(const T&, const T&));//  cauta un element folosind binary search si o functie de comparati
	int BinarySearch(const T& elem, Compare* comparator);//  cauta un element folosind binary search si un comparator

	int Find(const T& elem); // cauta un element in Array
	int Find(const T& elem, int(*compare)(const T&, const T&));//  cauta un element folosind o functie de comparati
	int Find(const T& elem, Compare* comparator);//  cauta un element folosind un comparator

	int GetSize()
	{
		return this->Size;
	}
	int GetCapacity()
	{
		return this->Capacity;
	}

	//ArrayIterator<T> GetBeginIterator();
	//ArrayIterator<T> GetEndIterator();
};