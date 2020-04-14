// Addier natürliche Zahlen
#include <stdlib.h>
#include <stdio.h>
#include <math.h>


/* Diese Methode addiert zahlen aufeinander.
   Weil ich das schön finde.
   */
int fak=0;
int summe;
int a=10;

int fakultaet(int pn){
 int rw=0;
 //Abbruch Bedingung
 if (pn == 0){ rw=1;}
 else {
      fak = (pn * fakultaet(pn-1));
  }
  
 return fak+rw;
}//fakultaet

main(){ 
    scanf("%d",&summe);
    printf("Fakultaet von %d ist:  %d",summe,fakultaet(summe));
    scanf("%d",&summe);
    exit(0);  
}
