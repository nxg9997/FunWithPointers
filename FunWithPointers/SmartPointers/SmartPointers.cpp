// SmartPointers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "SmartInt.h"

#include <memory>
#include <string>

int main()
{
	std::cout << "=== Smart Pointers ===" << std::endl << std::endl;

	// In other demos, we have had to worry about remembering to clean up our memory after allocating memory on the heap.
	// But what if there was a way for us to allocate memory without worrying too much about memory management?
	// Well, there is a way!
	// We can use a class to encapsulate the pointer for us, so when the class object goes out of scope, it will automatically clean up the pointer in the destructor.

	// I've made a class called "SmartInt", so let's head over to the class to see what's going on inside.

	// Now that we've taken a look at what SmartInt is doing under the hood, let's actually see it in practice.
	// So let's create an instance of a SmartInt object.
	SmartInt smartPtr(new int(10));

	// Now we have an SmartInt object that stores a reference to a new int that we allocated on the heap, and th value of that int should be 10.
	// If we dereference smartPtr, we should be able to see that the value of the int is actually 10.
	std::cout << "Value of smartInt: " << *smartPtr << std::endl;

	// If we were to end the program here, smartPtr will be moved out of scope, and it will automatically call the destructor.
	// Inside the destructor, I wrote a line to print out the value of the pointer so you can see when it goes out of scope.
	// It should print out a memory address of all 0's, which is the value of nullptr, meaning we successfully cleaned up our memory.

	// Our SmartInt class is great and all, but it only works for int pointers, and nothing else.
	// If we wanted to use it for other data types, we would have to create a new class for each data type we are trying to use.
	// This is hastle, and not worth our time.
	// Thankfully, we have template classes to solve this.
	// We could change our SmartInt class to be a template class, but cpp already ships with a library we can use for smart pointers.
	// If we say #include <memory> at the beginning of our code, we get a whole bunch of useful functions and classes for memory management.

	// In memory, there are two very useful types of smart pointers.
	// First, we have "unique_ptr"s.
	// unique_ptr's are a type of smart pointer that will only allow 1 smart pointer to hold a reference to a given pointer.
	// So let's create one.
	//               -V- Since unique_ptr is a template class, we have to provide it with the data type that we want it to contain. Otherwise the syntax should look familiar! 
	std::unique_ptr<char> uniqueChar(new char('X'));

	// We now have a unique_ptr that is storing a char; specifically an 'X'.
	// If we look at the value inside the unique_ptr, we can see that everything is working correctly.
	std::cout << "unique_ptr Value: " << *uniqueChar << std::endl;

	// The other useful smart pointer we have access to is a "shared_ptr".
	// This type of smart pointer keeps track of how many other shared_ptr's hold a reference to the same pointee, and will only clean up memory once every shared_ptr leaves scope.
	// Let's make one real quick, but his time let's give it a reference to a class so we can see the -> operator being used.
	std::shared_ptr<std::string> sharedStr(new std::string("Smart"));

	// This time we passed a std::string in as the class, and set it's value to "Smart".
	// If we print it out, we can see that it worked correctly.
	std::cout << "shared_ptr Value: " << *sharedStr << std::endl;

	// We can also call functions that are within the std::string class, so let's give it a shot.
	// We'll just simply print out the size of the string to see if it works.
	std::cout << "Length of sharedStr: " << sharedStr->size() << std::endl;

	// It prints out 5, which is the length of the sharedStr!
	// Now, just as before, if we leave our main() function, both our unique_ptr, and our shared_ptr, will be moved out of scope, and the memory will be cleaned up.
	// One thing to note about smart pointers is that they are slower than regular pointers, but for most use cases, speed won't an issue, and you can just use smart pointers to make sure you aren't forgetting to clean up memory.
}
