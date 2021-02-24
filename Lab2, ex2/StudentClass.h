#pragma once

#include <iostream>

using namespace std;

class Student
{
private:
	char* name;
	float english;
	float mathematics;
	float history;

public:
	void SetName();
	void GetName(char* student_name);
	void SetGradeEng(float x);
	void SetGradeMat(float x);
	void SetGradeHst(float x);
	void GetGradeEng(float& x);
	void GetGradeMat(float& x);
	void GetGradeHst(float& x);
	void AverageGrade(float& x);
};