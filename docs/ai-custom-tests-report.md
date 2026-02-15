# Report AI Custom Test (Trainer + Boss)

Aggiornato al **15 febbraio 2026**.

## Obiettivo

Questo report raccoglie in modo pratico cosa fa davvero l'AI nei casi che abbiamo testato con scenari mirati.
L'idea e' rispondere alla domanda: "in battaglia, cosa sceglie e perche?".

## Profili AI testati

- **Trainer standard**:
  - `Check bad Move`
  - `Try To Faint`
  - `Prefer Highest Damage Move`
  - `Check Viability`
  - `HP Aware`
  - `Smart Switching`
  - `Smart Mon Choices`
- **Boss battle**:
  - stesse flag sopra
  - + `Omniscient`

## Stato test (ultima esecuzione)

Comandi usati:

- `make check TESTS="AI custom scenarios:" -j24`
- `make check TESTS="AI custom move acknowledge:" -j24`
- `make check TESTS="AI custom move bug check:" -j24`

Risultati:

- `AI custom scenarios`: **26/26 PASS**
- `AI custom move acknowledge`: **6/6 PASS**
- `AI custom move bug check`: **2/2 PASS**
- Totale: **34/34 PASS**

## Cosa fa l'AI in pratica (scoperte)

## 1) Priorita', KO e speed control

- Se l'AI e' piu' lenta ma ha una **mossa prioritaria che chiude il KO**, la preferisce.
- Se l'AI e' gia' piu' veloce e ha due mosse che chiudono entrambe, puo' scegliere una delle due.
- In **speed tie**, la priorita' non e' sempre obbligatoria: l'AI puo' valutare entrambe le opzioni come valide.

Interpretazione gameplay: l'AI gioca "kill first", ma senza rigidita' assoluta quando il risultato del turno non cambia.

## 2) Switching: quando resta e quando cambia

- Se il tuo colpo e' letale e l'AI ha un compagno con **immunita' utile** (es. Levitate vs Ground), tende a switchare.
- Se non ha uno switch realmente migliore, puo' comunque restare per cercare il trade/KO.
- Se in panchina ha una risposta migliore e piu' rapida, tende a usare lo switch in modo attivo.

Interpretazione gameplay: non switcha "a caso"; lo fa quando il cambio migliora concretamente lo stato del turno successivo.

## 3) Caso "Maxie nel deserto" (boss profile)

- Negli scenari riprodotti (Feraligatr con Water Fangs contro core Hippowdon/Maractus/Camerupt), la boss AI:
  - **non entra in auto-switch immediato**
  - puo' scegliere di giocare la mossa del Pokemon in campo

Interpretazione gameplay: non e' emerso un comportamento di switch loop automatico nel setup testato.

## 4) Taunt

- Contro target orientati a mosse status, `Taunt` viene preferita.
- Se l'AI ha un **KO immediato**, ignora `Taunt` e chiude.
- Contro target full-offense, `Taunt` viene de-prioritizzata.

Interpretazione gameplay: `Taunt` e' una mossa "situazionale intelligente", non una scelta fissa.

## 5) Shed Tail

- `Shed Tail` viene usata quando il pivot e' sicuro e c'e' un compagno valido da far entrare.
- Viene evitata se i PS sono al 50% o meno.
- Viene evitata se non esiste uno switch utile/possibile.

Interpretazione gameplay: uso opportunistico, non spam.

## 6) Abilita' ignote e memorizzazione immunita'

- Contro abilita' non ancora note (caso Lanturn), l'AI puo' comunque provare il colpo rischioso (non e' sempre ultra-cauta).
- Una volta vista l'immunita' (es. Volt Absorb), l'AI **se la ricorda**, anche dopo switch out/in.

Interpretazione gameplay: c'e' apprendimento in battle state.

## 7) Illusion

- Con Zoroark avversario, l'AI puo' essere ingannata all'inizio dal typing apparente.
- Questo succede anche con `Omniscient` nel primo momento del bluff.
- Dopo segnali impossibili (mosse non compatibili con la forma mostrata), l'AI corregge la lettura.
- Se l'AI stessa ha `Illusion`, sceglie le mosse in base al proprio typing reale.

Interpretazione gameplay: l'AI gestisce Illusion in modo progressivo (prima apparenza, poi correzione).

## 8) Protect + orb (Guts / Toxic Boost)

- Con `Flame Orb` + `Guts` o `Toxic Orb` + `Toxic Boost`, l'AI puo' usare `Protect` per attivare il boost prima di attaccare.

Interpretazione gameplay: riconosce setup immediato a turno 1 per massimizzare il danno turno 2.

## 9) Mega Evolution e scoring mosse

- Nel caso testato, con Mega disponibile, lo scoring risulta ancora legato al **profilo base form** nella scelta del turno.

Interpretazione gameplay: possibile differenza tra "potenziale mega" e "valutazione effettiva del turno" da tenere a mente.

## 10) Pivot moves (U-turn / Volt Switch / Flip Turn)

- In scenario con `Palafin Zero` (pivot obbligatorio per attivare la trasformazione), l'AI privilegia le mosse hit-and-switch.

Interpretazione gameplay: riconosce il valore strategico del pivot, non solo il danno puro.

## 11) Knock Off

- Se il bersaglio ha ancora uno strumento removibile, `Knock Off` viene preferita anche rispetto a un'alternativa dark.
- Quando la pressione item non esiste piu', l'AI torna a privilegiare la mossa dark piu' forte.

Interpretazione gameplay: uso contestuale corretto di `Knock Off`.

## 12) Mosse custom: acknowledge e bug check

Con i test custom su mosse aggiunte in `moves_info.h`:

- Le mosse custom di danno vengono riconosciute come migliori rispetto a opzioni inutili.
- `Royal Guard` viene trattata come `Protect` in scenari di setup.
- `Hoarfrost` viene scelta su target sano quando ha senso.
- `Deterio` viene preferita contro target Steel.
- `Season Power` segue logica di tipo dinamica.
- L'AI evita hazard setup se l'avversario puo' rimuovere hazard con `Windsom of Change`.
- Bug check passati:
  - evita `Hoarfrost` su target gia' con status maggiore
  - evita `Purifying Water` su target Water

## Limiti del report

- Sono scenari sintetici (mirati), utili a isolare decisioni specifiche.
- Non coprono ancora tutte le combinazioni multi-turno, hazards completi, doubles avanzati, weather esteso.
- Alcuni casi (es. abilita' ignote) includono componente probabilistica.

## File di riferimento

- `test/battle/ai/custom/ai_custom_scenarios.c`
- `test/battle/ai/custom/ai_custom_moves_acknowledge.c`
- `docs/ai-trainers-normali-report.md`
- `docs/ai-boss-battle-report.md`
