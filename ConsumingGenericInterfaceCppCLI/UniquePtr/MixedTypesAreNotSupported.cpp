// Mixed Types are not Supported.cpp : main project file.

#include "stdafx.h"

#pragma unmanaged
#include <memory>
#pragma managed

using namespace System;



template< class fooRef>
public class foo
{
public:
	foo()
	{
		Console::WriteLine("foo created")
	}

	typedef void(__stdcall *function)(fooRef * data);

	function run = nullptr;
};


///
/// Typical Sideline story, you are thinking c++ with templates and so on but as a member of managed class mixed types are not supported.
/// Which means, any class or struct cannot be held like a value type within the context of the class.
//

template<class barRef>
public ref class bar
{
public:
	bar()
	{
		Console::WriteLine("bar created")
		LifeTimeRef = std::make_unique<foo<barRef>>();
	}

	foo<barRef> LifeTimeRef;

	void run(barRef * data)
	{
		
	}
};


int main(array<System::String ^> ^args)
{
    Console::WriteLine(L"Hello World");

	bar<int>^ test = gcnew bar<int>();

    return 0;
}
