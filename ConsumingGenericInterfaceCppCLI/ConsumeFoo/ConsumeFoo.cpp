// ConsumeFoo.cpp : main project file.

#include "stdafx.h"

using namespace System;
using namespace GenericSelfConsumingInterface;

// Does not compile because Foo is a type and only allowed are value types and reference, but i was so into c# that i didn't read the following sites right
public ref class Foo : public IFoo<Foo>
{
public:
	void Bar(Foo^ data) override
	{

	}
};

public ref class Foo : public IFoo<Foo^>
{
	
public :
	void Bar(Foo^ data) override
	{
		
	}
};

int main(array<System::String ^> ^args)
{
    Console::WriteLine(L"Hello World");
    return 0;
}
