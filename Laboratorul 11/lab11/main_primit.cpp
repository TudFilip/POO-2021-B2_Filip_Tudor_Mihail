#include <iostream>
#include "header_primit.h"

int main()
{
	int b[] = { 0, 7, 8, 3 }; //vectorul de tip T
	int n = 4; //numatul de elemente din vector
	cout << "Lista elemente: 0, -7, 8, 3\n";
	cout << "Lista dupa sortare: ";
	sortare_cu_erori<int>(b, n);
	cout << "\nSolutie care ar trebui afisata: 0, 3, 7, 8\n\n";
	cout << "--------------";

	cout << "\n\n";
	//sortare_cu_erori<int>(b, 5); //nu are atentionare de numar de elemente prea mari
	cout << "In cazul in care numarul de elemente din lista dat ca paramentru este mai mare\n";
	cout << "decat numarul efectiv de elemente existente, sortarea ar trebui sa nu se poate face\n";
	cout << "si sa dea un mesaj de eroare, dar, in schimb, sortarea are loc si apare o eroare de compilare\n\n";
	cout << "--------------";

	cout << "\n\n";
	cout << "Sortare in cazul in care avem elemente negative\n";
	cout << "Lista elemente: -1, -10, -3, 3\n";
	cout << "Lista dupa sortare: ";
	int a[] = { -1, -10, -3, 3 };
	sortare_cu_erori<int>(a, n); 
	cout << "\nSolutie care ar trebui afisata: -10, -3, -1, 3\n\n";
	cout << "--------------";
	
	cout << "\n\n";
	cout << "Sortare in care se verifica daca se ia primul element in considerare\n";
	int c[] = { 3, 7, 0, 8 };
	cout << "Lista elemente: 3, 7, 0, 8\n";
	cout << "Lista dupa sortare: ";
	sortare_cu_erori<int>(c, n); 
	cout << "\nSolutie care ar trebui afisata: 0, 3, 7, 8\n\n";
	cout << "--------------";

	cout << "\n\n";
	cout << "Sortare in cazul in care avem elemente comune\n";
	int d[] = { 1, 4, 4, 2, 1, 10, 6, 5 };
	n = 8;
	cout << "Lista elemente: 1, 4, 4, 2, 1, 10, 6, 5\n";
	cout << "Lista dupa sortare: ";
	sortare_cu_erori<int>(d, n); 
	cout << "\nSolutie care ar trebui afisata: 1, 1, 2, 4, 4, 5, 6, 10\n\n";
	cout << "--------------";

	cout << "\n\n";
	cout << "Sortare in cazul in care lista are un singur element\n";
	int e[] = { 1 };
	cout << "Lista elemente: 1\n";
	cout << "Lista dupa sortare: ";
	sortare_cu_erori<int>(e, 1); 
	cout << "\nSolutie care ar trebui afisata: 1\n\n";
	cout << "--------------";

	cout << "\n\n";
	cout << "Sortare in cazul in care elementele sunt de tip char\n";
	char f[] = { 'b', 'a' };
	cout << "Lista elemente: b, a\n";
	cout << "Lista dupa sortare: ";
	sortare_cu_erori<char>(f, 2);
	cout << "\nSolutie care ar trebui afisata: a, b\n";

	return 0;
}