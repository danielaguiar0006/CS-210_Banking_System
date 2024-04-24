@echo off
g++ -o Airgead_Banking main.cpp BankingSystem.cpp CalculationEngine.cpp
if %errorlevel% neq 0 (
    echo Build failed with error %errorlevel%.
    exit /b %errorlevel%
)
echo Build completed.
.\Airgead_Banking.exe
