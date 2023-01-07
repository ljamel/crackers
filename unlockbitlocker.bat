@echo off

echo Please choose the drive letter you wish to unlock:
set /p DriveLetter=

for /f %%i in ('type "passwords.txt"') do (
  echo Trying %%i
  manage-bde -unlock %DriveLetter%: -password %%i
  if %errorlevel% EQU 0 (
    echo The drive has been successfully unlocked with password %%i
    echo %%i >> "unlock_password.txt"
    goto :end
  )
)

echo No valid password was found in the list.

:end
