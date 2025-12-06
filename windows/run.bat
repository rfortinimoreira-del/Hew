@echo off
REM Hubble Launcher - Execute o jogo

cd /d "%~dp0"

if exist "hubble.exe" (
    start hubble.exe
) else (
    echo.
    echo [ERRO] hubble.exe nao encontrado!
    echo Certifique-se de que o arquivo esta na mesma pasta que este script.
    echo.
    pause
)
