#ifndef ELEMENT_FROM_SET_HPP_
#define ELEMENT_FROM_SET_HPP_

struct elementFromSet
{
	int currentValue;
	elementFromSet* pointerToPreviousValue;
	elementFromSet* pointerToNextValue;
};

#endif /* ELEMENT_FROM_SET_HPP_ */