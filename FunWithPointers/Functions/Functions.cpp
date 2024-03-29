// Functions.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "TestClass.h"

int Add(int a, int b);
int Subtract(int a, int b);
int Divide(int a, int b);
int Multiply(int a, int b);

int main()
{
    std::cout << "=== Function Pointers ===" << std::endl << std::endl;

	// In all the other demos we've done, we have only been using pointers with various data types & classes
	// But you can actually use pointers to reference functions
	// If you are familiar with JavaScript, this will look very similar to how we use callbacks and/or closures
	// I've created functions called Add(), Subtract(), Divide(), and Multiply(), which we will be using to demonstrate Function Pointers
	// Each function takes two ints as parameters, and returns the resulting int value
	// The first step in creating function pointers is a little strange; we actually have to define our own data type using the keyword "typedef"
	// The syntax for a typedef is a little confusing, so let's break it down
	//      -V- This "int" is just the return type of the data type we are defining
	//           -V- This second part is the name of the data type. We are also defining the data type to be a pointer by using the "*"
	//                     -V- Finally, we have the parameters the data type will take in
	typedef int(*Math)(int a, int b);

	// We can see how this works by creating a variable of the "Math" data type
	// Let's use the Add() function first
	// We can declare the variable like any other data type, such as an int, and we set it equal to the name of the function we are trying to point to
	// Just writing the name of the function, in this case "Add" just returns the address of the function, basically causing it to act as a pointer to the function
	Math add = Add; // We can also say "Math add = &Add;" - the "&" will also give us the address of the function

	// We can call Add() using the "add" variable just like it was the function itself
	// We'll also print out the result to the console
	std::cout << "Result of add(5, 6): " << add(5, 6) << std::endl;

	// We can see that we get the answer "11", which is what we expected
	// Now, it probably seems a little useless to make a function pointer if we can just call Add() by itself
	// So let's look at why we might want to use function pointers
	// We have a bunch of functions that all take two int values as parameters and each function returns an int, so we can set a "Math" variable to be any of these functions
	// Let's say we want our user to be able to select which math operation they want to call
	// First, we'll take user input to determine the operation to call
	char operation = ' ';
	std::cout << "Select a Math Operation to Call (+,-,/,*): ";
	std::cin >> operation;

	// Now that we have the operation the user wants to call, we should go ahead and call it
	// To start, we will create a single "Math" variable
	// We will set it to nullptr just in case the user enters input we aren't expecting
	Math doMath = nullptr;

	// Now, we can just use an if-else statement or a switch statement to determine the operation the user wants to call
	// We will just set "doMath" equal to the address of the function we want to call
	if (operation == '+') {
		doMath = Add;
	}
	else if (operation == '-') {
		doMath = Subtract;
	}
	else if (operation == '/') {
		doMath = Divide;
	}
	else if (operation == '*') {
		doMath = Multiply;
	}

	// We should now have "doMath" set to the correct operation
	// But we should also check to see if "doMath" is equal to nullptr before we call the function
	if (doMath != nullptr) {
		std::cout << "Result of doMath(6, 3): " << doMath(6, 3) << std::endl;
	}
	else {
		std::cout << "doMath is nullptr!" << std::endl;
	}

	// Everything should be working correctly!
	// But we come back to our question from before: "Why is this useful if I can just call the functions normally?"
	// Well, we could pass these references into other classes and functions!
	// I created a class called "TestClass", which also has our typedef "Math", and a function called MoreMath(), which takes a Math variable as a parameter
	// Let's go ahead and make a TestClass object
	TestClass testClass;

	// And just like before, let's see what operation the user wants to call
	// We can just reuse our "operation" variable from earlier
	std::cout << "Select an Operation to Use in TestClass (+,-,*,/): ";
	std::cin >> operation;

	// Again like before, we can use a Math variable to store the pointer for the function we want to call
	Math testMath = nullptr;
	if (operation == '+') {
		testMath = Add;
	}
	else if (operation == '-') {
		testMath = Subtract;
	}
	else if (operation == '/') {
		testMath = Divide;
	}
	else if (operation == '*') {
		testMath = Multiply;
	}

	// Now that we have that, let's pass our function pointer into MoreMath() in our TestClass object
	// Like before, we will check to make sure the function pointer isn't nullptr
	if (testMath != nullptr) {
		testClass.MoreMath(testMath);
	}
	else {
		std::cout << "testMath is nullptr!" << std::endl;
	}

	// Function pointers should be looking a little bit more useful now!
	// But we can do even more!
	// Now we're going to get a little crazy, so get ready!
	// We can also use function pointers to refer to functions from OTHER classes as well
	// Let's make a typedef that matches the function signature of our other function, PrintStuff(), from TestClass
	typedef void(*OtherClassFunc)();

	// Now, we will go ahead and make a OtherClassFunc variable and set it to point at PrintStuff()
	OtherClassFunc print = TestClass::PrintStuff;

	// If we call print, we will see that we successfully called the function from the other class
	print();

	// As we can see, it printed out a line to the console!
	// I recommend taking a look at the "TestClass.h" and "TestClass.cpp" files to get a better idea of how everything works
	// Function pointers can be a little confusing, but with practice they can be a very useful tool when writing complex code
}

int Add(int a, int b)
{
	return a + b;
}

int Subtract(int a, int b)
{
	return a - b;
}

int Divide(int a, int b)
{
	return a / b;
}

int Multiply(int a, int b)
{
	return a * b;
}
