#include <stdio.h>
#include <stdlib.h>

main(){
  FILE *datei;
  char c;
  char dname[20] = "test.txt";
  datei = fopen(dname, "r");
  
  if ((datei = fopen(dname, "r")) == NULL)
  {
  printf("\nDatei konnte nicht ge�ffnet"
  " werden! Programmabbruch, bitte"
  " <return> druecken:\n");
  c = getchar();
  exit(1);
  }
}
