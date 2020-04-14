#include <stdio.h>
#include <stdlib.h>

// TODO Ausgabe ist irgendwie falsch
// Wiederholung der Felder darf nicht stattfinden!
// mithilfe hiervon: http://de.wikibooks.org/wiki/C-Programmierung:_static_%26_Co. neu schreiben

// Deklarination
char Feld[3][3];
int eingabe;
int gewonnen;
int Spieler;   
int zaehler,i,j;

char getFeld(int pos1, int pos2){
     return Feld[pos1][pos2];
     }

int ueberpruefe(){
    
    // waagerecht gewonnen
        if ( Feld[0][0] == 'X' && Feld[0][1] == 'X' && Feld[0][2] == 'X'){
             gewonnen = 1;
             }
        if ( Feld[1][0] == 'X' && Feld[1][1] == 'X' && Feld[1][2] == 'X'){
             gewonnen = 1;
             }
        if ( Feld[2][0] == 'X' && Feld[2][1] == 'X' && Feld[2][2] == 'X'){
             gewonnen = 1;
             }
        if ( Feld[0][0] == 'O' && Feld[0][1] == 'O' && Feld[0][2] == 'O'){
             gewonnen = 2;
             }
        if ( Feld[1][0] == 'O' && Feld[1][1] == 'O' && Feld[1][2] == 'O'){
             gewonnen = 2;
             }
        if ( Feld[2][0] == 'O' && Feld[2][1] == 'O' && Feld[2][2] == 'O'){
             gewonnen = 2;
             }
       
     // senkrecht gewonnen
        if ( Feld[0][0] == 'X' && Feld[1][0] == 'X' && Feld[2][0] == 'X'){
             gewonnen = 1;
             }
        if ( Feld[1][1] == 'X' && Feld[2][1] == 'X' && Feld[0][1] == 'X'){
             gewonnen = 1;
             }
        if ( Feld[0][2] == 'X' && Feld[1][2] == 'X' && Feld[2][2] == 'X'){
             gewonnen = 1;
             }
        if ( Feld[0][0] == 'O' && Feld[1][0] == 'O' && Feld[2][0] == 'O'){
             gewonnen = 2;
             }
        if ( Feld[1][1] == 'O' && Feld[2][1] == 'O' && Feld[0][1] == 'O'){
             gewonnen = 2;
             }
        if ( Feld[0][2] == 'O' && Feld[1][2] == 'O' && Feld[2][2] == 'O'){
             gewonnen = 2;
             }   
             
    // diagonal gewonnen
        if ( Feld[0][0] == 'X' && Feld[1][1] == 'X' && Feld[2][2] == 'X'){
             gewonnen = 1;
             }
        if ( Feld[2][0] == 'X' && Feld[1][1] == 'X' && Feld[0][2] == 'X'){
             gewonnen = 1;
             }
        if ( Feld[0][0] == 'O' && Feld[1][1] == 'O' && Feld[2][2] == 'O'){
             gewonnen = 2;
             }
        if ( Feld[2][0] == 'O' && Feld[1][1] == 'O' && Feld[0][2] == 'O'){
             gewonnen = 2;
             }
    // draw Game
     for(i=0;i<3;i++){
      for(j=0;j<3;j++){
       if (Feld[i][j] != ' '){ // Wenn alle Felder voll sind liefert dieser Term gewonnen = 0 und nur dann!
        gewonnen = 0;
		} else {
		  gewonnen = 3; 
		  }
       }
     }
        
        // Programm beenden
        if ( gewonnen == 2 ) {
             return 2;				//Spieler2 gewinnt
             }
	    if ( gewonnen == 1 ) {
             return 1;				//Spieler 1 gewinnt
             }
		if ( gewonnen == 0 ) {
		     return 0;				//Draw Game
			 }
		/*else {
		     return 3; 			 // normale Rückgabe
			}*/
        }
        
void Feldanzeigen(){

        printf("\tTIC TAC TOE\n");
        printf("\n");
        printf("\tSpielfeld \tFeldadressen\n");
        printf("\t%-1c, %-1c, %-1c \t 11,12,13 \n",getFeld(0,0),getFeld(0,1),getFeld(0,2));
        printf("\t%-1c, %-1c, %-1c \t 21,22,23 \n",getFeld(1,0),getFeld(1,1),getFeld(1,2));
        printf("\t%-1c, %-1c, %-1c \t 31,32,33 \n",getFeld(2,0),getFeld(2,1),getFeld(2,2));
        printf("\n");
}

void aufEingabeWarten(int Spieler){
     eingabe = 0;
     printf("Spieler %d",Spieler);
     printf(" ist am Zug, bitte eine Feldadresse eingeben. (bsp 11)\n");
     printf("Um das Spiel zu beenden bitte die 0 waehlen\n");
     scanf("%d",&eingabe);
     
     //Dafür sorgen das kein Feld doppelt belegt werden kann
     FeldDoppelt(eingabe);
     
      switch (eingabe)
      {
     case 11:
      if ( Spieler == 1 ){
           Feld[0][0] = 'X';
           
           } else Feld[0][0] = 'O';
           
      break;
     case 12:
      if ( Spieler == 1 ){
           Feld[0][1] = 'X';
           
           } else Feld[0][1] = 'O';
           
      break;
     case 13:
      if ( Spieler == 1 ){
           Feld[0][2] = 'X';
           
           } else Feld[0][2] = 'O';
           
      break;
     case 21:
      if ( Spieler == 1 ){
           Feld[1][0] = 'X';
           
           } else Feld[1][0] = 'O';
           
      break;
      case 22:
      if ( Spieler == 1 ){
           Feld[1][1] = 'X';
           
           } else Feld[1][1] = 'O';
           
      break;
     case 23:
      if ( Spieler == 1 ){
           Feld[1][2] = 'X';
           
           } else Feld[1][2] = 'O';
           
      break;
     case 31:
      if ( Spieler == 1 ){
           Feld[2][0] = 'X';
           
           } else Feld[2][0] = 'O';
           
      break;
      case 32:
      if ( Spieler == 1 ){
           Feld[2][1] = 'X';
           
           } else Feld[2][1] = 'O';
           
      break;
     case 33:
      if ( Spieler == 1 ){
           Feld[2][2] = 'X';
           
           } else Feld[2][2] = 'O';
           
      break;
     case 0:
      exit(0);
      break;
	 case 666:
	  printf("Herzlichen Glueckwunsch, ein Draw Game!\n");
	printf("\n Nochmal? <1> eingeben <0> Spiel endet.");
    scanf("%d",&eingabe);
    if (eingabe == 1) { main(); } else { exit(0); }
	  
	   break;

     default:
      printf("\nKeine korrekte Feldangabe! Oder Feld ist schon belegt!\n");
   }    /* end of switch */


        }
// spieler vertauschen
int werIstDran(){
     if ( Spieler == 1 ) {
          Spieler = 2;
         } else Spieler = 1;
     }
     
int FeldDoppelt(int zahl){
	if ((getFeld(0,0)==(!' '))&&(getFeld(0,1)==(!' '))&&(getFeld(0,2)==(!' '))&&
    (getFeld(1,0)==(!' '))&&(getFeld(1,1)==(!' '))&&(getFeld(1,2)==(!' '))&&
    (getFeld(2,0)==(!' '))&&(getFeld(2,1)==(!' '))&&(getFeld(2,2)==(!' '))){
	   eingabe = 666;
	   
	 }
	 
    switch(zahl){
     case 11: if (getFeld(0,0) != ' ') eingabe = 99; break;
     case 12: if (getFeld(0,1) != ' ') eingabe = 99; break;
     case 13: if (getFeld(0,2) != ' ') eingabe = 99; break;
     case 21: if (getFeld(1,0) != ' ') eingabe = 99; break;
     case 22: if (getFeld(1,1) != ' ') eingabe = 99; break;
     case 23: if (getFeld(1,2) != ' ') eingabe = 99; break;
     case 31: if (getFeld(2,0) != ' ') eingabe = 99; break;
     case 32: if (getFeld(2,1) != ' ') eingabe = 99; break;
     case 33: if (getFeld(2,2) != ' ') eingabe = 99; break;
     default: return zahl; // ist out of stack
    }
    // Bei falscher Eingabe darf der Spieler nochmal, FEHLT!      
} // FeldDoppelt ?

int main(){
  //Initialisierung von Spieler
  Spieler = 1;
  
  //Spielfeld löschen
  for(i=0;i<4;i++){
   for(j=0;j<4;j++){
   Feld[i][j]=' ';   // mit leerzeichen füllen
   }
  }
    
  do {
      //neustart     
        if ( ueberpruefe() == 0 ){
           Feldanzeigen();  
           printf("Herzlichen Glueckwunsch, ein Draw Game!\n");
	       printf("\n Nochmal? <1> eingeben <0> Spiel endet.");
           scanf("%d",&eingabe);
           if (eingabe == 1) { main(); } else { exit(0); }
           }
        if ( ueberpruefe() == 1 || ueberpruefe() == 2 ) {	  
           Feldanzeigen();
           printf("Gewonnen hat Spieler %d",gewonnen); 
           printf("\n Nochmal? <1> eingeben <0> Spiel endet.");
           scanf("%d",&eingabe);
           if (eingabe == 1) { main(); } else { exit(0); }
           }
        // Spiel beginnt!
          Feldanzeigen();
          aufEingabeWarten(Spieler);
          werIstDran();
          /* der Spielschirm wird gelöscht!
          for(i=0;i<27;i++){
          printf("\n");
          }*/
          }  
      while ( ueberpruefe() != 3 );   
  
  scanf("%d");
  return 0;
  exit(0);  
}
