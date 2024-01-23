#include "Student.hpp"

Student::Student() :
	id(0),
	name(""),
	specialty("")
{
}

Student::Student(int id, string name, string specialty) :
	id(id),
	name(name),
	specialty(specialty)
{
}

Student::~Student()
{
}

void Student::displayInformation() const
{
	// Display information from the current Student
	cout << "Student n°" << this->id << endl;
	cout << "Name: " << this->name << endl;
	cout << "Specialty: " << this->specialty << endl;
}

bool Student::hasPassed() const
{
	// Has to return something. In fact, a student is never created because it is only a parent class.
	return false;
}