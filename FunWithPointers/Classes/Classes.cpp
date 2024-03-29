// Classes.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "TestClass.h"

int main()
{
	std::cout << "=== Classes ===" << std::endl << std::endl;

	// We've gone over mostly pointers to standard data types, such as ints, but you can use pointers to reference any data type
	// I've created a new class called TestClass, you can check out the source files for it, but there won't be any important/new information in there
	// There's a function in TestClass called "HelloWorld" that simply prints out "Hello World", and an int called "data", which is initialized to "5" in the constructor
	// First, let's create a regular object of TestClass
	TestClass test;

	// As always, we can call functions and access properties from a class object
	test.HelloWorld();
	std::cout << "Data from TestClass: " << test.data << std::endl;

	// We can also create a pointer to a class object
	TestClass* classPtr = &test;

	// We can call functions and access properties by either dereferencing the pointer as we've done before, but we can also directly access these from the pointer itself
	// Here's how we would access the above through dereferencing
	(*classPtr).HelloWorld();
	std::cout << "Data from TestClass (Using a Dereferenced Pointer): " << (*classPtr).data << std::endl;

	// But sometimes it's easier to access functions and properties directly
	// We use a new symbol, "->" to do just this
	classPtr->HelloWorld();
	std::cout << "Data from TestClass (Using a Pointer Directly): " << classPtr->data << std::endl;

	// Just as with other demos, we should clean up any memory we allocated
	// In this case, we never allocated any memory on the heap, so we don't have to worry about it - we can just exit the program
	// Also, everything we have done in other demos with pointers can be applied to class pointers. We just have to remember we have the new "->" symbol when working with class pointers

    return 0;
}

