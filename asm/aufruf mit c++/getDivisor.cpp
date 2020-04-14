//getDivisor.cpp
#include <iostream>

using namespace std;
extern "C" int getDivisorCount_a(int);
extern "C" void getDivisorCount_b(int,int*);
int main (void)
{
  int ein;
  int aus;
  cout<<"Geben Sie eine Zahl ein: ";
  cin>>ein;
  cout<<"Anzahl der ganzzahligen Teiler beträgt mit dem ersten Programm: "<<getDivisorCount_a(ein)<< endl;
  getDivisorCount_b(ein,&aus);
  cout<<"Anzahl der ganzzahligen Teiler beträgt mit dem zweiten Programm: "<< aus << endl;  

  return 0;
}
