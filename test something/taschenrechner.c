// Taschenrechner

#include <stdio.h>
#include <string.h>

float z1,z2;
char operator;

int main(){
     
     /*printf("Eingabe von Zahl1: ");
     scanf("%f",&z1,"\n");
     printf("Eingabe von Zahl2: ");
     scanf("%f",&z2,"\n");
     printf("Angabe der Rechenoperation (+,-,*,/):");
     scanf("%c",&operator,"\n");*/
       
       z1=2;
       z2=2;
       operator='/';
       
       switch(operator) {
                        
         case '+': printf(" Das Ergebnis ist: %f %f",z1+z2);
                   scanf("%f");
              break;
         case '-': printf(" Das Ergebnis ist: %f %f",z1-z2);
                   scanf("%f");
              break;
         case '*': printf(" Das Ergebnis ist: %f %f",z1*z2);
                   scanf("%f");
              break;
         case '/': printf(" Das Ergebnis ist: %f %f",z1/z2);
                   scanf("%f");
              break;
         default: printf("Programmfehler!");
                  exit(1);
                  break;
                        }// switch 

     } // main
