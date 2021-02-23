all:	Test_Address 

CPPFLAGS = /Zi /EHsc /GR
CC	= cl

Test_Address:	Test_Address.obj US_Address.obj German_Address.obj
	$(CC) $(CPPFLAGS) -Fe$@ $**

Test_Address.obj:	Test_Address.cpp Address.h
	$(CC) $(CPPFLAGS) /c Test_Address.cpp

US_Address.obj:	US_Address.cpp Address.h
	$(CC) $(CPPFLAGS) /c US_Address.cpp$<

German_Address.obj:	German_Address.cpp Address.h
	$(CC) $(CPPFLAGS) /c German_Address.cpp

clean:
	del *.obj
	del *.exe
	del *.pdb
	del *.ilk
