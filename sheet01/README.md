# Lösung Blatt 1
[Link zum Blatt](https://scoop.iwr.uni-heidelberg.de/teaching/2023ss/grundkurscpp/uebung01.pdf)

## Aufgabe 3
|Befehle|Beschreibung|
|---|---|  
|wc | Print newline, word, and byte counts for each FILE, and a total line if more than one FILE is specified|
|find | search for files in a directory hierarchy|
|xargs|wendet einen Befehl auf eine Liste an [(Erklärung)](https://wiki.ubuntuusers.de/xargs/)|
|grep|print lines that match patterns|

```
find /usr/include/ -name '*.h' | wc -l
```
Es befinden sich wohl 1717 .h Dateien unter `/usr/include/` .

`-name` setzt einen Test für find, welcher die Namen der Dateien nach der Endung `.h` durchsucht. Das `*` Zeichen davor gibt an, dass alle Zeichen davor ok sind, die letzten Zeichen aber `.h` sein müssen. 
`test.h` und `test.txt.h` werden aufgelistet, `test.h.txt` aber nicht.

`-l` von `wc` gibt nur die Anzahl an Zeilen (newline count) des Outputs von find aus.

```
find /usr/include/ -name '*.h' | xargs cat | grep -E '^[[:space:]]*#include' | wc -l
```

xargs wendet cat auf alle gefundenen dateien an, der Output wird weiter an grep gegeben.

grep durchsucht die Zeilen nach regular expressions. `[[:space:]]` ist ein Platzhalter für alle Zeichen, welche ein Leerzeichen oder Tab einfügen. Durch das `*` sind beliebig viele der Platzhalter möglich, auch keines.  
Damit sicher gegangen wird, dass das `#include` am anfang einer Zeile steht und nicht z.B. in einem Kommentar wird das Zeichen `^` benötigt. Dieses gibt an, dass das folgende Zeichen am Anfang der Zeile stehen muss.

Es sind wohl 3010 include Statements in den Dateien, wobei nur 2994 davon als erstes in einer Zeile stehen.