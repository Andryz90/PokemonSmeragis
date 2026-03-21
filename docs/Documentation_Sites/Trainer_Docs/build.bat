@echo off
setlocal EnableExtensions

set "PY_CMD="
where py >nul 2>&1
if not errorlevel 1 (
    py -3 --version >nul 2>&1
    if not errorlevel 1 set "PY_CMD=py -3"
    if not defined PY_CMD (
        py --version >nul 2>&1
        if not errorlevel 1 set "PY_CMD=py"
    )
)
if not defined PY_CMD (
    python --version >nul 2>&1
    if not errorlevel 1 set "PY_CMD=python"
)
if not defined PY_CMD (
    python3 --version >nul 2>&1
    if not errorlevel 1 set "PY_CMD=python3"
)
if not defined PY_CMD (
    echo [ERROR] Python non trovato. Installa Python 3 o il launcher "py".
    exit /b 1
)

copy "..\..\..\src\data\battle_partners.party" "./" >nul || exit /b 1
copy "..\..\..\src\data\trainers.party" "./" >nul || exit /b 1

call %PY_CMD% SortParty.py || exit /b 1
del trainers.party || exit /b 1
rename trainers_sorted.party trainers.party || exit /b 1

call %PY_CMD% .\main.py || exit /b 1
call %PY_CMD% .\createsitefromindx.py || exit /b 1
