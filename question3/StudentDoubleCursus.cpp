#include "StudentDoubleCursus.hpp"

StudentDoubleCursus::StudentDoubleCursus() :
	// It has to call every parent initializer to avoid the diamond problem.
	Student(),
	StudentMaster(),
	StudentEngineer()
{
}

StudentDoubleCursus::StudentDoubleCursus(int id, string name, string specialty, float internshipGrade, int toeicGrade) :
	// It has to call every parent initializer to avoid the diamond problem.
	Student(id, name, specialty),
	StudentMaster(id, name, specialty, internshipGrade),
	StudentEngineer(id, name, specialty, toeicGrade)
{
}

StudentDoubleCursus::~StudentDoubleCursus()
{
}

void StudentDoubleCursus::displayInformation() const
{
	// Calling the StudentMaster display information to get every information that is already contains in this class.
	StudentMaster::displayInformation();
	// Printing also the TOEIC grade (which comes from the inheritance of StudentEngineer)
	cout << "TOEIC grade: " << this->toeicGrade << endl;
}

bool StudentDoubleCursus::hasPassed() const
{
	// Getting both source of truth to check if the Double cursus student passed.
	bool hasPassedTOEIC = StudentEngineer::hasPassed();
	bool hasPassedInternship = StudentMaster::hasPassed();

	// The student passed only if he has passed in both ways.
	return hasPassedInternship && hasPassedTOEIC;
}