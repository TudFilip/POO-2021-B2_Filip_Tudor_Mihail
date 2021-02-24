#include "StudentClass.h"

void Student::SetName()
{
	cin.getline(name, 255);
}

void Student::GetName(char* student_name)
{
	strcpy(student_name, name);
}

void Student::SetGradeEng(float x) 
{
	english = x;
}

void Student::SetGradeHst(float x)
{
	history = x;
}

void Student::SetGradeMat(float x)
{
	mathematics = x;
}

void Student::GetGradeEng(float& x)
{
	x = english;
}

void Student::GetGradeHst(float& x)
{
	x = history;
}

void Student::GetGradeMat(float& x)
{
	x = mathematics;
}

void Student::AverageGrade(float& x)
{
	x = (english + history + mathematics) / 3.0;
}