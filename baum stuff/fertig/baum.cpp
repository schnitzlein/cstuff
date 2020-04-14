#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int TElem;  // Typ der Werte, die in einem Knoten gespeichert werden.

////////////////////////////////////////////////////////////////////////////////
// TKnoten repräsentiert einen Knoten des Baums.
// 
////////////////////////////////////////////////////////////////////////////////
struct TKnoten {
  TKnoten* sohn;   // Verweis auf den Sohn des Knotens (0, falls kein Sohn)
  TKnoten* bruder; // Verweis auf den rchten Bruder des Knotens (0, falls kein bruder)
  TElem wert;      // Gespeicherter Wert
};

////////////////////////////////////////////////////////////////////////////////
// TBaum repräsentiert einen Baum.
// 
////////////////////////////////////////////////////////////////////////////////
struct TBaum {
    TKnoten* wurzel; // Verweis auf den Wurzelknoten des Baums (0, falls Baum leer)
};

// Erzeugt einen neuen leeren Baum
TBaum neuerBaum()
{
  TBaum baum;
  
  baum.wurzel = 0;
  return baum;
}

// Fügt einen neuen Knoten in den Baum an der Adresse 'adr' ein.
// adr ist eine Zeichenkette bestehend aus Zahlen, die durch einen Punkt
// getrennt sind. Andere Zeichen duerfen nicht enthalten sein. 
// Zum Beispiel: "", "0", "0.25.1"
TBaum neuerKnoten(TBaum baum, const char* adr, TElem wert)
{
  TKnoten* aktueller = baum.wurzel;// Position im Baum, an der der neue Knoten
                                   // eingefügt werden muss.
  TKnoten* letzter = 0;            // unmittelbarer Vorgaenger des neu eingefuegten
                                   // Knotens (entweder Vater oder linker Bruder)
  TKnoten* neuerKnoten;            // Einzufuegender Knoten
  int brueder;                     // zaehlt die Nummer in der Adresse 
  int ersterSohn;                  // merken, ob aktuelle Position im Baum einen 
                                   // linken Bruder hat
  
  neuerKnoten = (TKnoten*)malloc(sizeof(TKnoten));
  neuerKnoten->sohn = 0;
  neuerKnoten->bruder = 0;
  neuerKnoten->wert = wert;

  // Sonderfall: Adresse ist Epsilon
  if(!*adr) {
    neuerKnoten->sohn = baum.wurzel;
    baum.wurzel = neuerKnoten;
    return baum;
  }
  
  // Sucht die Position im Baum, an der der neue Knoten einzufuegen ist
  while(*adr) {
    // Fuer jede Nummer in der Adresse einen Sohn absteigen
    if(!aktueller) {
      printf("Fehler in der Adresse.\n");
      exit(1);
    }
    letzter = aktueller;
    aktueller = aktueller->sohn;
    ersterSohn = 1;
    
    brueder = atoi(adr);
    while(brueder) {
      // Um Anzahl 'brueder' viele Knoten nach rechts gehen
      if(!aktueller) {
        printf("Fehler in der Adresse.\n");
        exit(1);
      }
      letzter = aktueller;
      aktueller = aktueller->bruder;
      ersterSohn = 0;
      brueder--;
    } 

    // Vorderste Nummer aus der Adresse entfernen
    adr = adr + strspn(adr,"0123456789");
    if(*adr != '.' && *adr != '\0') {
      printf("Fehler in der Adresse: %s\n", adr);
      exit(1);
    }
    if(*adr)
      adr++;
  }
  
  // Neuen Knoten an der gefundenen Position einfuegen.
  neuerKnoten->bruder = aktueller;
  if(!ersterSohn)
    letzter->bruder = neuerKnoten;
  else
    letzter->sohn = neuerKnoten;
  
  return baum;
}

// Praefixlinearisierung des Baums ausgeben
void prelin(TBaum baum) 
{
  TBaum aktuell;
  printf("%d ", baum.wurzel->wert);
  if (baum.wurzel->sohn != NULL){
    aktuell.wurzel = baum.wurzel->sohn;  // gehe alle söhne durch
    prelin(aktuell);
  }
  if (baum.wurzel->bruder != NULL){      // gehe alle brüder durch
    aktuell.wurzel = baum.wurzel->bruder;
    prelin(aktuell);
  } 
  else if (baum.wurzel->sohn == NULL && baum.wurzel->bruder == NULL); // ende
}

// Erzeugt einen Baum nach dem im Uebungsblatt beschriebenen Schema.
// Es wird zunächst die Adresse abgefragt, an der ein neuer Knoten
// eingefuegt werden soll (die Eingabe der leeren Zeichenkette steht
// fuer Epsilon). Anschließend wird der Wert abgefragt, der in diesem
// Knoten gespeichert werden soll. Ist der Wert negativ, wird der Knoten
// nicht erzeugt und die Praefixlinearisierung des bis dahin eingegebenen
// Baums ausgegeben.
//
// Eingabebeispiel:
// Adresse? <Enter>
// Wert? 2<Enter>
// Adresse? 0<Enter>
// Wert? 5<Enter>
// Adresse? 1<Enter>
// Wert? 3<Enter>
// Adresse? 1.0<Enter>
// Wert? 4<Enter>
// Adresse? 0<Enter>
// Wert? -1<Enter>
// Erzeugt den Baum:  2
//                   / \
//                  5   3
//                      |
//                      4
int main(int argc, char* argv[])
{
  TBaum baum = neuerBaum(); // Baum, dessen Preafixlinearisierung ausgegeben werde soll
  char adresse[256];        // Zum Aufbauen des Baums
  char wertEingabe[256];    // Zum Aufbauen des Baums
  TElem wert;               // Integerwert der Zeichenkette wertEingabe

  printf("Adresse? ");
  gets(adresse);
  printf("Wert? ");
  gets(wertEingabe);
  wert = atoi(wertEingabe);

  while(wert >= 0) {
    baum = neuerKnoten(baum,adresse,wert);
    printf("Adresse? ");
    gets(adresse);
    printf("Wert? ");
    gets(wertEingabe);
    wert = atoi(wertEingabe);
  }

  printf("Linearisierung: ");
  prelin(baum);
}
