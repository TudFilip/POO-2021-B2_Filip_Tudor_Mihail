#pragma once

#include "StudentClass.h"

class Functions 
{
public:
	static int CompareName(Student s1, Student s2);
	static int CompareGradeEng(Student s1, Student s2);
	static int CompareGradeMat(Student s1, Student s2);
	static int CompareGradeHst(Student s1, Student s2);
	static int CompareAverageGrade(Student s1, Student s2);
};