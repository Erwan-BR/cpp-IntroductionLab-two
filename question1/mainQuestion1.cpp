#include "mainQuestion1.hpp"

void mainQuestion1()
{
    // Creating some vector to test the different operators.
    int firstTab[] = {1, 2, 3, 4, 5};
    int secondTab[] = {10, 20, 30, 40, 50, 60};
    int thirdTab[] = {5, 10, 15, 20};
    int fourthTab[] = {2, 4, 6};

    MyVector firstVector = MyVector(firstTab, 5);
    MyVector secondVector = MyVector(secondTab, 6);
    MyVector thirdVector = MyVector(thirdTab, 4);
    MyVector fourthVector = MyVector(fourthTab, 3);

    // Creating the vector that will be used to test +, -, *, /
    
    MyVector firstComputeVector = firstVector + firstVector + secondVector;
    MyVector secondComputeVector = secondVector - firstVector ;
    MyVector thirdComputeVector = thirdVector * secondVector;
    MyVector fourthComputeVector = thirdVector / fourthVector;

    // Assert to check if those operators worked.

    // firstVector, secondVector, thirdvector and fourthVector sould not have changed at this moment.
    assert(compareTable(firstVector.getCoordinate(), firstVector.getVectorSize(), firstTab, 5));
    assert(compareTable(secondVector.getCoordinate(), secondVector.getVectorSize(), secondTab, 6));
    assert(compareTable(thirdVector.getCoordinate(), thirdVector.getVectorSize(), thirdTab, 4));
    assert(compareTable(fourthVector.getCoordinate(), fourthVector.getVectorSize(), fourthTab, 3));

    // Checking if the computation were correct.
    int firstComputedExpectedTab[] = {12, 24, 36, 48, 60, 60};
    int secondComputedExpectedTab[] = {9, 18, 27, 36, 45, 60};
    int thirdComputedExpectedTab[] = {50, 200, 450, 800, 0, 0};
    int fourthComputedExpectedTab[] = {2, 2, 2, -1};
    assert(compareTable(firstComputeVector.getCoordinate(), firstComputeVector.getVectorSize(), firstComputedExpectedTab, 6));
    assert(compareTable(secondComputeVector.getCoordinate(), secondComputeVector.getVectorSize(), secondComputedExpectedTab, 6));
    assert(compareTable(thirdComputeVector.getCoordinate(), thirdComputeVector.getVectorSize(), thirdComputedExpectedTab, 6));
    assert(compareTable(fourthComputeVector.getCoordinate(), fourthComputeVector.getVectorSize(), fourthComputedExpectedTab, 4));

    // Changing the value of the first created vectors to test +=, -=, *=, /=
    
    firstVector += secondVector;
    secondVector -= thirdVector;
    thirdVector *= fourthVector;
    fourthVector /= firstVector;

    // Checking if the computation were correct.
    int firstFinalExpectedTab[] = {11, 22, 33, 44, 55, 60};
    int secondFinalExpectedTab[] = {5, 10, 15, 20, 50, 60};
    int thirdFinalExpectedTab[] = {10, 40, 90, 0};
    int fourthFinalExpectedTab[] = {0, 0, 0, 0, 0, 0};
    assert(compareTable(firstVector.getCoordinate(), firstVector.getVectorSize(), firstFinalExpectedTab, 6));
    assert(compareTable(secondVector.getCoordinate(), secondVector.getVectorSize(), secondFinalExpectedTab, 6));
    assert(compareTable(thirdVector.getCoordinate(), thirdVector.getVectorSize(), thirdFinalExpectedTab, 4));
    assert(compareTable(fourthVector.getCoordinate(), fourthVector.getVectorSize(), fourthFinalExpectedTab, 6));

    // Creating a new vector to test if the = overload worked properly.
    MyVector lastVector;
    lastVector = firstVector;

    // Displaying information to check if first and seven set have the same information
    // But with different addresses (deepcopy)

    cout << "Two vectors exists and should be the same (with different addresses). Let's check that:" << endl;

    cout << "Here are the information of the first Vector:" << endl;
    cout << &firstVector << endl;
    firstVector.displayElements();

    cout << "Here are the information of the copied (deep-copy) Vector:" << endl;
    cout << &lastVector << endl;
    lastVector.displayElements();

    // Checking if == and != worked properly.
    assert(firstVector == lastVector);
    assert(!(firstVector == secondVector));
    assert(!(firstVector == thirdVector));
    assert(!(firstVector == fourthVector));
    assert(!(firstVector == firstComputeVector));
    assert(!(firstVector == secondComputeVector));
    assert(!(firstVector == thirdComputeVector));
    assert(!(firstVector == fourthComputeVector));

    assert(!(firstVector != lastVector));
    assert(firstVector != secondVector);
    assert(firstVector != thirdVector);
    assert(firstVector != fourthVector);
    assert(firstVector != firstComputeVector);
    assert(firstVector != secondComputeVector);
    assert(firstVector != thirdComputeVector);
    assert(firstVector != fourthComputeVector);

    cout << "If this line is reached, it means that evrything worked properly !" << endl;
}

bool compareTable(int table1[], int size1, int table2[], int size2)
{
    if (size1 != size2)
        return false;
    
    for (int index = 0; index < size1; index++)
    {
        if (table1[index] != table2[index])
            return false;
    }
    return true;
}