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
  TZiffer* neuVorKomma;  //erschaffe neues Objekt
  neuVorKomma = (TZiffer*)malloc(sizeof(TZiffer));
  
  neuVorKomma->ziffer = (int)ziffer;	//schreibe der Wert von Ziffer in Ziffer
  neuVorKomma->rechts = zahl->vkStelle->rechts; //Zeiger neuVorKomma->rechts zeig auf Element unmittelbar nach dem Komma
  neuVorKomma->links = zahl->vkStelle; //Zeiger neuVorKomma->links zeigt auf den linken Nachbarn
  zahl->vkStellen = ++(zahl->vkStellen); //erhöhe Anzahl der Vorkommastellen um 1
  zahl->vkStelle->rechts = neuVorKomma; //rechter Zeiger im linken nachbarn zeigt auf das neue Objekt
  neuVorKomma->rechts->links = neuVorKomma; //linker Zeiger im rechten nachbarn muss auf das neue Objekt zeigen

  zahl->vkStelle = neuVorKomma; // ÄNDERE vkStelle, da sich sonst die Nachkommastellen ändern würden
  zahl->aktPos = neuVorKomma;
  return;
}

void zifferNachKomma(char ziffer, TZahl* zahl)
{
  TZiffer* neuNachKomma;  //erschaffe neues Objekt
  neuNachKomma = (TZiffer*)malloc (sizeof (TZiffer));
  
  neuNachKomma->ziffer = (int)ziffer; //schreibe den Wert von ziffer in Ziffer
  neuNachKomma->rechts = zahl->vkStelle->rechts; //Zeiger neuNachKomma.rechts zeigt jetzt auf Element unmittelbar rechts von ihm
  neuNachKomma->links = zahl->vkStelle; //Zeiger neuNachKomma.links zeigt auf Element unmittelbar vor dem Komma
  zahl->nkStellen = ++(zahl->nkStellen); //erhöhe Anzahl der Nachkommastellen in zahl um 1
  zahl->vkStelle->rechts = neuNachKomma; // rechter Zeiger im linken Nachbarn zeigt auf das neue Objekt
  neuNachKomma->rechts->links = neuNachKomma; //Zeiger in vkStelle->rechts->links muss auf da neue Objekt zeigen.

  
  return; //ändere vkStelle NICHT, da sich nach dem Komma was ändert, nicht davor
}

TZiffer* posLinks(TZahl* zahl)
{
  if (zahl->aktPos->links){ // solange linkes Element von aktPos auf ein nicht-leeres element zeigt
    while (zahl->aktPos->links)
      zahl->aktPos = zahl->aktPos->links; // setze aktPos auf dieses Objekt
  }
  return zahl->aktPos; //gib aktPos zurück
}

TZiffer* posRechts(TZahl* zahl)
{
  if (zahl->aktPos->rechts){ //solange rechtes Element von aktPos auf ein nicht-leeres Objekt zeigt
  while (zahl->aktPos->rechts)
      zahl->aktPos = zahl->aktPos->rechts; // setze aktPos auf dieses Objekt
  }
  return zahl->aktPos; //gib aktPos zurück
}

TZiffer* nachRechts(TZahl* zahl)
{
   if (zahl->aktPos->rechts!=0){ // zeigt aktPos->rechts auf ein nicht-leeres Objekt
     zahl->aktPos = zahl->aktPos->rechts; // setze zeiger von aktPos auf diese Objekt
	 return zahl->aktPos; //gib aktPos zurück
   }
   return NULL;//wenn nicht, gib NULL zurück
   //Unterschied zu posRechts: mache dies nur EINMAL
}

TZiffer* nachLinks(TZahl* zahl)
{
  if (zahl->aktPos->links!=0){ //zeigt aktPos->links auf ein nicht-leeres Objekt
    zahl->aktPos = zahl->aktPos->links; //setze Zeiger von aktPos auf dieses Obejkt
	return zahl->aktPos; // gib aktPos zurück
  }
  return NULL;
  //Unterschied zu posLinks: mache dies nur EINMAL
   //wenn nicht, gib NULLzurück
}



void normalisiere(TZahl* zahl)
{
 zahl->aktPos = posLinks(zahl); // setze aktPos auf das linkeste Element
 while (zahl->aktPos->rechts!=0 && zahl->aktPos->rechts->ziffer==0){  //solange vom linkesten element der rechte nachbar die Ziffer 0 enthält...
   zahl->aktPos = zahl->aktPos->rechts;   // zeige auf den rechten Nachbarn
   zahl->vkStellen = --(zahl->vkStellen); // verringere Anzahl der vkStellen in TZahl* zahl
   free(zahl->aktPos->links); // gib speicherbereich des linkesten Elements frei
   zahl->aktPos->links = NULL; // setze den Zeiger auf dieses Element Null
 }
 zahl->aktPos = posRechts(zahl);  // setze aktPos auf das rechteste Element
 while (zahl->aktPos->links!=0 && zahl->aktPos->links->ziffer==0){ // solange dies einen linken Nachbarn hat, dessen Ziffer 0 ist...
   zahl->aktPos = zahl->aktPos->links; // setze aktPos auf dieses Element
   zahl->nkStellen = --(zahl->nkStellen); // verringere nkStellen in TZahl* zahl
   free(zahl->aktPos->rechts); // gib speicherbereich des rechtesten Elements frei
   zahl->aktPos->rechts = NULL; // setze Zeiger auf dieses Element Null
 }

 return;
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

