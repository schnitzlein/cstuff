#ifndef __LIST__

#define __LIST__
#include "stack.h"

struct TList
{
  TStackP links;   
  TStackP rechts;  
};

TList neueListe();
TList geheZuPos(int pos, TList liste);
TList einfuegen(void* elem, TList liste);
TList loeschen(TList liste);
void* aktuellesElement(TList liste);


#endif
