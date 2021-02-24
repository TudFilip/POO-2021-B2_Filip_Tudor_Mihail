#include "StudentClass.h"
#include "GlobalFunctions.h"

int Functions::CompareName(Student s1, Student s2)
{
	char name_student1[256], name_student2[256];
	s1.GetName(name_student1);
	s2.GetName(name_student2);

	if (strcmp(name_student1, name_student2) == 1)
		return 0;
	else
		if (strcmp(name_student1, name_student2) > 1)
			return 1;
		else
			return -1;
}

int Functions::CompareGradeEng(Student s1, Student s2)
{
	float grade_student1, grade_student2;
	s1.GetGradeEng(grade_student1);
	s2.GetGradeEng(grade_student2);

	if (grade_student1 == grade_student2)
		return 0;
	else
		if (grade_student1 > grade_student2)
			return 1;
		else
			return -1;
}

int Functions::CompareGradeMat(Student s1, Student s2)
{
	float grade_student1, grade_student2;
	s1.GetGradeMat(grade_student1);
	s2.GetGradeMat(grade_student2);

	if (grade_student1 == grade_student2)
		return 0;
	else
		if (grade_student1 > grade_student2)
			return 1;
		else
			return -1;
}

int Functions::CompareGradeHst(Student s1, Student s2)
{
	float grade_student1, grade_student2;
	s1.GetGradeHst(grade_student1);
	s2.GetGradeHst(grade_student2);

	if (grade_student1 == grade_student2)
		return 0;
	else
		if (grade_student1 > grade_student2)
			return 1;
		else
			return -1;
}

int Functions::CompareAverageGrade(Student s1, Student s2)
{
	float av_grade_student1, av_grade_student2;
	s1.AverageGrade(av_grade_student1);
	s2.AverageGrade(av_grade_student2);

	if (av_grade_student1 == av_grade_student2)
		return 0;
	else
		if (av_grade_student1 > av_grade_student2)
			return 1;
		else
			return -1;
}