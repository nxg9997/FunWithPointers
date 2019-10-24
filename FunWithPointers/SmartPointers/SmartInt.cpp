#include "pch.h"
#include "SmartInt.h"

// In our constructor, we are simply setting the private ptr to the new pointer we are passing in.
SmartInt::SmartInt(int * _ptr)
{
	ptr = _ptr;
}

// In our destructor, we are cleaning up the memory allocated. When the SmartInt object moves out of scope, the destructor will be called, automatically cleaning up our memory for us.
// It will also print out a line to let us know that the destructor was called, along with the value of ptr so we know if it was successfully deleted or not.
SmartInt::~SmartInt()
{
	delete ptr;
	ptr = nullptr;
	std::cout << "In SmartInt Destructor, Value of ptr: " << ptr << std::endl;
}

// In our operator overload, we will return a reference to the actual int value we allocated.
int& SmartInt::operator*()
{
	return *ptr;
}
