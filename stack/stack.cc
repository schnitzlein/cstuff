#include <iostream>

using namespace std;

struct Element {
  int daten;
  Element* next;	
}

struct Liste {
  Element* top;
  int anzahl;
}

void push(int inhalt, Liste l)
{
	Element* elem; // neues Element erzeugen
	elem = (Element *)malloc(sizeof(Element));
	 elem.daten = inhalt;
	 l.top = elem;
	 elem->next = l.top;
	 
}

void pop(Liste* l)
{
  Element* wegschmeiss = l->top; // (*l).top
  l->top = l->top->next;
  cout << "geloescht wurde" << wegschmeiss.daten;
  free(wegschmeiss);
}


Liste stack;


void main() 
{
  stack = (Liste*)malloc(sizeof(Liste));  //malloc Liste
  stack.anzahl = 0;
  stack.top = NULL;	
  
  int eingabe = "";
  int zahl = 0;

  cout << "Operation angeben: 1=[push] 2=[pop] 3=[show] " << endl;
  cin >> eingabe;
 
  switch(eingabe){
    case 1: cout << "Neue Zahl eingeben: ";
                 cin >> zahl;
                 push(zahl,stack); 
      break;
    case 2:  pop(stack);
      break;
    case 3:  cout << "Anzahl Element im Stack" << stack.anzahl << endl;
  }
	
}
