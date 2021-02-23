CPPFLAGS = /Zi /EHsc /GR
all:	PD_Application.exe

PD_Application.exe:	PD_Application.obj array_based_PD.obj
	cl $(CPPFLAGS) /Fe$@ $**

PD_Application.obj:	PD_application.cpp array_based_PD.h
	cl $(CPPFLAGS) -DUSEARRAY /c PD_application.cpp

array_based_PD.obj:	array_based_PD.cpp array_based_PD.h
	cl $(CPPFLAGS) /c array_based_PD.cpp

clean:
	del *.exe
	del *.obj
