#include <stdio.h>

void ausgabe(char* e)
{ int i=0;
  while(i < strlen(e)){
  printf("%c",e[i]);
  i++;
  }

}

int main (void)
{
  char text[255];
  printf("Eingabe: ");
  scanf("%s",text);
  ausgabe(text);
}
 
