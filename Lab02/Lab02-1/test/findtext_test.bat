REM test crypt empty file
findtext.exe "empty.txt" ""
IF NOT ERRORLEVEL 1 GOTO err

REM test find existed substrings
findtext.exe "main.txt" "vector" > output
IF ERRORLEVEL 1 GOTO err
FC /B "output" "main.result"
IF ERRORLEVEL 1 GOTO err

REM test not find substrings
findtext.exe "main.txt" "not_existed"
IF NOT ERRORLEVEL 1 GOTO err

ECHO Program testing succeeded :-)

EXIT

:err
ECHO Program testing failed :-(
EXIT