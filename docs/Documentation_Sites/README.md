# HackROM Documentation Sites

Indice rapido per i documenti locali della hackrom, con link e workflow di aggiornamento.

## Link rapidi

- [EKalc (dist/index.html)](./Calculator/dist/index.html)
- [Trainer Docs (site/index.html)](./Trainer_Docs/site/index.html)
- [Porydex (site/index.html)](./porydex/site/index.html)
- [ItemsDoc (index.html)](./ItemsDoc/index.html)
- [ItemsDoc sorgente (obtainable_items.md)](./ItemsDoc/obtainable_items.md)

## Aggiornamento centralizzato (consigliato)

Per evitare passaggi manuali sparsi, usa lo script unico:

```bat
cd docs\Documentation_Sites
update_all_docs.bat
```

Opzioni utili:

```bat
update_all_docs.bat --update-smogon-sets
update_all_docs.bat --skip-porydex
```

Lo script esegue in ordine:
1. `Trainer_Docs` + sync sets di `EKalc`
2. rigenerazione `moves.ts` helper
3. rigenerazione `species tables` helper
4. build `EKalc` (`node build`)
5. `porydex config set` + `porydex extract` via `wsl` (se non usi `--skip-porydex`)
6. reminder `ItemsDoc` (statico/manuale)

## Windows + WSL (ostacolo superato)

- I passaggi Windows rimangono in `.bat`.
- Il passaggio Linux/WSL (`porydex`) viene richiamato automaticamente da `.bat` tramite `wsl`.
- Prima di `extract`, lo script riallinea automaticamente il path `expansion` di `porydex` alla repo corrente.
- Se WSL non e disponibile, puoi usare `--skip-porydex` e lanciare quello step separatamente quando sei in WSL.

## Aggiornare manualmente (fallback)

Esegui i comandi dalla root repository (`/home/grieco/HackRomProject`), salvo dove indicato.

### 1) Trainer Docs + EKalc sets sync

```bat
cd docs\Documentation_Sites\Calculator\bat
calc_sets_update.bat
```

### 2) Rigenerazione Moves/Species support scripts

Moves:

```bat
cd docs\Documentation_Sites\Script_Moves_Ts
build.bat
```

Species:

```bat
cd docs\Documentation_Sites\Script_Species_Ts
species_table_generator.bat
```

### 3) Build EKalc

```bash
cd docs/Documentation_Sites/Calculator
node build
```

Opzionale prima del build:

```bat
npm update @smogon/sets
```

### 4) Porydex extract

WSL/Linux:

```bash
cd docs/Documentation_Sites/porydex
./.venv/bin/python porydex.py config set -e "$(cd ../../.. && pwd)" -o "$(pwd)/site/data" -f showdown
./.venv/bin/python porydex.py extract
```

### 5) ItemsDoc

`ItemsDoc` e una pagina statica: aggiorna `docs/Documentation_Sites/ItemsDoc/obtainable_items.md` e/o `index.html` quando cambi il routing/item split.

## Prima del push

Controlli veloci:

```bash
git status --short
git diff -- .gitignore docs/Documentation_Sites/README.md docs/Documentation_Sites/update_all_docs.bat docs/SUMMARY.md README.md
```

Commit docs:

```bash
git add .gitignore docs/Documentation_Sites/README.md docs/Documentation_Sites/update_all_docs.bat docs/SUMMARY.md README.md
git commit -m "docs: update hackrom documentation hub and links"
git push
```
