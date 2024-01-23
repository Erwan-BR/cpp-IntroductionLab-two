#include <array>
#include <iostream>
#include <vector>
#include "ElementFromSet.hpp"

using namespace std;

#ifndef SET_HPP_
#define SET_HPP_

class Set
{
private:
    elementFromSet* firstElement;
    elementFromSet* lastElement;
    int size;

public:
    Set(int initialValue);
    Set(Set* otherSet);
    Set();
    virtual ~Set();

    // Getter
    int getSize();

    // Functions from first lab
    bool checkIfContainsValue(int searchedValue);
    void addElement(int newValue);
    void deleteElement(int oldValue);
    void displayAllElements();
    int getIndexOfElement(int searchedValue);

    // Operators
    bool operator==(Set& otherSet);
    bool operator!=(Set& otherSet);
    void operator=(const Set& setToCopy);
};

#endif /* SET_HPP_ */