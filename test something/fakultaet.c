// Fakultaet

#include <stdio.h>
#include <stdlib.h>

// Variablen Teil
int zahl, erg;
int fakultaet(int welche){
    zahl = welche;
    erg = 1;
    for(int i=0,zahl>0,i++){
    erg = erg * zahl;
    fakultaet(zahl); 
    }
    return erg;
}// fakultaet

main (){
     scanf("%d",&zahl);
     fakultaet(zahl);
     printf("Die fakultaet betraegt: %d",erg);
 
 
     
     scanf("%d",&zahl);
}// main
