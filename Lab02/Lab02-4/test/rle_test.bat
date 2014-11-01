REM test pack empty file
rle.exe pack "empty.txt" "empty.rle"
IF ERRORLEVEL 1 GOTO err
FC /B "empty.txt" "empty.rle"
IF ERRORLEVEL 1 GOTO err

REM test normal pack/unpack cycle
rle.exe pack "test.txt" "test.rle"
IF ERRORLEVEL 1 GOTO err
rle.exe unpack "test.rle" "cycle_test.txt"
FC /B "test.txt" "cycle_test.txt"
IF ERRORLEVEL 1 GOTO err

REM test 255 file length
rle.exe pack "255.txt" "255.rle"
IF ERRORLEVEL 1 GOTO err
FC /B "255.rle" "reference_255.txt"
IF ERRORLEVEL 1 GOTO err

REM test 256 file length
rle.exe pack "256.txt" "256.rle"
IF ERRORLEVEL 1 GOTO err
FC /B "256.rle" "reference_256.txt"
IF ERRORLEVEL 1 GOTO err

REM test 257 file length
rle.exe pack "257.txt" "257.rle"
IF ERRORLEVEL 1 GOTO err
FC /B "257.rle" "reference_257.txt"
IF ERRORLEVEL 1 GOTO err

REM test file with 16 ff symbols
rle.exe pack "ff.txt" "ff.rle"
IF ERRORLEVEL 1 GOTO err
FC /B "ff.rle" "reference_ff.txt"
IF ERRORLEVEL 1 GOTO err

REM test unpack corrupted file
rle.exe unpack "corrupted.rle" "corrupted.txt"
IF NOT ERRORLEVEL 1 GOTO err

ECHO Program testing succeeded :-)

EXIT

:err
ECHO Program testing failed :-(
EXIT