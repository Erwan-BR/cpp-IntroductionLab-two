#ifndef STUDENTDOUBLECURSUS_HPP_
#define QUESTION3_STUDENTDOUBLECURSUS_HPP_

#include <iostream>

#include "StudentEngineer.hpp"
#include "StudentMaster.hpp"

using namespace std;

class StudentDoubleCursus : public StudentEngineer, StudentMaster
{
public:
	StudentDoubleCursus();
	StudentDoubleCursus(int id, string name, string specialty, float internshipGrade, int toeicGrade);
	virtual ~StudentDoubleCursus();

	void displayInformation() const override;
	bool hasPassed() const override;
};

#endif /* STUDENTDOUBLECURSUS_HPP_ */