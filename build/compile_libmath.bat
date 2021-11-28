@ECHO OFF
@cls
rem del *.obj *.pdb *.ilk *.exe

cl /nologo /Zi /EHs /MDd /W4 -D_CRT_SECURE_NO_WARNINGS -I ..\unit_test\include\ -I ..\include\lib_math\ /c ..\unit_test\src\MatrixTest.cpp
cl /nologo /Zi /EHs /MDd /W4 -D_CRT_SECURE_NO_WARNINGS -I ..\unit_test\include\ -I ..\include\lib_math\  /c ..\unit_test\src\VectorTest.cpp
cl /nologo /Zi /EHs /MDd /W4 -D_CRT_SECURE_NO_WARNINGS -I ..\unit_test\include\ -I ..\include\lib_math\  /c ..\unit_test\src\UnitTestHelpers.cpp
cl /nologo /Zi /EHs /MDd /W4 -D_CRT_SECURE_NO_WARNINGS -I ..\unit_test\include\ -I ..\include\lib_math\  /c ..\unit_test\src\UnitTestMain.cpp

cl /nologo /Zi /EHs /MDd /W4 /Fe:..\bin\libmath.exe UnitTestMain.obj VectorTest.obj MatrixTest.obj UnitTestHelpers.obj
