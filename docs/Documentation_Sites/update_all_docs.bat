@echo off
setlocal EnableExtensions

set "SCRIPT_DIR=%~dp0"
for %%I in ("%SCRIPT_DIR%..\..") do set "REPO_ROOT=%%~fI"
set "EXPECTED_REPO_ROOT=C:\Users\Andre\Documents\Pokemon Smeragis\HackRomProject"
set "SKIP_PORYDEX=0"
set "UPDATE_SMOGON_SETS=0"

if /I not "%REPO_ROOT%"=="%EXPECTED_REPO_ROOT%" (
    echo [ERROR] Questo script e bloccato su una sola repo Windows.
    echo [ERROR] Rilevato : %REPO_ROOT%
    echo [ERROR] Atteso   : %EXPECTED_REPO_ROOT%
    exit /b 1
)

:parse_args
if "%~1"=="" goto :args_done
if /I "%~1"=="--skip-porydex" (
    set "SKIP_PORYDEX=1"
    shift
    goto :parse_args
)
if /I "%~1"=="--update-smogon-sets" (
    set "UPDATE_SMOGON_SETS=1"
    shift
    goto :parse_args
)
if /I "%~1"=="--help" (
    echo.
    echo Uso:
    echo   update_all_docs.bat [--update-smogon-sets] [--skip-porydex]
    echo.
    echo Opzioni:
    echo   --update-smogon-sets  Esegue anche npm update @smogon/sets prima del build EKalc
    echo   --skip-porydex        Salta lo step porydex ^(utile se WSL non disponibile^)
    echo.
    echo Esempi:
    echo   update_all_docs.bat
    echo   update_all_docs.bat --update-smogon-sets
    echo   update_all_docs.bat --skip-porydex
    exit /b 0
)

echo [ERROR] Opzione non riconosciuta: %~1
echo.
echo Usa --help per vedere le opzioni disponibili.
exit /b 1

:args_done
echo.
echo === HackROM Documentation: Full Update ===
echo Root repo: %REPO_ROOT%
echo.

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
    where python >nul 2>&1
    if not errorlevel 1 set "PY_CMD=python"
)
if not defined PY_CMD (
    echo [ERROR] Python non trovato. Installa Python 3 o il launcher "py".
    exit /b 1
)

where node >nul 2>&1
if errorlevel 1 (
    echo [ERROR] Comando "node" non trovato. Installa Node.js.
    exit /b 1
)

where npm >nul 2>&1
if errorlevel 1 (
    echo [ERROR] Comando "npm" non trovato. Installa npm/Node.js.
    exit /b 1
)

pushd "%SCRIPT_DIR%" || (
    echo [ERROR] Impossibile accedere a %SCRIPT_DIR%
    exit /b 1
)

echo [1/9] Sync learnset helpers (porymoves_files ^> src headers)
pushd "%REPO_ROOT%" || goto :fail
call %PY_CMD% tools\learnset_helpers\teachable.py
if errorlevel 1 (
    popd
    goto :fail
)
popd

echo [2/9] Sync wild encounters header (wild_encounters.json ^> wild_encounters.h)
pushd "%REPO_ROOT%" || goto :fail
call %PY_CMD% tools\wild_encounters\wild_encounters_to_header.py
if errorlevel 1 (
    popd
    goto :fail
)
popd

echo [3/9] Trainer Docs + EKalc sets sync
pushd "Calculator\bat" || goto :fail
call "calc_sets_update.bat"
if errorlevel 1 (
    popd
    goto :fail
)
popd

echo [4/9] Rigenerazione moves.ts helper
pushd "Script_Moves_Ts" || goto :fail
call "build.bat"
if errorlevel 1 (
    popd
    goto :fail
)
popd

echo [5/9] Rigenerazione species tables helper
pushd "Script_Species_Ts" || goto :fail
call "species_table_generator.bat"
if errorlevel 1 (
    popd
    goto :fail
)
popd

echo [6/9] Build EKalc dist
pushd "Calculator" || goto :fail
if "%UPDATE_SMOGON_SETS%"=="1" (
    echo [6a] npm update @smogon/sets
    call npm update @smogon/sets
    if errorlevel 1 (
        popd
        goto :fail
    )
)
call node build
if errorlevel 1 (
    popd
    goto :fail
)
popd

if "%SKIP_PORYDEX%"=="1" goto :skip_porydex

echo [7/9] Porydex extract via WSL
where wsl >nul 2>&1
if errorlevel 1 (
    echo [ERROR] WSL non trovato. Installa/configura WSL oppure usa --skip-porydex.
    goto :fail
)

set "PORYDEX_WIN_DIR=%SCRIPT_DIR%porydex"
for /f "usebackq delims=" %%I in (`wsl wslpath -a "%PORYDEX_WIN_DIR%" 2^>nul`) do set "WSL_PORYDEX_DIR=%%I"
if not defined WSL_PORYDEX_DIR (
    echo [ERROR] Impossibile convertire il path porydex in path WSL.
    echo [HINT] Verifica che WSL sia installato e che il path esista: %PORYDEX_WIN_DIR%
    goto :fail
)

for /f "usebackq delims=" %%I in (`wsl wslpath -a "%REPO_ROOT%" 2^>nul`) do set "WSL_REPO_ROOT=%%I"
if not defined WSL_REPO_ROOT (
    echo [ERROR] Impossibile convertire il path repository in path WSL.
    echo [HINT] Verifica che il path esista: %REPO_ROOT%
    goto :fail
)

for /f "usebackq delims=" %%I in (`wsl wslpath -a "%EXPECTED_REPO_ROOT%" 2^>nul`) do set "WSL_EXPECTED_REPO_ROOT=%%I"
if not defined WSL_EXPECTED_REPO_ROOT (
    echo [ERROR] Impossibile convertire il path repository atteso in path WSL.
    goto :fail
)
if /I not "%WSL_REPO_ROOT%"=="%WSL_EXPECTED_REPO_ROOT%" (
    echo [ERROR] Path repo WSL non coerente con il path Windows atteso.
    echo [ERROR] Rilevato : %WSL_REPO_ROOT%
    echo [ERROR] Atteso   : %WSL_EXPECTED_REPO_ROOT%
    goto :fail
)

echo [INFO] WSL porydex path: %WSL_PORYDEX_DIR%
echo [INFO] WSL repo path: %WSL_REPO_ROOT%
wsl bash -lc "cd '%WSL_PORYDEX_DIR%' && test -x './.venv/bin/python' && ./.venv/bin/python porydex.py config set -e '%WSL_REPO_ROOT%' -o '%WSL_PORYDEX_DIR%/site/data' -f showdown && ./.venv/bin/python porydex.py extract --reload"
if errorlevel 1 (
    echo [ERROR] Step porydex fallito.
    echo [HINT] Verifica che la virtualenv esista in %WSL_PORYDEX_DIR%/.venv
    goto :fail
)
goto :after_porydex

:skip_porydex
echo [7/9] Porydex extract saltato (--skip-porydex)

:after_porydex
echo [8/9] Build static encounters overlay
pushd "%REPO_ROOT%" || goto :fail
call %PY_CMD% docs\Documentation_Sites\porydex\build_static_encounters.py
if errorlevel 1 (
    popd
    goto :fail
)
popd

echo [9/9] ItemsDoc
echo [INFO] ItemsDoc e statico: aggiorna manualmente ItemsDoc/index.html e obtainable_items.md quando necessario.

popd
echo.
echo [OK] Aggiornamento documentazione completato.
echo [INFO] Verifica con: git status --short
exit /b 0

:fail
popd
echo.
echo [ERROR] Aggiornamento interrotto. Controlla il log sopra.
exit /b 1
