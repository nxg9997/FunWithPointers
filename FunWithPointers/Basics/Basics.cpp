// Basics.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>


int main()
{
	std::cout << "=== Basics of Pointers === " << std::endl << std::endl << "=== What is a Pointer? (And using the Stack) ===" << std::endl << std::endl;


	// Let's create some variables to hold information
	// Variables are allocated to memory on the stack when created
	int val1 = 0;

	// If we print out the value of val1, we should get "0" as expected
	std::cout << "Value of val1: " << val1 << std::endl;

	// Declare a pointer
	// You create a pointer by adding a * after the data type
	int* stackPtr;

	// Let's point our stackPtr at the var1 variable
	// The & gives us the memory address of a variable. This address "points" at a location in memory, thus we have a pointer that references val1
	stackPtr = &val1;

	// Next, we'll change the data that stackPtr is referencing
	// In addition to * being used to create a pointer, * is also used  to access the data it is pointing at. This is called "dereferencing"
	*stackPtr = 5;

	// If we print out the value of the derefernced pointer, we should see "5" in the output
	std::cout << "Dereferenced Stack Pointer: " << *stackPtr << std::endl;

	// If we print out the value of val1 again, we should see that it has changed to "5" as well, since we changed it by dereferencing stackPtr
	std::cout << "Value of val1: " << val1 << std::endl;

	// What happens if we forget to derefence stackPtr before printing it out?
	// We will simply print out the memory address that the pointer is pointing at, which is a Hexadecimal value
	std::cout << "Stack Pointer (Not Dereferenced): " << stackPtr << std::endl;


	std::cout << std::endl << "=== Memory Allocation & Heap Pointers ===" << std::endl << std::endl;
	// We've now gone over the basics of what a pointer is and how it works, but let's go a bit deeper
	// There are two parts of memory, the stack and the heap
	// The stack is where we store temporary data; when we leave scope, any data allocated on the stack can be overwritten. Pointers to stack memory are not super useful because of this
	// The heap is where we store data permanently. When we leave scope, the data stored on the heap is left unchanged, allowing us to access any data in the heap whenever we need it. Pointers to heap data are very useful for this reason; we can keep track of data from anywhere in the program
	// The above example is allocating data on the stack; val1 will leave scope when the main() function ends, and stackPtr will then point to useless data in memory

	// Let's make some data on the heap
	// Instead of creating an int, we are going to start by telling the program to allocate memory on the heap
	// We create a pointer just as we did before, but now we use the keyword "new" to tell the program we want to allocate memory on the heap for the pointer to reference
	int* heapPtr = new int();

	// We can dereference heapPtr and access the data the same way as before, using the * symbol
	// Since we never initiallized the value heapPtr is referencing, we end up printing garbage data from memory. Some compiliers may automatically initiallize the value of the int pointer to 0, but some don't, so keep that in mind
	std::cout << "Dereferenced heapPtr: " << *heapPtr << std::endl;

	// It's good practice to initiallize our data, so let's do that the same way we changed the value of val1 earlier using pointers
	*heapPtr = 10;

	// If we print it out again, we should see the value is "10" and not garbage
	std::cout << "Dereferenced heapPtr (Value Initiallized): " << *heapPtr << std::endl;

	// Using the heap is tricky, because we can run into issues if we forget to "deallocate" the memory we allocated
	// This is called a "memory leak", and memory leaks can persist even after a program exits. Since we never told the program to free the memory, we leave our data in memory permanently, preventing other programs from using it
	// A few leaks are not a big problem; leaving 4 bytes of memory behind won't cause your computer to crash, but lots of memory leaks can cause crashing and tons of other issues, so it's good practice to clean up our memory before exiting the program
	// We deallocate heap memory by using the "delete" keyword
	delete heapPtr;

	// If we try to print out the value of heapPtr now, we will get an error
	//std::cout << "Dereferenced heapPtr (After Delete): " << *heapPtr << std::endl;

	// Since we deallocated heapPtr, we should also set the pointer to the value of nullptr, so we don't run into issues/crashes later when trying to use heapPtr
	heapPtr = nullptr;



	std::cout << std::endl << "=== More About Pointers ===" << std::endl << std::endl;

	// Let's allocate another variable on the heap & initiallize its value
	int* heapInt = new int();
	*heapInt = 15;

	// We can set two pointers to point at the same location in memory
	int* intPtr = heapInt;

	// If we print out the derefenced pointers, we should get the same value
	std::cout << "Dereferenced heapInt: " << *heapInt << std::endl;
	std::cout << "Dereferenced intPtr: " << *intPtr << std::endl;

	// If we print out the pointers themselves, we can see that they point to the same location in memory
	std::cout << "Address of heapInt: " << heapInt << std::endl;
	std::cout << "Address of intPtr: " << intPtr << std::endl;

	// Since both pointers are referencing the same meory location, if we dereference one and change the value, the other pointer is also affected
	// Let's change the value of intPtr, and then print out the values of both pointers again
	*intPtr = 20;
	std::cout << "Dereferenced heapInt (Value Changed): " << *heapInt << std::endl;
	std::cout << "Dereferenced intPtr (Value Changed): " << *intPtr << std::endl;

	// Now, since we are done with the data we allocated on the heap, we should deallocate it
	// Remember, since both pointers point to the same data on the heap, if we deallocate one, the other pointer is also affected. Because of this, we only should use delete on one of the pointer, not both
	delete heapInt;

	// If we call delete on the other pointer, the program will throw an error
	//delete intPtr;

	// Let's end by setting both pointers to nullptr
	heapInt = nullptr;
	intPtr = nullptr;

    return 0;
}

