#pragma once
#include <iostream>

// Here's the header file for our SmartInt class, I've defined a couple of functions that will be useful to us in the class itself.
class SmartInt
{
public:
	// First we have our constructor, which will take a pointer to a int.
	SmartInt(int* _ptr);

	// Next, we have our destructor, which doesn't take any parameters
	~SmartInt();

	// Finally, we have an operator overload.
	// We want our * operator to give us a reference to the int value we are storing.
	int& operator*();

private:

	// We also have the pointer itself, we leave it private so that we can't mess with the pointer without using the above functions.
	int* ptr;
};

