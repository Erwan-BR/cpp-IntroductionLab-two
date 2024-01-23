#ifndef STUDENTENGINEER_HPP_
#define STUDENTENGINEER_HPP_

#include <iostream>
#include "Student.hpp"

using namespace std;

// The class has to inherite virtually to avoid any ambiguous problem.
class StudentEngineer : public virtual Student
{
protected:
	int toeicGrade;
public:
	StudentEngineer();
	StudentEngineer(int id, string name, string specialty, int toeicGrade);
	virtual ~StudentEngineer();

	void displayInformation() const override;
	bool hasPassed() const override;
};

#endif /* STUDENTENGINEER_HPP_ */
