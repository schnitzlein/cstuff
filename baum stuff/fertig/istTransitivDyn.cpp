#include <stdio.h>
#include <stdlib.h>

int istTransitiv(int* adjazenzMatrix[], int groesse)
{
  for(int i = 0; i < groesse; i++)
    for(int j = 0; j < groesse; j++)
      for(int k = 0; k < groesse; k++)
        if(adjazenzMatrix[i][j] && adjazenzMatrix[j][k] && !adjazenzMatrix[i][k])
          return 0;
  return 1;
}

int main(int argc, char* argv[])
{
  int a;  // zum Abfragen der Relation
  int b;  // zum Abfragen der Relation
  int groesse;          // zum Abfragen der Groesse der Matrix 
  int** adjazenzMatrix; // Zeiger auf das zu erzeugende Zeigerfeld

  // Groesse abfragen
  printf("Groesse? ");
  scanf("%d",&groesse);

  
  //////////////////////////////////////////////////////////
  // Hier den Programmcode zum Erzeugen der Matrix einfügen
  // Speicherarray erzeugen, einzelenen Listen im Speicher erzeugen
  // Wenn Rand der Spalte erreicht neue Zeile, Zeile++
  // Wenn alle Zeile voll, beenden
  //////////////////////////////////////////////////////////
  adjazenzMatrix = (int**)malloc(sizeof(int*));
  for(int i=0;i<groesse;i++)
    adjazenzMatrix[i] = (int*)malloc(sizeof(int));
    
  for(int i=0;i<groesse;i++){  //zeile
   for(int j=0;j<groesse;j++){ //spalte
     adjazenzMatrix[i][j] = 0;
   }
  }
  
  // Relation abfragen - wie bereits in Aufgabenblatt 10
  while(1) {
    printf("a? ");
    scanf("%d",&a);
    if(a < 0 || a >= groesse)
      break;
    printf("b? ");
    scanf("%d",&b);
    if(b < 0 || b >= groesse)
      break;
    
    adjazenzMatrix[a][b] = 1;
  }
  
  printf("\nIstTransitiv: %d\n",istTransitiv(adjazenzMatrix,groesse));

  //////////////////////////////////////////////////////////////////
  // Hier den Programmcode zum Freigeben des angeforderten Speichers einfuegen
  //////////////////////////////////////////////////////////////////
  for(int i=0;i < groesse;i++){ //alle einzelnen Listen löschen
    free(adjazenzMatrix[i]);
  }
  free(adjazenzMatrix);
}
