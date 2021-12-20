#include <iostream>
using std::cerr;
using std::cout;
using std::endl;
#include <fstream>
using std::ifstream;
#include <cstdlib> 
#include <string>
using namespace std;
#include "constantes.h"
/*
// permet de stocker l'environnement
struct t_monde
{
	t_matrice mat;		// matrice
	int L;			// largeur
	int H;			// hauteur
	int Fx,Fy;		// position de la fourmiliËre
};
*/
t_monde LireEnvironnement(string nom)
{
   ifstream indata; // indata is like cin
   t_monde temp; 
   t_monde table;

   int i=0;
   indata.open(nom); // opens the file
   if(!indata) { // file couldn't be opened
      cerr << "Error: file could not be opened" << endl;
      exit(1);
   }
   
   int Largeur, Hauteur, absc, ord;
   indata>>Largeur;
   indata>>Hauteur;
   indata>>absc;
   indata>>ord;
   table.L=Largeur;
   table.H=Hauteur;
   table.Fx=absc;
   table.Fy=ord;
   while ( !indata.eof() && i<Hauteur){ 
      for(int j=0;j<Largeur;j++){
      indata>>table.mat[i][j];     
      }
      i++;
   }
 
   indata.close();
   cout << "End-of-file reached.." << endl;

   return table;

}