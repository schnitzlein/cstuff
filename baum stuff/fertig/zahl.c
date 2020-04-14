#include <stdio.h>
#include <stdlib.h>

struct TZiffer {
  char ziffer;
  TZiffer* links;
  TZiffer* rechts;
};

struct TZahl {
  TZiffer* vkStelle; // Vorkommastelle
  int nkStellen;     // Nachkommastellen
  int vkStellen;     // Vorkommastellen
  TZiffer* aktPos;   // aktuelle Position in der liste
};

// Erzeugt den Dezimalbrucch 0.0
TZahl* erzeugeNull()
{
  TZahl* Null;
  
  Null = (TZahl*)malloc(sizeof(TZahl));
  Null->vkStellen = 0;
  Null->nkStellen = 0;
  // Vorkommastelle mit 0 initialisieren
  Null->vkStelle = (TZiffer*)malloc(sizeof(TZiffer));
  Null->vkStelle->ziffer = 0;
  Null->vkStelle->links = 0;
  // Nachkommastelle erzeugen
  Null->vkStelle->rechts = (TZiffer*)malloc(sizeof(TZiffer));
  Null->vkStelle->rechts->links = Null->vkStelle;
  Null->vkStelle->rechts->rechts = 0;
  Null->vkStelle->rechts->ziffer = 0;
  
  return Null;
}

// Gibt 1 zurueck, falls aktPos auf die erste Nachkommastelle zeigt
int ersteNKStelle(TZahl* zahl)
{
  return zahl->aktPos == zahl->vkStelle->rechts;
}

void zifferVorKomma(char ziffer, TZahl* zahl)
{
  // if ( posLinks(zahl) ) nachLinks(zahl);
  zahl.vkStelle.ziffer = ziffer;
  
}

void zifferNachKomma(char ziffer, TZahl* zahl)
{
}

TZiffer* posLinks(TZahl* zahl)
{
}

TZiffer* posRechts(TZahl* zahl)
{
}

TZiffer* nachRechts(TZahl* zahl)
{
}

TZiffer* nachLinks(TZahl* zahl)
{
}

void normalisiere(TZahl* zahl)
{
}

// Zum Erzeugen eines Zahlenobjekts aus einem Text
// Zum Beispiel: text = "12.500600"
TZahl* read(char* text)
{
  TZahl* zahl;
  
  zahl = erzeugeNull();
  
  while(*text != '.' && *text) {
    zifferVorKomma(*text - '0',zahl);
    text++;
  }
  
  if(!*text)
    return zahl;
  
  while(*text)
    text++;
  
  text--;
  while(*text != '.') {
    zifferNachKomma(*text - '0',zahl);
    text--;
  }
  
  return zahl;
}

// Zum Ausgeben der Ziffern eines Zahlenobjekts einschliesslich
// des Kommas
void druckeZahl(TZahl* zahl)
{
  TZiffer* ziffer;
  
  ziffer = posLinks(zahl);
  
  do {
    if(ersteNKStelle(zahl))
      printf(".");
    printf("%c",ziffer->ziffer + '0');
    ziffer = nachRechts(zahl);
  }while(ziffer);
}

int main(int argc, char* argv[])
{
  char eingabe[1024];
  TZahl* zahl;
  
  // Zum Testen der Implementierung. Die eingegebene Zahl darf nur aus
  // Ziffern und einem Punkt bestehen und sollte einen Vor- und Nachkommaanteil 
  // haben, die durch einen Punkt getrennt sind. Zum Beispiel: 47.11
  gets(eingabe);
  zahl = read(eingabe);
  druckeZahl(zahl);
  printf("\n");
  normalisiere(zahl);
  druckeZahl(zahl);
  printf("\n");
}
