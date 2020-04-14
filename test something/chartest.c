#include <stdio.h>

int main(int argc, char* argv[]) 
{

 int i,j=0;
 char hilf[36];
 for(i=0;i<10;i++){ // alle zahlen
   hilf[i]=i+48;
 }
   for(i=10;i<36;i++){ // alle Buchstaben
     hilf[i]=i+55; 
   }
 while(j<36){
   printf("%c\n",hilf[j]);
   j++;
 }
 
}
