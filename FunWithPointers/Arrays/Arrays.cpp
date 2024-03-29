// Arrays.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>


int main()
{
	std::cout << "=== Pointers & Arrays ===" << std::endl << std::endl;

	// Let's start by creating a basic array and initiallizing all the values
	int arr[5] = { 10, 20, 30, 40, 50 };

	// Now we'll print out the values of the array to make sure everything looks good
	// Remember that arrays do not keep track of their size in C++
	for (int i = 0; i < 5; i++)
	{
		std::cout << "Value at Index " << i << ": " << arr[i] << std::endl;
	}

	// Everything looks good, so let's start talking about pointers
	// Let's create a pointer and have it reference the array
	// Arrays do not need the & symbol to get their address because an array is really just a pointer under the hood
	int* arrPtr = arr;

	// If we dereference arrPtr we will get the value at index 0
	std::cout << "Derefenced arrPtr: " << *arrPtr << std::endl;

	// We can see the values of other indexes in the array by using pointer arithmetic
	// Using ++ on a pointer will shift where it is pointing forward by the size of the data type it is pointing to; an int pointer will shift over 4 bytes (the size of an int)
	// Using -- will shift the pointer the same amount to the left
	// Let's use our arrPtr to print out the values in our array
	for (int i = 0; i < 5; i++)
	{
		std::cout << "Value at Index " << i << " (Using Pointers): " << *arrPtr << std::endl;
		arrPtr++;
	}

	// Let's also print the values in reverse
	// Our pointer is actually pointing at the memory location right past the last index of our array, so let's move it back 1 position to put it back in bounds of our array
	arrPtr--;

	// Our pointer is now pointing at the last index in our array, so we can just use -- to move it back to the start
	std::cout << "Reverse Print" << std::endl;
	for (int i = 4; i >= 0; i--)
	{
		std::cout << "Value at Index " << i << " (Using Pointers): " << *arrPtr << std::endl;
		arrPtr--;
	}



	// Now that we know some basics of array pointers, we can go deeper
	// Let's look at how we can create a 2D array on the heap
	// We are combining both heap memory allocation and multidimentional arrays here, but it should make sense once we start doing it
	// We start by creating a pointer that points to a pointer, and allocating data onto the heap
	// This first step will allocate enough memory to create an array of pointers
	// We can create an array on the heap by using the "new" keyword, followed by the amount of data to allocate. In this case, 5 int pointers
	int** multiArr = new int*[5];

	// In a loop, we can go ahead and allocate memory for all of the pointers we created above
	// Right now, we have a single, 1D array of pointers that don't point to anything
	// We will go ahead and tell each pointer to point at an array of int values
	for (int i = 0; i < 5; i++)
	{
		multiArr[i] = new int[5];
	}

	// Now we have a 2D array of int values
	// The only problem is we haven't initiallized the data yet
	// We'll just go through and give each index a unique value
	// You can access array indexes the same way you would in other languages, using [][] notation
	int index = 0;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			multiArr[i][j] = index++;
		}
	}

	// Now we can go through and print the values of the array to make sure it worked
	std::cout << "2D Array:" << std::endl;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			std::cout << multiArr[i][j] << " ";
		}
		std::cout << std::endl;
	}

	// Everything printed out as expected
	// Since we're done with the array, we have to clean up our memory
	// We allocated a lot of memory, so let's clean it up step by step
	// A good rule of thumb is to deallocate memory in the reverse direction that it was created in when dealing with multi-dimentional arrays
	// We start by deallocating all the arrays that are being pointed to by the original 1D array
	// If we allocate using [] instead of (), we use the keyword "delete" followed by "[]"
	for (int i = 0; i < 5; i++)
	{
		delete[] multiArr[i];
	}

	// Now we can deallocate the original array
	delete[] multiArr;

    return 0;
}

