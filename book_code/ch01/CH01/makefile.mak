TARGETS = Test_Clock.exe Test_Clockx.exe Test_Person.exe Test_Company.exe

CPPFLAGS = /Zi /EHsc /GR

all:	$(TARGETS)

Test_Clock.exe:	Test_Clock.obj Clock.obj
	cl $(CPPFLAGS) /Fe$@ $**

Test_Clockx.exe:	Test_Clockx.obj Clock.obj
	cl $(CPPFLAGS) /Fe$@ $**

Test_Person.exe:	Test_Person.obj Person.obj
	cl $(CPPFLAGS) /Fe$@ $**

Test_Company.exe:	Test_Company.obj Company.obj Person.obj
	cl $(CPPFLAGS) /Fe$@ $**

Test_Clock.obj:	Test_Clock.cpp Clock.h
	cl /c $(CPPFLAGS) Test_Clock.cpp

Clock.obj:	Clock.cpp Clock.h
	cl /c $(CPPFLAGS) Clock.cpp

Test_Clockx.obj:	Test_Clockx.cpp Clock.h
	cl /c $(CPPFLAGS) Test_Clockx.cpp

Test_Person.obj:	Test_Person.cpp Person.h
	cl /c $(CPPFLAGS) Test_Person.cpp 

Person.obj:	Person.cpp Person.h
	cl /c $(CPPFLAGS) Person.cpp

Test_Company.obj:	Test_Company.cpp Company.h Person.h
	cl /c $(CPPFLAGS) Test_Company.cpp

Company.obj:	Company.cpp Company.h
	cl /c $(CPPFLAGS) Company.cpp

clean:
	del *.exe
	del *.obj

