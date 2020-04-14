#include <stdlib.h>
#include "stack.h"

TStackP create()
{
  TStackP stackNeu;
  
  stackNeu.info = 0;
  stackNeu.p = 0;
  stackNeu.anzahl = 0;
  
  return stackNeu;
}

TStackP push(void* info, TStackP oldStack)
{
  TStackP* newElem = (TStackP*)malloc(sizeof(TStackP));

  newElem->p = oldStack.p;
  oldStack.p = newElem;
  newElem->info = info;
  oldStack.anzahl++;
  return oldStack;
}

TStackP pop(TStackP oldStack)
{
  TStackP* prev;

  // Ist der Stapel leer?
  if(!oldStack.p)
    return oldStack;

  prev = oldStack.p;
  oldStack.p = oldStack.p->p;
  free(prev); // Achtung: Der Inhalt (*info) wird damit nicht freigegeben.
  oldStack.anzahl--;
  return oldStack;
}

void* top(TStackP stack)
{
  if(stack.p)
    return stack.p->info;
  return 0;
}

int groesseStack(TStackP stack)
{
  return stack.anzahl;
}
