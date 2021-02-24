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
	void GetName(char *student_name);
	void SetGradeEng();
	void SetGradeMat();
	void SetGradeHst();
	void GetGradeEng();
	void GetGradeMat();
	void GetGradeHst();

}