// StackVsHeap.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

int* StackPointers();
int* HeapPointers();

int main()
{
	std::cout << "=== Stack vs Heap ===" << std::endl << std::endl;

	// In Basics we went over briefly how the stack and the heap work, and how pointers work in conjunction with that
	// Now, we can go over in more detail the difference between the stack and the heap
	// I've went ahead and created two functions, StackPointers() and HeapPointers()
	// Both functions return the pointer to an int, which we will come back to later
	// For now, we can start by taking a look at the HeapPointers() function
	// We will also be creating a pointer to store the address returned from the function
	int* heapPtr = HeapPointers();

	// Now that we've returned from HeapPointers(), let's try and look at the data we allocated from within the function
	std::cout << "HeapPointers() data (Outside HeapPointers()): " << *heapPtr << std::endl;

	// As you can see, the data is still the same whether we are inside the function where we allocated memory on the heap or not
	// Let's see how that differs from if we were to allocate memory on the stack instead
	// For that, we will go into the StackPointers() function
	// Like before, we will store the int pointer returned from the function
	int* stackPtr = StackPointers();

	// Now that we've returned from StackPointers(), let's try and look at the data we allocated from within the function
	std::cout << "StackPointers() data (Outside StackPointers()): " << *stackPtr << std::endl;

	// Looks good, right?
	// The problem with this is the data can be overwritten since we allocated it on the stack, and then we left the scope of the function
	// Let's make a bunch of useless data on the stack, and then try and print out the data from stackPtr again
	for (int i = 0; i < 1000; i++)
	{
		int randomData = i;
	}

	// The data should be overwritten now, so let's take another look at stackPtr
	std::cout << "StackPointers() data (Outside StackPointers(), after overwritting the stack): " << *stackPtr << std::endl;

	// As you can see, the data referenced by stackPtr is completely useless now that it has been overwritten
	// Be careful when passing pointers around from functions so you can avoid this; you don't want important data to be overwritten by accident because it was allocated wrong
	// We'll also print out the heapPtr again, so you can see that it is still unchanged
	std::cout << "HeapPointers() data (Outside HeapPointers(), after overwritting the stack): " << *heapPtr << std::endl;

	// There's not much else to do here, so we can go and free up the memory we allocated
	// We only have to deallocate the data on the heap, since the stack is automatically cleaned up for us
	delete heapPtr;


    return 0;
}

int* StackPointers()
{
	// Let's go ahead an allocate memory on the stack
	// We don't need to create a pointer to do this, since we aren't allocating to the heap
	// We'll set this data to "55" so we can remember it later
	int data = 55;

	// We'll also print out the data like we did in HeapPointers() to see how it looks from within the function
	std::cout << "StackPointers() data (Inside StackPointers()): " << data << std::endl;

	// In order to return a pointer to the data we created, we get the address of the data using the & symbol
	return &data;
}

int* HeapPointers()
{
	// Inside HeapPointers(), let's allocate an int onto the heap
	int* data = new int();

	// Let's also set the value of data to something, we'll go with "77"
	*data = 77;

	// Just so we can see how the data looks right now, let's go ahead and print it out
	std::cout << "HeapPointers() data (Inside HeapPointers()): " << *data << std::endl;

	// There isn't much else to do here, so we can leave the function
	// We are going to return the pointer to the data, however
	// Since we allocated data on the heap, we should be able to access this data from outside this function as long as we have the reference to it
	return data;
}