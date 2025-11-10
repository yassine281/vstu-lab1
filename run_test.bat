@echo off

:: This script compiles and runs your C program with a predefined set of inputs.

:: --- STEP 1: COMPILE THE CODE ---
:: It uses the GCC compiler to turn your main.c file into an .exe program.

echo Compiling the program...
gcc main.c -o matrix_app.exe

:: Check if the program was created successfully.
if not exist matrix_app.exe (
    echo [ERROR] Compilation failed! Make sure GCC is installed.
    pause
    exit /b
)

echo.
echo --- RUNNING AUTOMATED TEST ---
echo The following output is from your program running with inputs from input.txt
echo --------------------------------
echo.

:: --- STEP 2: RUN THE PROGRAM WITH TEST INPUTS ---
:: This runs your compiled program.
:: The '<' symbol redirects the content from input.txt and "types" it into your app.

matrix_app.exe < input.txt

echo.
echo --------------------------------
echo --- TEST FINISHED ---
echo.

:: --- STEP 3: PAUSE ---
:: This keeps the window open so you can read the output.
pause
