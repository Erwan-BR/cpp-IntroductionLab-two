#ifndef QUESTION1_MYVECTOR_HPP_
#define QUESTION1_MYVECTOR_HPP_

#include <iostream>

using namespace std;

class MyVector
{
private:
	int *coordinate = nullptr;
	int vectorSize = 0;

	void initCoordinate(int *coordinate, int vectorSize);

	// Initializer for operators (in case of different sizes)
	friend void initializeSizeForOperator(MyVector& firstVector, MyVector& secondVector);

public:
	MyVector();
	MyVector(int *coordinate, int vectorSize);
	MyVector(MyVector* otherVector);
	virtual ~MyVector();

	// getter
	int getVectorSize();
	int* getCoordinate();

	// Setter
	void setVectorSize(int newVectorSize);
	void setCoordinate(int* newCoordinate);

	// Operators
	bool operator==(MyVector& otherVector);
    bool operator!=(MyVector& otherVector);
	
	void operator=(const MyVector& vectorToCopy);

	void operator+=(MyVector& secondVector);
	MyVector operator+(MyVector& secondVector);

	void operator-=(MyVector& secondVector);
	MyVector operator-(MyVector& secondVector);

	void operator*=(MyVector& secondVector);
	MyVector operator*(MyVector& secondVector);

	void operator/=(MyVector& secondVector);
	MyVector operator/(MyVector& secondVector);

	// Display
	void displayElements();
};

#endif /* QUESTION1_MYVECTOR_HPP_ */
