#include "pch.h"
#include "TestClass.h"


TestClass::TestClass()
{
}


TestClass::~TestClass()
{
}

void TestClass::MoreMath(Math math)
{
	// Just like in main(), we just call the function pointer to access the function we are pointing at
	std::cout << "Result from MoreMath (12, 4): " << math(12, 4) << std::endl;
}

void TestClass::PrintStuff()
{
	std::cout << "Hi from inside PrintStuff()!" << std::endl;
}
