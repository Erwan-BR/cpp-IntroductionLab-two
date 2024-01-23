#include "mainQuestion2.hpp"

void mainQuestion2()
{
	// Instantiation of the first set used to test == and != operators.
	Set firstSet = Set(10);
	firstSet.addElement(5);
	firstSet.addElement(8);
	firstSet.addElement(7);

    // Instantiation of a second set, equal to the first one.
	Set secondSet = Set(7);
	secondSet.addElement(10);
	secondSet.addElement(5);
	secondSet.addElement(8);

    // Instanciation of a third set which do not contains the 8.
    Set thirdSet = Set(7);
    thirdSet.addElement(10);
	thirdSet.addElement(5);

    // Instanciation of a fourth set which contains a 4.
    Set fourthSet = Set(7);
    fourthSet.addElement(8);
    fourthSet.addElement(5);
	fourthSet.addElement(10);
    fourthSet.addElement(4);

    // Creating an empty set to check if two empty set are equals.
    Set fifthSet = Set();

    // Creating a second empty set to check if two empty set are equals.
    Set sixthSet = Set();

    // Creating a seventh set to check if the = override worked properly.
    Set seventhSet ;
    seventhSet = firstSet;

    // Displaying information to check if first and seven set have the same information
    // But with different addresses (deepcopy)

    cout << "Two sets exists and should be the same (with different addresses). Let's check that:" << endl;

    cout << "Here are the information of the first Set:" << endl;
    cout << &firstSet << endl;
    firstSet.displayAllElements();

    cout << "Here are the information of the seventh Set:" << endl;
    cout << &seventhSet << endl;
    seventhSet.displayAllElements();

    // Checking if == works properly.
    assert(firstSet == secondSet);
    assert(!(secondSet == thirdSet));
    assert(!(secondSet == fourthSet));
    assert(!(secondSet == fifthSet));
    assert(!(secondSet == sixthSet));
    assert(fifthSet == sixthSet);
    assert(firstSet == seventhSet);
    
    // Checking if != works properly.
    assert(!(firstSet != secondSet));
    assert(secondSet != thirdSet);
    assert(secondSet != fourthSet);
    assert(secondSet != fifthSet);
    assert(secondSet != sixthSet);
    assert(!(fifthSet != sixthSet));
    assert(!(firstSet != seventhSet));

    cout << "If this line is reached, it means that all asserts worked !" << endl;
}