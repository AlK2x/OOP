REM  ��� ��ࠬ��஢
eval.exe
IF ERRORLEVEL 1 GOTO err

REM  ������ ��ࠬ���
eval.exe incorrectExpression
IF NOT ERRORLEVEL 1 GOTO err

REM  ���⮩ ��ࠬ���
eval.exe ""
IF NOT ERRORLEVEL 1 GOTO err

REM ���� ���
eval.exe 12345 > output.txt
IF ERRORLEVEL 1 GOTO err
FC output.txt 12345.txt
IF ERRORLEVEL 1 GOTO err

REM ���⮥ ��ࠦ����
eval.exe 13 + 7 / 8 * 3.8 > output.txt
IF ERRORLEVEL 1 GOTO err
FC output.txt 9p500.txt
IF ERRORLEVEL 1 GOTO err

REM �஢�ઠ ������� �� ����
eval.exe 1 / 0 > output.txt
IF NOT ERRORLEVEL 1 GOTO err

REM �஢�ઠ �� �������⨬� ������
eval.exe 1 P 0 > output.txt
IF NOT ERRORLEVEL 1 GOTO err

REM ��ࠦ���� � ����⥫�묨 �᫠��
eval.exe 13 + 7 / 8 * -3.8 > output.txt
IF ERRORLEVEL 1 GOTO err
FC output.txt m9p500.txt
IF ERRORLEVEL 1 GOTO err

REM �஢�ઠ �� �������⨬� ���࠭�
eval.exe 13 + notAllowed / 8 * -3.8 > output.txt
IF NOT ERRORLEVEL 1 GOTO err


ECHO Program testing succeeded :-)

EXIT

:err
ECHO Program testing failed :-(
EXIT
