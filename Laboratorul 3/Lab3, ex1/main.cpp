#include "Math.h"

int main()
{
	cout << "Suma numerelor 20 si 50 este: " << Math::Add(20, 50) << '\n';
	cout << "Suma numerelor 20, 50 si 80 este: " << Math::Add(20, 50, 80) << '\n';
	cout << "Suma numerelor 27.3 si 12.5 este: " << Math::Add(27.3, 12.5) << '\n';
	cout << "Suma numerelor 14.5, 15.5 si 5.3 este: " << Math::Add(14.5, 15.5, 5.3) << "\n\n";
	cout << "---------------------------------\n\n";
	cout << "Inmultirea numerelor 20 si 50 da: " << Math::Mul(20, 50) << '\n';
	cout << "Inmultirea numerelor 20, 50 si 80 da: " << Math::Mul(20, 50, 80) << '\n';
	cout << "Inmultirea numerelor 27.3 si 12.5 da: " << Math::Mul(27.3, 12.5) << '\n';
	cout << "Inmultirea numerelor 14.5, 15.5 si 5.3 da: " << Math::Mul(14.5, 15.5, 5.3) << "\n\n";
	cout << "---------------------------------\n\n";
	cout << "Suma unei liste oarecare de 9 elemente este: " << Math::Add(9, 2, 5, 4, 13, 14, 20, 75, 21, 18) << "\n\n";
	cout << "---------------------------------\n\n";
	const char *s1 = "1970";
	const char *s2 = "230";
	char *s3 = Math::Add(s1, s2);
	cout << "Suma a unui string \"1970\" cu alt string \"230\" este: " << *s3;

	return 0;
}