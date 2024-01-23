#include "MyVector.hpp"

MyVector::MyVector()
{
}

MyVector::MyVector(int *coordinate, int vectorSize)
{
	// Calling the initCoordinate function (created to avoid repetition among many function)
	this->initCoordinate(coordinate, vectorSize);
}

MyVector::MyVector(MyVector* otherVector)
{
	// Calling the initCoordinate function (created to avoid repetition among many function)
	this->initCoordinate(otherVector->getCoordinate(), otherVector->getVectorSize());
}

// Function called to init the coordinate of the vector.
void MyVector::initCoordinate(int *coordinate, int vectorSize)
{
	this->vectorSize = vectorSize;

	// Depending of how we are initializing the vector, we may have something on the coordinate.
	if (this->coordinate != nullptr)
	{
		delete this->coordinate;
	}
	// Creating a new tab.
	this->coordinate = new int[this->vectorSize];

	// Writing all int value in the table.
	for(int i = 0; i < vectorSize; i++)
		this->coordinate[i] = coordinate[i];
}

MyVector::~MyVector()
{
	// Free the allocated memory.
	delete coordinate;
}

int MyVector::getVectorSize()
{
	return this->vectorSize;
}

int* MyVector::getCoordinate()
{
	return this->coordinate;
}

void MyVector::setVectorSize(int newVectorSize)
{
	this->vectorSize = newVectorSize;
}

void MyVector::setCoordinate(int* newCoordinate)
{
	this->coordinate = newCoordinate ;
}

void MyVector::displayElements()
{
	cout << "Address: " << this->coordinate << endl;
	
	// Iterating amond all elements to see what is in the tab.
	for (int i=0; i<this->vectorSize; i++)
		cout << this->coordinate[i] << "\t";
	cout << endl;
}

bool MyVector::operator==(MyVector& otherVector)
{
    // If both set size aren't equal, then vectors are not the same.
    if (this->vectorSize != otherVector.getVectorSize())
        return false;
    
	// Iterating among all values to check if vectors have the same element everywhere.
	for (int index = 0; index < this->vectorSize; index++)
	{
		// If only one coordinate is different, then vectors are not equals.
		if (this->coordinate[index] != otherVector.getCoordinate()[index])
			return false;
	}
	// If this line is reached, it means that all coordinates are the same.
    return true;
}

bool MyVector::operator!=(MyVector& otherVector)
{
    // If both set size aren't equal, then vectors are not the same.
    if (this->vectorSize != otherVector.getVectorSize())
        return true;
    
	// Iterating among all values to check if vectors have the same element everywhere.
	for (int index = 0; index < this->vectorSize; index++)
	{
		// If only one coordinate is different, then vectors are not equals.
		if (this->coordinate[index] != otherVector.getCoordinate()[index])
			return true;
	}
	// If this line is reached, it means that all coordinates are the same.
    return false;
}

void MyVector::operator=(const MyVector& vectorToCopy)
{
	// To overload, we just have to call the init function.
	initCoordinate(vectorToCopy.coordinate, vectorToCopy.vectorSize);
}

void MyVector::operator+=(MyVector& secondVector)
{
	// We have to initialize the size of this if this vector is too small.
	initializeSizeForOperator(*this, secondVector);

	// Keeping the size of the second vector in mind.
	int vectorSizeSecondVector = secondVector.getVectorSize();

	// Iterating among the vector size.
	for (int i=0; i<this->vectorSize; i++)
	{
		// If the second vector is too small, the default value to add is a 0.
		int valueToAdd = 0;

		// Checking if the secondVector is big enough
		if (i<vectorSizeSecondVector)
			valueToAdd =  secondVector.getCoordinate()[i];

		// Adding the value.
		this->coordinate[i] += valueToAdd;	
	}
}

MyVector MyVector::operator+(MyVector& secondVector)
{
	// Instantiation of a new vector
	MyVector newVector = this;

	// Calling the += function that does all the computation.
	newVector += secondVector;

	return newVector;
}

void MyVector::operator-=(MyVector& secondVector)
{
	// We have to initialize the size of this if this vector is too small.
	initializeSizeForOperator(*this, secondVector);

	// Keeping the size of the second vector in mind.
	int outputSizeSecondVector = secondVector.getVectorSize();

	// Iterating among the vector size.
	for (int i=0; i<this->vectorSize; i++)
	{
		// If the second vector is too small, the default value to substract is a 0.
		int valueToSubstract = 0;

		// Checking if the secondVector is big enough
		if (i<outputSizeSecondVector)
			valueToSubstract =  secondVector.getCoordinate()[i];

		// Substracting the value.
		this->coordinate[i] -= valueToSubstract;	
	}
}

MyVector MyVector::operator-(MyVector& secondVector)
{
	// Instantiation of a new vector
	MyVector newVector = this;

	// Calling the -= function that does all the computation.
	newVector -= secondVector;

	return newVector;
}

void MyVector::operator*=(MyVector& secondVector)
{
	// We have to initialize the size of this if this vector is too small.
	initializeSizeForOperator(*this, secondVector);

	// Keeping the size of the second vector in mind.
	int outputSizeSecondVector = secondVector.getVectorSize();

	// Iterating among the vector size.
	for (int i=0; i<this->vectorSize; i++)
	{
		// If the second vector is too small, the default value to multiply is a 0.
		int valueForMultiplication = 0;

		// Checking if the secondVector is big enough
		if (i<outputSizeSecondVector)
			valueForMultiplication =  secondVector.getCoordinate()[i];

		// Multiplication of the two value.
		this->coordinate[i] *= valueForMultiplication;	
	}
}

MyVector MyVector::operator*(MyVector& secondVector)
{
	// Instantiation of a new vector
	MyVector newVector = this;

	// Calling the *= function that does all the computation.
	newVector *= secondVector;

	return newVector;
}

void MyVector::operator/=(MyVector& secondVector)
{
	// We have to initialize the size of this if this vector is too small.
	initializeSizeForOperator(*this, secondVector);

	// Keeping the size of the second vector in mind.
	int outputSizeSecondVector = secondVector.getVectorSize();

	// Iterating among the vector size.
	for (int i=0; i<this->vectorSize; i++)
	{
		// If the second vector is too small, the default value that divide is a 0.
		int valueThatDivide = 0;

		// Checking if the secondVector is big enough
		if (i<outputSizeSecondVector)
			valueThatDivide = secondVector.getCoordinate()[i];
		
		// Avoid the division by 0
		if (valueThatDivide==0)
			this->coordinate[i] = -1;
		else
			this->coordinate[i] /= valueThatDivide;	
	}
}

MyVector MyVector::operator/(MyVector& secondVector)
{
	// Instantiation of a new vector
	MyVector newVector = this;

	// Calling the /= function that does all the computation.
	newVector /= secondVector;

	return newVector;
}

// Function called to initialise size of the first vector if it's size is not appropriate.
void initializeSizeForOperator(MyVector& firstVector, MyVector& secondVector)
{
	// Computing thez output size.
	int outputSize = max(firstVector.vectorSize, secondVector.vectorSize);
	
	// If the first vector size is not big enough, we have to change it's vector.
	if (firstVector.vectorSize < outputSize)
	{
		// Creating a new empty table.
		int newCoordinates[outputSize] = {0};
		
		// Adding all information in the new table.
		for (int index=0; index<firstVector.vectorSize; index++)
			newCoordinates[index] = firstVector.coordinate[index];

		// Calling the init function that will make all the init properly.
		firstVector.initCoordinate(newCoordinates, outputSize);
	}
}