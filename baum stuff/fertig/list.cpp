#include <stdlib.h>
#include "list.h"
#include "stack.h"
#include "stack.cpp"


TList neueListe(){
  TList liste;
  
  liste.links = create();  //neues objekt erzeugt durch TStackP.create()
  liste.rechts = create(); //neues objekt erzeugt durch TStackP.create()
  
  return liste;
}

TList geheZuPos(int pos, TList liste){
 
 while (pos>(liste.links.anzahl)){ // wenn position größer als letzte position
    if (liste.rechts.anzahl==0) break; //sobald der rechte rand erreicht wird   
    liste.links = push( (top(liste.rechts)) , liste.links); //  gesuchte position groesser ist als die anzahl des linken stacks (auf das die aktuelle position zeigt) ,
    liste.rechts = pop(liste.rechts); 
 }

  while (pos<(liste.links.anzahl)){  
    if (liste.links.anzahl==1) break;  //sobald der linke rand erreicht wird  
    liste.rechts = push( (top(liste.links)) , liste.rechts); // solange die gesuchte position kleine ist als die anzahl des linken stacks (auf das die aktuelle position zeigt) ,
    liste.links = pop(liste.links);                          // wird das obere element von "links" auf "rechts" gesetzt und von "links" gelöscht
  }       

  return (liste); 
}
TList einfuegen(void* elem, TList liste){
  liste.links = push (elem, liste.links);  //Element auf die linke Liste einfügen
  return (liste); 
}
TList loeschen(TList liste){
  liste.links = pop(liste.links);   //loescht das obere Element der linken Liste
  return (liste);
}
void* aktuellesElement(TList liste){
  return top(liste.links);
}
