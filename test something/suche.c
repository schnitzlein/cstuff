/* Programm untersucht zeichenkette nach zeichenkette "schiff" */

#include <stdio.h>
#include <string.h>   // fuer Zeichenketten-Manipulation

  main () 
  {
     char feld[20];
     char text[8];
     int *ptr;     // pointer
     int laenge=0 ,i,  j = 0;
     
     
     // Zuweisung ausgeschrieben
     text[0] = 's';
     text[1] = 'c';
     text[2] = 'h';
     text[3] = 'i';
     text[4] = 'f';
     text[5] = 'f';
     text[6] = '\0';  //Termination des Strings, da sonst Speichermüll angezeigt wird
     
  
     scanf("%s",feld);
  
     printf("Zu suchender String: %s",text,"\n");
     laenge = strlen(text);
     printf("\nLaenge von zusuchender String: %i",laenge);
     
     for(i=0;i<=laenge;i++){         
           if ( text[i] == feld[i] ){
                printf("\ngefunden %c", feld[i]);
           }
     }      
     // Zum lesn des programms
     scanf("%d");
 return(0);    
}    
       
