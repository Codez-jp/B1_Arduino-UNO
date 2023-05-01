echo off

rem echo UserProfile %UserProfile%
rem echo UserName %UserName%
rem echo AppData %AppData%
rem echo LocalAppData %LocalAppData%
rem echo CurrentDirectory %CD%
rem echo CD %CD%
rem echo SELF %0

rem https://stackoverflow.com/questions/17279114/split-path-and-take-last-folder-name-in-batch-script
set MYDIR=%CD%\
if "%MYDIR:~-1%" == "\" set "MYDIR1=%MYDIR:~0,-1%"
for %%f in ("%MYDIR1%") do set "FOLDER=%%~nxf"
echo FOLDER %FOLDER%

set TOOL=\Arduino15\packages\arduino\tools\avrdude\6.3.0-arduino17
set EXE=%LocalAppData%%TOOL%/bin/avrdude.exe
set CONF=%LocalAppData%%TOOL%/etc/avrdude.conf
set HEX=%CD%\dist\default\production/%FOLDER%.production.hex

echo "---------------------"
echo EXE  %EXE%
echo CONF %CONF%
echo HEX  %HEX%
echo "---------------------"

set CMD=%EXE% -C%CONF% -v -patmega328p -carduino -PCOM3 -b115200 -D -Uflash:w:%HEX%:i
echo CMD %CMD%
%CMD%
pause
