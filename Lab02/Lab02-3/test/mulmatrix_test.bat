REM read empty file
multmatrix.exe "empty.txt" "m0.txt"
IF NOT ERRORLEVEL 1 GOTO err

REM read not existed file
multmatrix.exe "not_exist.txt" "m0.txt"
IF NOT ERRORLEVEL 1 GOTO err

REM read incorrect file
multmatrix.exe "bad.txt" "bad.txt"
IF NOT ERRORLEVEL 1 GOTO err

REM zero matrix multiplication
multmatrix.exe "m0.txt" "m0.txt" > m0xm0.txt
IF ERRORLEVEL 1 GOTO err
FC /B "m0.txt" "m0xm0.txt"
IF ERRORLEVEL 1 GOTO err

REM non zero matrix multiplication
multmatrix.exe "m1.txt" "m1.txt" > m1xm1.txt
IF ERRORLEVEL 1 GOTO err
FC /B "m1xm1.txt" "m1xm1.ref"
IF ERRORLEVEL 1 GOTO err


ECHO Program testing succeeded :-)

EXIT

:err
ECHO Program testing failed :-(
EXIT