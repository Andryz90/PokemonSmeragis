# AI Boss Battle - Guida Divulgativa

## A cosa serve questo documento

Questa guida spiega in modo semplice come si comporta l AI nelle boss battle.
L idea e: "cosa succede in campo", non "come e scritto il codice".

## Differenza chiave rispetto ai trainer normali

I boss usano la stessa base comportamentale dei trainer normali, ma con una differenza fondamentale:

1. **Omniscient**: hanno informazione molto piu completa sul team del giocatore.

Nel tuo progetto attuale:

1. 821 trainer usano il profilo "normale"
2. 35 trainer usano lo stesso profilo + `Omniscient`

## Cosa NON cambia rispetto ai trainer normali

Anche nei boss, la logica generale resta questa:

1. Evitare mosse inutili.
2. Cercare il KO quando c'e.
3. Valutare il contesto (non solo danno puro).
4. Fare switch tattici quando il matchup e brutto.
5. Scegliere meglio chi mandare dentro dopo uno switch o un KO.

Quindi i boss non sono "un AI diversa da zero": sono una versione piu informata della stessa AI.

## Cosa cambia davvero con Omniscient

Con Omniscient, il boss tende a:

1. Leggere meglio il tuo set (mosse/abilita/item), quindi cade meno in bluff.
2. Fare switch piu precisi contro le tue coverage.
3. Sbagliare meno su immunita/assorbimenti/item utility.
4. Valutare meglio se rischiare o meno una trade.

In pratica: non gioca solo bene, gioca anche con meno incertezza.

## Esempi pratici in partita

## Esempio A - Coverage sorpresa

Contesto:

1. Tu hai una mossa coverage che normalmente "non si aspetterebbero".
2. Un trainer normale puo restare e subire la sorpresa.
3. Un boss tende molto di piu a evitare quella linea e a cambiare prima.

Effetto percepito:

1. Meno KO "gratis" da mossa rivelata all ultimo.

## Esempio B - Bluff su abilita/item

Contesto:

1. Provi a far credere un certo piano (es. attirare una mossa in un assorbimento).
2. Contro AI normale puo funzionare piu spesso.
3. Contro boss funziona meno, perche legge meglio il rischio reale.

Effetto percepito:

1. Ti sembra "meno ingannabile" e piu pulito nelle risposte.

## Esempio C - Scelta switch-in dopo un KO

Contesto:

1. Il boss deve mandare un nuovo Pokemon.
2. Non sceglie solo "chi fa piu danno", ma chi entra meglio contro il tuo attivo.
3. Con Omniscient la scelta tende a essere ancora piu coerente.

Effetto percepito:

1. Piu spesso entra il mon giusto nel momento giusto.

## Cosa aspettarsi in ritmo partita

Nelle boss battle, di solito vedrai:

1. Meno turni regalati.
2. Piu pressione sul chiudere KO.
3. Piu switch "di controllo" del matchup.
4. Meno spazio per vincere con sola sorpresa.

## Come tradurlo per i giocatori (testo pronto)

"I boss usano la stessa intelligenza tattica dei trainer avanzati, ma con una lettura molto piu accurata del tuo team. In pratica puniscono di piu gli errori, regalano meno turni, e scelgono piu spesso lo switch o la mossa migliore per il contesto."

## Consigli pratici contro i boss (divulgativi)

1. Non contare solo sul fattore sorpresa: prepara linee solide anche dopo il reveal.
2. Valuta i loro switch: spesso conviene giocare su doppio turno (chip + controllo) invece del "colpo secco".
3. Pensa in sequenza di 2-3 turni: i boss puniscono di piu le scelte improvvisate.
4. Le win condition stabili (hazard, chip, speed control, posizionamento) rendono di piu dei gimmick singoli.

## Riassunto rapido

Se i trainer normali sono "buoni e aggressivi", i boss sono "buoni, aggressivi e molto piu informati".
La partita contro un boss si vince meno con il trucco singolo, e piu con un piano coerente turno dopo turno.
