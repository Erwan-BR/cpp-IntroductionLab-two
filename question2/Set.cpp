#include "Set.hpp"

Set::Set(int initialValue) :
	size(1)
{
	elementFromSet* firstElementFromSet = new elementFromSet;
	firstElementFromSet->currentValue = initialValue;
	firstElementFromSet->pointerToPreviousValue = nullptr;
	firstElementFromSet->pointerToNextValue = nullptr;

	this->firstElement = firstElementFromSet;
	this->lastElement = firstElementFromSet;
}

Set::Set(Set* otherSet)
{
    // Init member to default value.
    this->firstElement = nullptr;
    this->lastElement = nullptr;
    this->size = 0;

    // Copying elements from the other set to the new one.
    elementFromSet* currentElementFromOtherSet = otherSet->firstElement;

    while (currentElementFromOtherSet != nullptr)
    {
        this->addElement(currentElementFromOtherSet->currentValue);
        currentElementFromOtherSet = currentElementFromOtherSet->pointerToNextValue;
    }
}

Set::Set() :
	firstElement(nullptr),
	lastElement(nullptr),
	size(0)
{
}

Set::~Set()
{
	// Getting the first element before iterating.
	elementFromSet* currentElement = this->firstElement;

	elementFromSet* nextElement = nullptr;

	// While the currentElement is not a null pointer, we have to delete this element.
	while (currentElement != nullptr)
	{
		// Retrieving the nextElement.
		nextElement = currentElement->pointerToNextValue;

		// Delete the currentElement which is useless now.
		delete currentElement;

		// Taking the next element to loop again (if needed).
		currentElement = nextElement;
	}
}

bool Set::operator==(Set& otherSet)
{
    // If both set size aren't equal, then sets are not the same.
    if (this->size != otherSet.getSize())
        return false;
    // If both are the same size and empty, then they are equal.
    else if (this->size == 0)
        return true;
    
    // If this line is reached, it means that they are the same size, and not empty.
    // We have to iterate on all element from this to check if they are on the other one.
    elementFromSet* currentElementFromSet = this->firstElement;

    // Looping while the element is not null.
    while (currentElementFromSet != nullptr)
    {
        // If this value is not on the other set, then sets are not equal.
        if (!otherSet.checkIfContainsValue(currentElementFromSet->currentValue))
            return false;
        
        // Retrieve the next element.
        currentElementFromSet = currentElementFromSet->pointerToNextValue;
    }
    // If this line is reached, it means that both set are equal.
    return true;
}

bool Set::operator!=(Set& otherSet)
{
    // If both set size aren't equal, then sets are not the same.
    if (this->size != otherSet.getSize())
        return true;
    // If both are the same size and empty, then they are equal.
    else if (this->size == 0)
        return false;
    
    // If this line is reached, it means that they are the same size, and not empty.
    // We have to iterate on all element from this to check if they are on the other one.
    elementFromSet* currentElementFromSet = this->firstElement;

    // Looping while the element is not null.
    while (currentElementFromSet != nullptr)
    {
        // If this value is not on the other set, then sets are not equal.
        if (!otherSet.checkIfContainsValue(currentElementFromSet->currentValue))
            return true;
        
        // Retrieve the next element.
        currentElementFromSet = currentElementFromSet->pointerToNextValue;
    }
    // If this line is reached, it means that both set are equal.
    return false;
}

void Set::operator=(const Set& setToCopy)
{
    // Init member to default value.
    this->firstElement = nullptr;
    this->lastElement = nullptr;
    this->size = 0;

    // Copying elements from the other set to the new one.
    elementFromSet* currentElementFromOtherSet = setToCopy.firstElement;

    while (currentElementFromOtherSet != nullptr)
    {
        this->addElement(currentElementFromOtherSet->currentValue);
        currentElementFromOtherSet = currentElementFromOtherSet->pointerToNextValue;
    }
}

int Set::getSize()
{
	return this->size;
}

bool Set::checkIfContainsValue(int searchedValue)
{
	// Using the default value of getIndex to avoid repetiting code.
	return this->getIndexOfElement(searchedValue) != -1;
}

void Set::addElement(int newValue)
{
	// We had an element only if this is not already in the set.
	if (!this->checkIfContainsValue(newValue))
	{
		// Instantiation of the new element.
		elementFromSet* newElement = new elementFromSet;
		newElement->currentValue = newValue;
		newElement->pointerToPreviousValue = this->lastElement;
		newElement->pointerToNextValue = nullptr;

		// If the firstElement is null : the list was empty. This is not the case anymore.
		if (this->firstElement == nullptr)
			this->firstElement = newElement;
		// If the firstElement is not null : the elemenbt which was the last before adding is not the last one anymore.
		else
			this->lastElement->pointerToNextValue = newElement;

		// Setting the new last element
		this->lastElement = newElement;

		// When adding a new element, the size increase by one.
		this->size++;
	}
}

void Set::deleteElement(int oldValue)
{
	int indexElementToDelete = this->getIndexOfElement(oldValue);
	// We have to delete an element only if this element is on the chained list.

	// First case : the element to delete is the first one.
	if (indexElementToDelete==0)
	{
		// First case : there is no others value in the chained list.
		if (this->size==1)
		{
			// Setting the first and last pointer to null.
			this->firstElement = nullptr;
			this->lastElement = nullptr;

			// Now the size is null because there is no value i the chained list.
			this->size = 0;
		}
		// Second case : there is some others elements in the chained list.
		else
		{
			// Retrieve the information concerning the first ahnd the second element
			elementFromSet* elementToDelete = this->firstElement;
			elementFromSet* newFirstElement = elementToDelete->pointerToNextValue;

			// The new first element must point to nothing before.
			newFirstElement->pointerToPreviousValue = nullptr;
			this->firstElement = newFirstElement;

			// Delete the element to free memory.
			delete elementToDelete;
			this->size--;
		}
	}
	// Second case : the element to delete is the last one. Ir cannot be the only, otherwise it would have be in the previous case (index=0, size=1
	else if (indexElementToDelete == this->size - 1)
	{
		elementFromSet* elementToDelete = this->lastElement;
		elementFromSet* newLastElement = elementToDelete->pointerToPreviousValue;
		newLastElement->pointerToNextValue = nullptr;
		this->lastElement = newLastElement;

		delete elementToDelete;
		this->size -= 1;
	}

	else if (indexElementToDelete != -1)
	{
		elementFromSet* currentElement = this->firstElement->pointerToNextValue;

		// We have to go to the right index to get the value.
		for (int index = 1; index < indexElementToDelete; index++)
		{
			currentElement = currentElement->pointerToNextValue;
		}
		// Now, the currentElement is the element to delete. We have to update the information of the previous and the next one.
		currentElement->pointerToPreviousValue->pointerToNextValue = currentElement->pointerToNextValue;
		currentElement->pointerToNextValue->pointerToPreviousValue = currentElement->pointerToPreviousValue;

		// Delete the useless structure to free memory.
		delete currentElement;
		this->size--;
	}
}

void Set::displayAllElements()
{
	// If the chained list is empty, we display the information to the user.
	if (this->size == 0)
		cout << "There is nothing to display !" << endl;
	else
	{
		// Index to know the position easily.
		int index = 0;

		// currentElementFromSet is used to loop.

		elementFromSet* currentElementFromSet = this->firstElement;

		// Looping while the element is not null.
		while (currentElementFromSet != nullptr)
		{
			// Printing some information in the terminal.
			cout << "Element n°" << index << ". Current value: " << currentElementFromSet->currentValue << "\tPrevious address: " ;
			cout << currentElementFromSet->pointerToPreviousValue << "\tCurrent address: " << currentElementFromSet << "\tNext Address: " << currentElementFromSet->pointerToNextValue << endl;

			// Retrieve the next element.
			currentElementFromSet = currentElementFromSet->pointerToNextValue;

			// Update the index.
			index++;
		}
	}
	cout << endl;
}

int Set::getIndexOfElement(int searchedValue)
{
	// The return value is -1 if the value is not in the chained list.
	int defaultValue = -1;

	// If there are some elements in the list, we will have to iterate from the first element to the last one.
	if (this->size != 0)
	{
		int indexOfCurrentPosition = 0;

		// Getting the informations from the first element
		elementFromSet* currentElementFromSet = this->firstElement;

		while (currentElementFromSet != nullptr)
		{
			if (currentElementFromSet->currentValue == searchedValue)
				return indexOfCurrentPosition;
			indexOfCurrentPosition++;
			currentElementFromSet = currentElementFromSet->pointerToNextValue;
		}
	}
	return defaultValue;
}
