#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
  

int main(int argc, char* argv[])
{
  char dateiname[256];  // Name der Datei, die das Labyrinth enthaelt
  
  // Dateinamen abfragen
  scanf("%s",dateiname);

  ////////////////////////////////////////////////
  // Bitte ergänzen Sie ihre Implementierung hier
  ////////////////////////////////////////////////
  
	ifstream inputFile;
		
	inputFile.open(dateiname);
	
    if(inputFile)
    { 
                 
      //bestimmt zuerst die spalten und zeilenanzahl           
      int x=0;
	  int y=1;
      char t;
	  while(!inputFile.eof()) 
	  { 
	    inputFile.get(t);
	    if (t=='\n') {y++;}
        if (y==1) {x++;}
	  }
	inputFile.close();


	
	char lab [y][x];//matrix für das labyrinth erzeugen
	
	
    ifstream inputFile;//datei neu laden
    inputFile.open (dateiname);
    
    //einlesen aus .txt
	for (int i = 0; i < y; i++)
	{
       for (int j = 0; j <x; j++)
       {
	     inputFile >> lab[i][j];
       }
    }
	inputFile.close();
	
	
    //ausgabe des labyrinths
	for (int i = 0; i < y; i++)
	{
        for (int j = 0; j < x; j++){
		cout << lab[i][j];} cout<< endl;
    }

    //starposition setzen
    int akt_x=1;
    int akt_y=y-1;
    
    //anfangsrichtung ist Norden
    char kompas='N';
    
    //vector der den weg speichert
    vector <char> derWeg;
           
while(1) //endlosspaghetti
    {
    //abbruch falls die zielposition gefunden wird          
    if((akt_x==x-2)&&(akt_y==0)){
      cout<<"Weg gefunden"<<endl;
                                 
      //ausgabe des weges aus dem vector 
      cout << "DerWeg : ";
      for(int i =0;i <derWeg.size(); i++)
      cout  << derWeg[i] ;
      cout << endl;break;}
    
    //überprüft die himmelsrichtung und geht dementsprechend die möglichen wegrichtugen durch       
    switch (kompas){
      case('N'):{ //gehtsLinks?
                 if (lab[akt_y][akt_x-1]!='*'){//wenn ja
                   kompas='W';//setzt kompas richtung Westen
                   akt_x--;//geht auf die position links von der aktuellen position aus                   
                   if (lab[akt_y][akt_x]=='.'){//prüft ob hier schonmal war
                     lab[akt_y][akt_x]='o';//da noch nicht, setzt marker
                     derWeg.push_back('L');//schreibt den schritt auf
                   }
                   else{//falls schonaml hier war
                     
                     derWeg.pop_back();//entfernt letzten schritt von der liste
                   }
                   
                   break;
                 }
                 
                //gehtsHoch?
                if (lab[akt_y-1][akt_x]!='*'){
                  kompas='N';
                  akt_y--;
                  if (lab[akt_y][akt_x]=='.'){//prüft ob hier schonmal war
                     lab[akt_y][akt_x]='o';//da noch nicht, setzt marker
                     derWeg.push_back('O');//schreibt den schritt auf
                   }
                   else{
                     
                     derWeg.pop_back();
                   }
                  break;
                }
                
                //gehtsRechts?
                if (lab[akt_y][akt_x+1]!='*'){
                  kompas='O';                            
                  akt_x++;
                  if (lab[akt_y][akt_x]=='.'){//prüft ob hier schonmal war
                     lab[akt_y][akt_x]='o';//da noch nicht, setzt marker
                     derWeg.push_back('R');//schreibt den schritt auf
                   }
                   else{
                     
                     derWeg.pop_back();//entfernt letzten schritt von der liste
                   }
                  break;
                }
                
                //gehtsRunter?
                  if (lab[akt_y+1][akt_x]!='*'){
                    kompas='S';
                    akt_y++;
                    if (lab[akt_y][akt_x]=='.'){//prüft ob hier schonmal war
                     lab[akt_y][akt_x]='o';//da noch nicht, setzt marker
                     derWeg.push_back('U');//schreibt den schritt auf
                   }
                   else{
                     
                     derWeg.pop_back();//entfernt letzten schritt von der liste
                   }
                    break;
                  }
                  }
      case('O'):{//gehtsHoch?
                if (lab[akt_y-1][akt_x]!='*'){
                  kompas='N';
                  akt_y--;
                  if (lab[akt_y][akt_x]=='.'){//prüft ob hier schonmal war
                     lab[akt_y][akt_x]='o';//da noch nicht, setzt marker
                     derWeg.push_back('O');//schreibt den schritt auf
                   }
                   else{
                     
                     derWeg.pop_back();
                   }
                  break;
                }
                //gehtsRechts?
                if (lab[akt_y][akt_x+1]!='*'){
                  kompas='O';                            
                  akt_x++;
                  if (lab[akt_y][akt_x]=='.'){//prüft ob hier schonmal war
                     lab[akt_y][akt_x]='o';//da noch nicht, setzt marker
                     derWeg.push_back('R');//schreibt den schritt auf
                   }
                   else{
                     
                     derWeg.pop_back();//entfernt letzten schritt von der liste
                   }
                  break;
                }
                
                //gehtsRunter?
                if (lab[akt_y+1][akt_x]!='*'){
                    kompas='S';
                    akt_y++;
                    if (lab[akt_y][akt_x]=='.'){//prüft ob hier schonmal war
                     lab[akt_y][akt_x]='o';//da noch nicht, setzt marker
                     derWeg.push_back('U');//schreibt den schritt auf
                   }
                   else{
                    
                     derWeg.pop_back();//entfernt letzten schritt von der liste
                   }
                    break;
                  }
                //gehtsLinks?
                if (lab[akt_y][akt_x-1]!='*'){
                   kompas='W';
                   akt_x--;
                   
                   if (lab[akt_y][akt_x]=='.'){//prüft ob hier schonmal war
                     lab[akt_y][akt_x]='o';//da noch nicht, setzt marker
                     derWeg.push_back('L');//schreibt den schritt auf
                   }
                   else{
                    
                     derWeg.pop_back();
                   }
                   
                   break;
                 }
                 }
                
                 
      case('S'):{//gehtsRechts?
                if (lab[akt_y][akt_x+1]!='*'){
                  kompas='O';                            
                  akt_x++;
                  if (lab[akt_y][akt_x]=='.'){//prüft ob hier schonmal war
                     lab[akt_y][akt_x]='o';//da noch nicht, setzt marker
                     derWeg.push_back('R');//schreibt den schritt auf
                   }
                   else{
                     
                     derWeg.pop_back();//entfernt letzten schritt von der liste
                   }
                  break;
                }
                
                //gehtsRunter?
                if (lab[akt_y+1][akt_x]!='*'){
                    kompas='S';
                    akt_y++;
                    if (lab[akt_y][akt_x]=='.'){//prüft ob hier schonmal war
                     lab[akt_y][akt_x]='o';//da noch nicht, setzt marker
                     derWeg.push_back('U');//schreibt den schritt auf
                   }
                   else{
                     
                     derWeg.pop_back();//entfernt letzten schritt von der liste
                   }
                    break;
                  }
                  
                //gehtsLinks? 
                if (lab[akt_y][akt_x-1]!='*'){
                   kompas='W';
                   akt_x--;
                   
                   if (lab[akt_y][akt_x]=='.'){//prüft ob hier schonmal war
                     lab[akt_y][akt_x]='o';//da noch nicht, setzt marker
                     derWeg.push_back('L');//schreibt den schritt auf
                   }
                   else{
                    
                     derWeg.pop_back();
                   }
                   
                   break;
                 }
                 
                //gehtsHoch?
                if (lab[akt_y-1][akt_x]!='*'){
                  kompas='N';
                  akt_y--;
                  if (lab[akt_y][akt_x]=='.'){//prüft ob hier schonmal war
                     lab[akt_y][akt_x]='o';//da noch nicht, setzt marker
                     derWeg.push_back('O');//schreibt den schritt auf
                   }
                   else{
                     
                     derWeg.pop_back();
                   }
                  break;
                }
                }
                
      case('W'):{//gehtsRunter?
                if (lab[akt_y+1][akt_x]!='*'){
                    kompas='S';
                    akt_y++;
                    if (lab[akt_y][akt_x]=='.'){//prüft ob hier schonmal war
                     lab[akt_y][akt_x]='o';//da noch nicht, setzt marker
                     derWeg.push_back('U');//schreibt den schritt auf
                   }
                   else{
                     
                     derWeg.pop_back();//entfernt letzten schritt von der liste
                   }
                    break;
                  }
                  
                //gehtsLinks?
                if (lab[akt_y][akt_x-1]!='*'){
                   kompas='W';
                   akt_x--;
                   
                   if (lab[akt_y][akt_x]=='.'){//prüft ob hier schonmal war
                     lab[akt_y][akt_x]='o';//da noch nicht, setzt marker
                     derWeg.push_back('L');//schreibt den schritt auf
                   }
                   else{
                     
                     derWeg.pop_back();
                   }
                   
                   break;
                 }
                 
                //gehtsHoch?
                if (lab[akt_y-1][akt_x]!='*'){
                  kompas='N';
                  akt_y--;
                  if (lab[akt_y][akt_x]=='.'){//prüft ob hier schonmal war
                     lab[akt_y][akt_x]='o';//da noch nicht, setzt marker
                     derWeg.push_back('O');//schreibt den schritt auf
                   }
                   else{
                    
                     derWeg.pop_back();
                   }
                  break;
                }
                
                //gehtsRechts?
                if (lab[akt_y][akt_x+1]!='*'){
                  kompas='O';                            
                  akt_x++;
                  if (lab[akt_y][akt_x]=='.'){//prüft ob hier schonmal war
                     lab[akt_y][akt_x]='o';//da noch nicht, setzt marker
                     derWeg.push_back('R');//schreibt den schritt auf
                   }
                   else{
                    
                     derWeg.pop_back();//entfernt letzten schritt von der liste
                   }
                  break;
                }
                }  
     }//switch 
       
    
    if((akt_x==1)&&(akt_y==y-1)){cout<<"kein Weg gefunden"<<endl;break;} 
    
}//while

}//if (file)	 
else cout <<"ungueltiger dateiname" << endl;



//	system("pause");

}
