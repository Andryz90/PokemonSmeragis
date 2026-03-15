# HackROM Documentation Sites

Indice rapido per i documenti locali della hackrom, con link e workflow di aggiornamento.

## Link rapidi

- [EKalc (dist/index.html)](./Calculator/dist/index.html)
- [Trainer Docs (site/index.html)](./Trainer_Docs/site/index.html)
- [Porydex (site/index.html)](./porydex/site/index.html)
- [ItemsDoc (index.html)](./ItemsDoc/index.html)
- [ItemsDoc sorgente (obtainable_items.md)](./ItemsDoc/obtainable_items.md)

## Aggiornare tutta la documentazione

Esegui i comandi dalla root repository (`/home/grieco/HackRomProject`), salvo dove indicato.

### 1) Trainer Docs

Windows:

```bat
cd docs\Documentation_Sites\Trainer_Docs
build.bat
```

### 2) EKalc (calculator)

Build standard:

```bash
cd docs/Documentation_Sites/Calculator
node build
```

Aggiornamento sets (Windows helper):

```bat
cd docs\Documentation_Sites\Calculator\bat
calc_sets_update.bat
cd ..
npm update @smogon/sets
node build
```

### 3) Rigenerazione Moves/Species support scripts

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

### 4) Porydex extract

WSL/Linux:

```bash
cd docs/Documentation_Sites/porydex
./.venv/bin/python porydex.py extract
```

### 5) ItemsDoc

`ItemsDoc` e una pagina statica: aggiorna `docs/Documentation_Sites/ItemsDoc/obtainable_items.md` e/o `index.html` quando cambi il routing/item split.

## Prima del push

Controlli veloci:

```bash
git status --short
git diff -- docs/Documentation_Sites/README.md docs/SUMMARY.md README.md
```

Commit docs:

```bash
git add docs/Documentation_Sites/README.md docs/SUMMARY.md README.md
git commit -m "docs: update hackrom documentation hub and links"
git push
```
