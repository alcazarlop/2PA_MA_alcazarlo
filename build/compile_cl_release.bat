@ECHO OFF

del *.obj *.pdb *.ilk *.exe

cl /nologo /O2 /GR- /EHs /MD /W4 -D_CRT_SECURE_NO_WARNINGS -I ..\include -I ..\deps\sdl2\include -I ..\deps\imgui\ -I ..\deps\sqlite\include\ /c ..\src\*.cc
cl /nologo /O2 /GR- /EHs /MD /W4 /Fe:..\bin\main.exe *.obj /link /SUBSYSTEM:CONSOLE ..\deps\sdl2\lib\x86\SDL2.lib ..\deps\sdl2\lib\x86\SDL2main.lib ..\deps\imgui\lib\imgui_d.lib ..\deps\sqlite\lib\sqlite3.lib opengl32.lib shell32.lib user32.lib gdi32.lib

