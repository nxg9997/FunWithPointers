#include "stdafx.h"
#include "TestClass.h"


TestClass::TestClass()
{
	data = 5;
}


TestClass::~TestClass()
{
}

void TestClass::HelloWorld()
{
	std::cout << "Hello World" << std::endl;
}
