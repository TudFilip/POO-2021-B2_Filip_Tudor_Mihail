#pragma once

#include <iostream>
#include <cstring>

using namespace std;

class Student
{
private:
	char name[256];
	float english;
	float mathematics;
	float history;

public:
	void SetName();
	void GetName(char student_name[256]);
	void SetGradeEng(float x);
	void SetGradeMat(float x);
	void SetGradeHst(float x);
	void GetGradeEng(float& x);
	void GetGradeMat(float& x);
	void GetGradeHst(float& x);
	void AverageGrade(float& x);
};