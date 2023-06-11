echo off

rem echo ====== for testing ======
rem echo ProgramFiles(x86)  %ProgramFiles(x86)%
rem echo ProgramFiles       %ProgramFiles%
rem echo LocalAppData       %LocalAppData%
rem echo CurrentDirectory   %CD%
rem echo UserProfile    %UserProfile%
rem echo UserName       %UserName%
rem echo AppData        %AppData%
rem echo CD             %CD%
rem echo SELF           %0
rem echo ====== for testing ======

rem https://stackoverflow.com/questions/17279114/split-path-and-take-last-folder-name-in-batch-script
set MYDIR=%CD%\
if "%MYDIR:~-1%" == "\" set "MYDIR1=%MYDIR:~0,-1%"
for %%f in ("%MYDIR1%") do set "FOLDER=%%~nxf"
echo PROJ   %FOLDER%

set TOOL=\bin\avrdude.exe
set CONF=\etc\avrdude.conf
set ROOT=%ProgramFiles(x86)%\Arduino\hardware\tools\avr

if not exist "%ROOT%%TOOL%" (
    echo not found TOOL "%ROOT%"
    set ROOT=%LocalAppData%\Arduino15\packages\arduino\tools\avrdude\6.3.0-arduino17
    echo change ROOT to "%ROOT%"
)
echo ROOT   %ROOT%

set HEX=%CD%\dist\default\production\%FOLDER%.production.hex
if not exist "%HEX%" goto not_found_hex
echo HEX    %HEX%

set CMD="%ROOT%%TOOL%" -C "%ROOT%%CONF%" -patmega328p -carduino -PCOM3 -b115200 -D -U flash:w:%HEX%:i
echo CMD        %CMD%
%CMD% -v
goto :OK



:not_found_exe
echo ERROR ERROR ERROR
echo not found avrdude.exe
echo please install avrdude.exe with Arduino IDE.
goto :EOF

:not_found_hex
echo ERROR ERROR ERROR
echo not found hex file
echo please re-build with **NOT DEBUG** mode.
goto :EOF

:OK
echo OK done.
goto :EOF

:EOF
pause
