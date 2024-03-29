#define _CRT_SECURE_NO_WARNINGS
#include "StudentClass.h"

void Student::SetName()
{
	char name_student[256];
	cin.getline(name_student, 255);
	strcpy(name, name_student);
}

void Student::GetName(char student_name[256])
{
	strcpy(student_name, this->name);
}

void Student::SetGradeEng(float x) 
{
	this->english = x;
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
	 x = (english + history + mathematics) / (float)3.0f;
}