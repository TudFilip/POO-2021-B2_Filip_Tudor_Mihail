#include "Template_Vector.h"

const char* typeOfSort()
{
	cout << "Scrie \"descrescator\" daca doresti sa sortezi vectorul descrescator, sau \"crescator\" daca\ndoresti sa il ordonezi crescator: ";
	char* text = new char[50];
	cin.get(text, 50);
	return text;
}



int main()
{
	Vector<int> v;

	v.push(1);
	v.push(7);
	v.push(4);
	v.push(2);
	v.push(10);

	//cout << v.pop()<<endl;
	v.print();
	cout << endl;
	v.sort(typeOfSort());
	v.print();
	//v.set(3, 3);
	//cout << v.get(3);

	return 0;
}