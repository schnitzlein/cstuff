// felder
#include <stdio.h>
#include <stdlib.h>

main(){
  int *pointer;
  int jolanda = 5;
  int feld[6];
  int x;
  pointer = &jolanda;
  
  printf("\nDer Wert von 'jolanda' ist %d",jolanda);
  printf("\nDie Adresse von 'jolanda' ist %u",pointer);
  printf("\nDie Grosse von 'pointer' %u",sizeof(pointer));
  printf("\n Pointer zeigt auf: %d",*pointer);

//sleep(10000);

for(x=0;x<7;x++){
feld[x]=x*2;
pointer = &feld[x];
  printf("\n An der Adresse: %d und sein Wert ist: %d",x,*pointer);
  //*pointer++;
  }
sleep(10000);   
}//main
