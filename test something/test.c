#include <stdio.h>

void main(){
  int a,b;
  a=1;
  b=1;
  printf("a++ ist: %d\n",a++); // a=1
  printf("++a ist: %d\n",++a); // a=3
  printf("\n");
  printf("%d",(a < b ? b : a));     // bedingte anweisung
  scanf("%d",&b);   
}
