@echo generating gen9.js from Trainer Docs

rem .\ gen9.js @echo Removing old .js

@echo Generating new one

pushd ..\..\Trainer_Docs\

call build.bat
if errorlevel 1 (
  popd
  exit /b 1
)

popd

python .\calc_sets_modifier.py
if errorlevel 1 exit /b 1

move /Y gen9.js ..\src\js\data\sets\gen9.js
if errorlevel 1 exit /b 1
