@echo off
REM Hubble - Windows Installer
REM Instala o jogo na pasta Program Files

setlocal enabledelayedexpansion

cls
echo.
echo    ^|^^^| Hubble - Instalador Windows
echo    ^|^|  Jogo 3D Magico
echo.

REM Verificar direitos de administrador
net session >nul 2>&1
if %errorLevel% neq 0 (
    echo [ERRO] Este instalador requer direitos de administrador!
    echo Por favor, execute como administrador.
    pause
    exit /b 1
)

REM Definir caminho de instalação
set "INSTALL_DIR=%ProgramFiles%\Hubble"

echo [INFO] Instalando em: %INSTALL_DIR%
echo.

REM Criar diretório
if not exist "%INSTALL_DIR%" (
    mkdir "%INSTALL_DIR%"
    echo [OK] Diretorio criado
)

REM Copiar arquivos
echo [INFO] Copiando arquivos...
copy "hubble.exe" "%INSTALL_DIR%\" >nul
if exist "assets" (
    xcopy /E /I /Y "assets" "%INSTALL_DIR%\assets" >nul
)
copy "README.txt" "%INSTALL_DIR%\" >nul
copy "run.bat" "%INSTALL_DIR%\" >nul 2>&1

if %errorLevel% equ 0 (
    echo [OK] Arquivos copiados com sucesso
) else (
    echo [ERRO] Falha ao copiar arquivos
    pause
    exit /b 1
)

REM Criar atalho no Desktop
echo [INFO] Criando atalhos...

set "DESKTOP=%USERPROFILE%\Desktop"
set "SHORTCUT=%DESKTOP%\Hubble.lnk"

powershell -Command "(New-Object -COM WScript.Shell).CreateShortcut('%SHORTCUT%').TargetPath='%INSTALL_DIR%\hubble.exe'; (New-Object -COM WScript.Shell).CreateShortcut('%SHORTCUT%').WorkingDirectory='%INSTALL_DIR%'; (New-Object -COM WScript.Shell).CreateShortcut('%SHORTCUT%').Save()" >nul 2>&1

REM Criar atalho no Menu Iniciar
set "START_MENU=%APPDATA%\Microsoft\Windows\Start Menu\Programs"
set "MENU_SHORTCUT=%START_MENU%\Hubble.lnk"

powershell -Command "(New-Object -COM WScript.Shell).CreateShortcut('%MENU_SHORTCUT%').TargetPath='%INSTALL_DIR%\hubble.exe'; (New-Object -COM WScript.Shell).CreateShortcut('%MENU_SHORTCUT%').WorkingDirectory='%INSTALL_DIR%'; (New-Object -COM WScript.Shell).CreateShortcut('%MENU_SHORTCUT%').Save()" >nul 2>&1

echo [OK] Atalhos criados

echo.
echo    ✨ Instalacao concluida com sucesso!
echo.
echo    O jogo foi instalado em:
echo    %INSTALL_DIR%
echo.
echo    Voce pode encontra-lo em:
echo    - Menu Iniciar ^> Hubble
echo    - Desktop ^> Hubble (atalho)
echo.

pause
