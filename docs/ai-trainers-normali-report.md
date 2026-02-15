# AI Trainer Normali - Guida Divulgativa

## A cosa serve questo documento

Questa e una spiegazione semplice di come giocano i **trainer normali**.
Non e una guida al codice: e una guida a cosa vedi davvero in battaglia.

## In una frase

L AI prova prima a **non sprecare turni**, poi a **chiudere il KO** quando puo, e se il matchup e brutto prova a **switchare in un Pokemon piu adatto**.

## Come ragiona un turno (versione semplice)

Ogni turno, in pratica:

1. Controlla se conviene cambiare Pokemon.
2. Se resta in campo, scarta le mosse pessime o inutili.
3. Se puo fare KO, tende a farlo.
4. Se non puo fare KO, sceglie tra:
   - danno migliore
   - mossa con effetto utile in quel momento
   - opzione piu coerente con gli HP attuali

## Quando va per la kill

L AI cerca spesso la kill quando:

1. Ha una mossa che manda KO il tuo Pokemon in questo turno.
2. E piu veloce e il KO e sicuro.
3. Anche se e piu lenta, puo usare una mossa con priorita per chiudere prima.

In parole semplici: se vede una kill pulita, la prende quasi sempre.

## Quando preferisce switchare invece di attaccare

Con le tue flag attuali, lo switch e importante.
L AI switcha spesso quando:

1. Le sue mosse fanno poco o nulla al bersaglio.
2. E in un matchup molto sfavorevole (rischia di perdere lo scambio 1v1).
3. E bloccata in una mossa pessima (esempio tipico: Choice item su mossa inutile).
4. Sta per subire uno stato pesante e non ha un buon motivo per restare.
5. Le sue statistiche offensive sono scese troppo e non riesce piu a fare pressione.

Quindi non e un AI "ferma": cerca attivamente un ingresso migliore quando sente di stare perdendo il turno.

## "Check Bad Move": cosa significa per il giocatore

Significa che evita molte mosse "stupide", per esempio:

1. Mosse che non ti colpiscono.
2. Mosse rese inutili da immunita ovvie.
3. Setup/status in momenti in cui hanno poco senso.

Risultato pratico: vedi meno turni regalati.

## "Check Viability": cosa cambia davvero

Questa e la parte che rende l AI meno casuale.

Non guarda solo "quanto danno fa", ma anche:

1. Se una mossa apre una situazione vantaggiosa.
2. Se una mossa e affidabile.
3. Se in quel momento e meglio colpire, settare, o fare utility.

In breve: prova a fare la mossa "piu sensata" per il contesto, non solo la piu forte sulla carta.

## "Prefer Highest Damage Move": effetto concreto

Tra due opzioni simili, tende a preferire quella con danno piu alto.
Quindi a volte sceglie la mossa piu "grezza" invece di quella piu prudente.

Per il giocatore:

1. Piu pressione offensiva.
2. Meno turni di utility quando c'e un'opzione di danno molto alta.

## "HP Aware": cosa noterai in partita

Questa parte cambia le scelte in base alla vita rimasta.

1. Se il bersaglio e gia in range KO, tende a chiudere invece di perdere tempo.
2. Se e messa male di HP, evita alcune linee lente o rischiose.
3. Se ha tanta vita, e meno incline a usare opzioni "da emergenza" troppo presto.

Tradotto: fa scelte diverse a inizio, meta e fine scambio.

## "Smart Switching" e "Smart Mon Choices": differenza semplice

## Smart Switching

Decide **se** conviene uscire adesso.
Guarda matchup, status, probabilita di sopravvivenza, qualita delle mosse disponibili.

## Smart Mon Choices

Decide **chi** far entrare.
Non manda un Pokemon a caso: prova a mandare quello che regge meglio o minaccia meglio il tuo attivo.

Effetto pratico:

1. Dopo un KO, prova a entrare con un revenge killer sensato.
2. A meta battaglia, cerca un ingresso che non muoia subito e possa rispondere.

## Cosa NON sa sempre l AI normale

I trainer normali (senza Omniscient) non hanno sempre informazione perfetta.
Quindi a volte ragionano su quello che hanno gia "visto" durante la lotta.

Questo significa:

1. Sono forti, ma non leggono tutto in modo magico.
2. Alcuni bluff o reveal tardivi possono ancora funzionare.

## Riassunto rapido per i giocatori

Contro trainer normali aspettati:

1. Meno mosse inutili.
2. Piu tentativi di chiudere KO appena possibile.
3. Piu switch tattici quando il matchup e brutto.
4. Scelte diverse in base agli HP, non sempre la stessa mossa in loop.

Se vuoi, nel prossimo step ti preparo la stessa versione divulgativa per le **boss battle** e ti evidenzio solo le differenze percepibili dal giocatore.
