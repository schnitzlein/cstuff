#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "list.cpp"

/*******************************************************************************
* Das Ein-/Ausgabeverhalten der main-Funktion darf nicht verändert werden.
* e <Enter>                 beendet das Programm.
* i <Enter> <Zahl>  <Enter> speichert <Zahl> an aktueller Position in der Liste.
* d <Enter>                 loescht aktuelles Element aus der Liste.
* c <Enter>                 Gibt aktuelles Listenelement aus.
* g <Enter> <Zahl> <Enter>  Macht Element an Position <Zahl> zum aktuellen Element.
*******************************************************************************/
int main(int argc, char* argv[])
{
  int* val;
  int pos;
  char command[8];
  TList liste;
  
  liste = neueListe();
  while(*command != 'e')
  {
    printf("\ncmd? ");
    scanf("%s",&command);
    switch(*command)
    {
      case 'i' : val = (int*)malloc(sizeof(int));
                 printf("val? ");
                 scanf("%d",val);
                 liste = einfuegen(val,liste);
                 break;
      case 'd' : val = (int*)aktuellesElement(liste);
                 if(val)
                   free(val);
                 else
                   printf("\nKein Element zum Loeschen.");
                 liste = loeschen(liste);
                 break;
      case 'c' : if((val = (int*)aktuellesElement(liste)))
                   printf("\n%d",*val);
                 else
                   printf("\nKein aktuelles Element");
                 break;
      case 'g' : printf("pos? ");
                 scanf("%d",&pos);
                 liste = geheZuPos(pos,liste);
                 break;
    }
  }
}

