// AssemblyExplorerCrashOnDissembleyOfEventProperty.cpp : main project file.

#include "stdafx.h"

using namespace System;

void OnDataEventHandler(System::Object ^sender, System::String ^e);
namespace SureImportantToProblem::ButAintNoProblemToBeLongOrLonger::EvenLevelsShouldBeEnough::OrYouWouldNotice
{
		generic<class fooData>
		public interface class foo
		{
		public:
			event EventHandler<fooData>^ DataEventHandler;
		};

		generic<class fooData>
		public ref class barGeneric : public foo<fooData>
		{
		public:
			virtual event EventHandler<fooData>^ DataEventHandler;

			void fireEvent(fooData message)
			{
				DataEventHandler(this, message);
			}
		};

		template<class fooData, class UnmanageBarFuba>
		public ref class barTemplate : public foo<fooData>
		{
		public:
			virtual event EventHandler<fooData>^ DataEventHandler;

			void fireEvent(fooData message)
			{
				DataEventHandler(this, message);
			}

			void fireUnmanageEvent( UnmanageBarFuba barFuba)
			{
				
			}
		};

}

using namespace SureImportantToProblem::ButAintNoProblemToBeLongOrLonger::EvenLevelsShouldBeEnough::OrYouWouldNotice;

int main(array<System::String ^> ^args)
{
	auto testGeneric  = gcnew barGeneric<String^>;
	auto testTemplate = gcnew barTemplate<String^, wchar_t*>;

	testGeneric->DataEventHandler += gcnew System::EventHandler<System::String ^>(&OnDataEventHandler);
	testGeneric->fireEvent(gcnew String(L"A"));

	testGeneric->DataEventHandler += gcnew System::EventHandler<System::String ^>(&OnDataEventHandler);
	testGeneric->fireEvent(gcnew String(L"B"));
	testGeneric->DataEventHandler -= gcnew System::EventHandler<System::String ^>(&OnDataEventHandler); // uff working but ... jeah ;) .NET is working for me 
	testGeneric->fireEvent(gcnew String(L"C"));
	
	testTemplate->DataEventHandler += gcnew System::EventHandler<System::String ^>(&OnDataEventHandler);
	testTemplate->fireEvent(gcnew String(L"A"));

	testTemplate->DataEventHandler += gcnew System::EventHandler<System::String ^>(&OnDataEventHandler);
	testTemplate->fireEvent(gcnew String(L"B"));
	testTemplate->DataEventHandler -= gcnew System::EventHandler<System::String ^>(&OnDataEventHandler); // uff working but ... jeah ;) .NET is working for me 
	testTemplate->fireEvent(gcnew String(L"C"));


    return 0;
}

void OnDataEventHandler(System::Object ^sender, System::String ^e)
{
	Console::WriteLine(e);
}
