#include "StudentMaster.hpp"

StudentMaster::StudentMaster() :
	Student::Student(),
	internshipGrade(-1.f)
{
}

StudentMaster::StudentMaster(int id, string name, string specialty, float internshipGrade) :
	Student::Student(id, name, specialty),
	internshipGrade(internshipGrade)
{
}

StudentMaster::~StudentMaster()
{
}

void StudentMaster::displayInformation() const
{
	// Display inforamtion from the parent class.
	Student::displayInformation();

	// Also display the internship grade.
	cout << "Internship grade: " << this->internshipGrade << endl;
}

bool StudentMaster::hasPassed() const
{
	// Check if the grade is enough to pass.
	return this->internshipGrade > 10;
}