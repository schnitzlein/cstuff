#include <stdlib.h>
#include <stdio.h>

float a,b,c,y;
char rechenzeichen;

int main()
{
    do //Schleife
    {
    //Erfragen von Zahl 1 & 2
         printf("Bitte geben Sie die erste Zahl ein: \n");
         scanf("%f", &a);
         printf("Bitte geben Sie die zweite Zahl ein: \n");
         scanf("%f", &b);
         
         //Nach der Rechenoperation fragen
         printf(" + - * / \n");
         scanf("%c", &rechenzeichen);
         printf("%c", &rechenzeichen);
         scanf("%c");
         
         switch(rechenzeichen)
         {
                              case '+': c=a+b;
                              printf("%f + %f = %f", a,b,c);
                              printf("\n \nWeiterrechnen <1> Stop <0> \n");
                              scanf("%f", &y);
                              break;
                              case '-': c=a-b;
                              printf("%f - %f = %f", a,b,c);
                              printf("\n \nWeiterrechnen <1> Stop <0> \n");
                              scanf("%f", &y);
                              break;
                              case '*': c=a*b;
                              printf("%f * %f = %f", a,b,c);
                              printf("\n \nWeiterrechnen <1> Stop <0> \n");
                              scanf("%f", &y);
                              break;
                              case '/': c=a/b;
                              printf("%f / %f = %f", a,b,c);
                              printf("\n \nWeiterrechnen <1> Stop <0> \n");
                              scanf("%f", &y);
                              break;
                              
                              default: printf("%f ??? %f = kein gültiges Rechenzeichen", a,b);
                                       printf("\n \nNochmals versuchen <1> Stop <0> \n");
                                       scanf("%f", &y);
                              break;
                              }                        
                              }while (y!=0);
                              return 0;
                              }         
         
