#pragma once
#include <iostream>
#include <exception>
#include "clasa_compare.h"
#include "clasa_iterator.h"

using namespace std;

class Compare
{
public:
	virtual int CompareElements(void* e1, void* e2) = 0;
};

class index_exception {
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
		delete List;
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
			return List[index];
		}
		catch (exception& exc) {
			cout << "Exceptia este: " << exc.what() << '\n';
		}
	}// arunca exceptie daca index este out of range

	const Array<T>& operator+=(const T& newElem) {
		if (this->Size == this->Capacity)
			realloc(List, this->Capacity * 2);
		this->List[size] = (T*)malloc(sizeof(newElem));
		memcpy(this->List[size], newElem, sizeof(newElem));
		this->Size++;
		return *this;
	}// adauga un element de tipul T la sfarsitul listei si returneaza this
	const Array<T>& Insert(int index, const T& newElem) {
		index_exception exc_index;
		try {
			if (index >= this->Size || index < 0 || index + 1 > this->Capacity)
				throw exc_index;
			
			this->List[size] = (T*)malloc(sizeof(this->List[size - 1]));
			
			for (int i = index; i < size; i++)
			{
				realloc(this->List[i + 1], sizeof(this->List[i]));
				memcpy(this->List[i + 1], this->List[i], sizeof(this->List[i]);
			}
			realloc(this->List[index], sizeof(newElem));
			memcpy(this->List[index], newElem, sizeof(newElem));
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
			if (index >= this->Size || index < 0 || index + otherArray.Size > this->Capacity)
				throw exc_index;

			for (int i = this->Size; i < otherArray.Size; i++)
			{
				this->List[i] = (T*)malloc(sizeof(this->List[]))
			}
			return *this;
		}
		catch (exception& exc)
		{
			cout << "Exceptia este: " << exc.what() << '\n';
		}
	}// adauga o lista pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie
	const Array<T>& Delete(int index); // sterge un element de pe pozitia index, returneaza this. Daca index e invalid arunca o exceptie

	bool operator=(const Array<T>& otherArray);

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

	int GetSize();
	int GetCapacity();

	ArrayIterator<T> GetBeginIterator();
	ArrayIterator<T> GetEndIterator();
};