#ifndef __STACK__

#define __STACK__

struct TStackP
{
  void* info;
  TStackP* p;
  int anzahl;
};

TStackP create();
TStackP push(void* info, TStackP oldStack);
TStackP pop(TStackP oldStack);
void* top(TStackP stack);
int groesseStack(TStackP stack);

#endif
