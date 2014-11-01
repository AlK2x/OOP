REM test crypt empty file
crypt.exe crypt "empty.txt" "empty.crypt" 42
IF ERRORLEVEL 1 GOTO err
FC /B "empty.txt" "empty.crypt"
IF ERRORLEVEL 1 GOTO err

REM test normal crypt/decrypt cycle
crypt.exe crypt "test.txt" "test.crypt" 42
IF ERRORLEVEL 1 GOTO err
crypt.exe decrypt "test.crypt" "cycle_test.txt" 42
FC /B "test.txt" "cycle_test.txt"
IF ERRORLEVEL 1 GOTO err

REM test crypt 00.txt key == 0
crypt.exe crypt "00.txt" "00.crypt" 0
IF ERRORLEVEL 1 GOTO err
FC /B "00.crypt" "00.txt"
IF ERRORLEVEL 1 GOTO err

REM test crypt 00.txt key == 255
crypt.exe crypt "00.txt" "00.crypt" 255
IF ERRORLEVEL 1 GOTO err
FC /B "00.crypt" "ff.txt"
IF ERRORLEVEL 1 GOTO err

REM error command
crypt.exe command "00.txt" "00.crypt" 255
IF NOT ERRORLEVEL 1 GOTO err

REM non exist input file
crypt.exe unpack "not_exist.txt" "not_exist.crypt" 22
IF NOT ERRORLEVEL 1 GOTO err

REM error key
crypt.exe unpack "00.txt" "00.crypt" 256
IF NOT ERRORLEVEL 1 GOTO err

ECHO Program testing succeeded :-)

EXIT

:err
ECHO Program testing failed :-(
EXIT