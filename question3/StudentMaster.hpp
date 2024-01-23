#ifndef STUDENTMASTER_HPP_
#define STUDENTMASTER_HPP_

#include <iostream>

#include "Student.hpp"

using namespace std;

// The class has to inherite virtually to avoid any ambiguous problem.
class StudentMaster : public virtual Student
{
protected:
	float internshipGrade;
public:
	StudentMaster();
	StudentMaster(int id, string name, string specialty, float internshipgrade);
	virtual ~StudentMaster();

	void displayInformation() const override;
	bool hasPassed() const override;
};

#endif /* STUDENTMASTER_HPP_ */
