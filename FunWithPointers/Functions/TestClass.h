#pragma once
#include <iostream>
class TestClass
{
public:
	TestClass();
	~TestClass();

	// We define our typedef in our TestClass header file
	// Normally we would want to only define our typedef once, probably in a header file present in all files to keep our code easier to read
	// In this case however, we defined it in both main() and here since we are just going over the basic concepts of function pointers
	typedef int(*Math)(int a, int b);

	// MoreMath() will take a function pointer to one of our math functions, and then print the result
	void MoreMath(Math math);

	// PrintStuff() will print out a line of text to the console
	// We set it to static so it can be accessed from outside of a class object
	static void PrintStuff();

};

