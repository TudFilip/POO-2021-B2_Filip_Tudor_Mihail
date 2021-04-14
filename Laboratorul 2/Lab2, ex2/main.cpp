#include "StudentClass.h"
#include "GlobalFunctions.h"
#include <iomanip>

int main()
{
	Student s1, s2;
	float x;

	cout << "Citim numele fiecarui student\n";
	cout << "Nume student 1: ";
	s1.SetName();
	cout << "Nume student 2: ";
	s2.SetName();
	cout << "\n\n";
	

	s1.SetGradeMat(7.8);
	s1.SetGradeEng(10);
	s1.SetGradeHst(9.5);
	cout << "Note student 1:\n";
	s1.GetGradeMat(x);
	cout << "matematica: "<< x;
	cout << '\n';
	s1.GetGradeEng(x);
	cout << "engleza: " << x;
	cout << '\n';
	s1.GetGradeHst(x);
	cout << "istorie: "<< x;
	cout << "\n\n";

	s2.SetGradeMat(9.2);
	s2.SetGradeEng(9.1);
	s2.SetGradeHst(6.5);
	cout << "Note student 2:\n";
	s2.GetGradeMat(x);
	cout << "matematica: " << x;
	cout << '\n';
	s2.GetGradeEng(x);
	cout << "engleza: " << x;
	cout << '\n';
	s2.GetGradeHst(x);
	cout << "istorie: " << x;
	cout << "\n\n";


	float medie1, medie2;
	char nume_student1[256], nume_student2[256];
	
	cout << "Mediile celor doi:\n";
	s1.AverageGrade(medie1);
	s1.GetName(nume_student1);
	cout << "medie " << nume_student1 << ": " << setprecision(3) << medie1 << "\n";
	s2.AverageGrade(medie2);
	s2.GetName(nume_student2);
	cout << "medie " << nume_student2 << ": " << setprecision(3)<< medie2 << "\n";

	
	if (CompareAverageGrade(s1, s2))
		cout << nume_student1 << " are media mai mare;\n";
	else
		if (CompareAverageGrade(s1, s2) == -1)
			cout << nume_student2 << " are media mai mare;\n";
		else
			cout << "Studentii au aceeasi medie\n";
	
	
	if (CompareGradeEng(s1, s2))
		cout << nume_student1 << " are nota mai mare la engleza\n";
	else
		if (CompareGradeEng(s1, s2) == -1)
			cout << nume_student2 << " are nota mai mare la engleza\n";
		else
			cout << "Au aceeasi medie la engleza\n";
	
	
	if (CompareGradeMat(s1, s2))
		cout << nume_student1 << " are nota mai mare la matematica\n";
	else
		if (CompareGradeMat(s1, s2) == -1)
			cout << nume_student2 << " are nota mai mare la matematica\n";
		else
			cout << "Au aceeasi medie la matematica\n";

	
	if (CompareGradeHst(s1, s2))
		cout << nume_student1 << " are nota mai mare la istorie\n";
	else
		if (CompareGradeHst(s1, s2) == -1)
			cout << nume_student2 << " are nota mai mare la istorie\n";
		else
			cout << "Au aceeasi medie la istorie\n";

	
	cout << "Ordinea alfabetica a numelor studentilor: ";
	if (CompareName(s1, s2))
		cout << nume_student1 << ", " << nume_student2;
	else
		if (CompareName(s1, s2) == -1)
			cout << nume_student2 << ", " << nume_student1;
		else
			cout << nume_student1 << ", " << nume_student2;

	return 0;
}