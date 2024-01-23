#include "StudentEngineer.hpp"

StudentEngineer::StudentEngineer() :
	Student::Student(),
	toeicGrade(-1)
{
}

StudentEngineer::StudentEngineer(int id, string name, string specialty, int toeicGrade) :
	Student::Student(id, name, specialty),
	toeicGrade(toeicGrade)
{
}

StudentEngineer::~StudentEngineer()
{
}

void StudentEngineer::displayInformation() const
{
	// Display inforamtion from the parent class.
	Student::displayInformation();

	// Also display the TOEIC grade.
	cout << "TOEIC grade: " << this->toeicGrade << endl ;
}

bool StudentEngineer::hasPassed() const
{
	// Check if the grade is enough to pass.
	return this->toeicGrade > 600;
}