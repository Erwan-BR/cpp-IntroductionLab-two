#ifndef STUDENT_HPP_
#define STUDENT_HPP_

#include <iostream>

using namespace std;

class Student
{
protected:
	int id;
	string name;
	string specialty;

public:
	Student();
	Student(int id, string name, string specialty);
	virtual ~Student();

	virtual void displayInformation() const;
	virtual bool hasPassed() const;
};

#endif /* STUDENT_HPP_ */
