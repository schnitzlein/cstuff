#include <stdio.h>
#include <string.h>

struct Datum
{unsigned jahr,monat,tag;};

struct Person{
       char name[40],vorname[40];
       char geschlecht;
       struct Datum geb;
       struct Datum sterb;
       float gewicht;
       unsigned kinderzahl;
};

int main()
{
struct Person p1;
struct Person *zeiger;
strcpy(p1.name,"Meier");
strcpy(p1.vorname,"Fritz");
p1.geschlecht='m';
p1.gewicht=85.2;
p1.geb.jahr=1965;
p1.geb.monat=12;
p1.geb.tag=6;
p1.kinderzahl=1;

p1.sterb.jahr=2008;
p1.sterb.monat=02;
p1.sterb.tag=5;

zeiger=&p1;
zeiger->geb.monat=11;
//zeiger->geb.monat=11;
zeiger->gewicht=44.45;

printf("Geschlecht: %c",p1.geschlecht);
printf("\nGewicht: %f",zeiger->gewicht);
printf("\nGebJahr: %d.%d.%d",p1.geb.tag,p1.geb.monat,p1.geb.jahr);
printf("\nInhalt von Zeiger ist: %d",*zeiger);

//printf("Geschlecht: %c",p1.geschlecht);
sleep(5000);
/*hier weitere Anweisungen*/
return 0;
}
