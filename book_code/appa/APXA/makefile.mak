All:	Test_Employee Test_Student Test_Address Test_Student_Worker

Test_Student_Worker:	Test_Student_Worker.obj StudentWorker.obj US_Address.obj German_Address.obj Person.obj
	cl /EHsc    /FeTest_Student_Worker Test_Student_Worker.obj StudentWorker.obj US_Address.obj German_Address.obj Person.obj

Test_Employee:	Test_Employee.obj Employee.obj US_Address.obj German_Address.obj Person.obj
	cl /EHsc    /FeTest_Employee Test_Employee.obj Employee.obj US_Address.obj German_Address.obj Person.obj

Test_Student:	Test_Student.obj Student.obj US_Address.obj German_Address.obj Person.obj
	cl /EHsc    /FeTest_Student Test_Student.obj Student.obj US_Address.obj German_Address.obj Person.obj

Test_Address:	Test_Address.obj US_Address.obj German_Address.obj
	cl /EHsc    /FeTest_Address Test_Address.obj US_Address.obj German_Address.obj

Test_Address.obj:	Test_Address.cpp Address.h
	cl /EHsc    /c Test_Address.cpp

US_Address.obj:	US_Address.cpp Address.h
	cl /EHsc    /c US_Address.cpp

German_Address.obj:	German_Address.cpp Address.h
	cl /EHsc    /c German_Address.cpp

Employee.obj:	Employee.cpp Employee.h Address.h Person.h
	cl /EHsc    /c Employee.cpp

Student.obj:	Student.cpp Student.h Address.h Person.h
	cl /EHsc    /c Student.cpp

Test_Student.obj:	Test_Student.cpp Student.h Address.h Person.h
	cl /EHsc    /c Test_Student.cpp

Test_Employee.obj: Test_Employee.cpp Employee.h Address.h Person.h
	cl /EHsc    /c Test_Employee.cpp

StudentWorker.obj:	StudentWorker.cpp Student.h Employee.h StudentWorker.h Address.h Person.h
	cl /EHsc    /c StudentWorker.cpp

Person.obj:	Person.cpp Person.h
	cl /EHsc    /c Person.cpp

Test_Student_Worker.obj:	Test_Student_Worker.cpp Student.h Employee.h StudentWorker.h Address.h Person.h
	cl /EHsc /c Test_Student_Worker.cpp
