@echo off
echo Building simple cheat...
echo.

echo [1] Creating DLL...
g++ -shared -o SimpleCheat.dll SimpleCheat.cpp -lwinmm

echo [2] Creating injector...
g++ -o injector.exe -std=c++11 injector.cpp

echo.
echo Done! Files created:
echo   - SimpleCheat.dll
echo   - injector.exe
echo.
pause
