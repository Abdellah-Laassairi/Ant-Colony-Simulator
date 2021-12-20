#include <iostream>
#include <stdlib.h> 
#include <fstream>
#include <cstdlib> 
#include <string>
#include <time.h>
#include <unistd.h>
#include "monde.h"
#include "affichage.h"
#include "fourmi.h"
#include <chrono>
#include <thread>
using std::this_thread::sleep_for;
using std::cerr;
using std::cout;
using std::endl;
using std::ifstream;
using namespace std;

/*retour <- InitAffichage(largeur,hauteur)
...
TantQue retour=1 Faire
...
Pour <chaque fourmi> Faire
...
MiseAJourFourmi(...)
FinPour
...
MiseAJourEnvironnement(...)
retour <- Affichage()
FinTantQue*/
int main(){
int retour;


string nom_monde = "monde1.dat";
t_monde monde;
monde = LireEnvironnement(nom_monde);
fourmi f1,f2;
f1.monde=monde;
f1.Fx=15;
f1.Fy=15;
f1.direction=0;
f1.mode=0;


retour= InitAffichage(monde.L, monde.H);
while(retour==1){
 
    f1=DeplaceFourmie(f1, monde); 
    MiseAJourFourmi(f1.Fx, f1.Fy,0);
    MiseAJourEnvironnement(monde);
    sleep_for(std::chrono::milliseconds(400));
 
 retour = Affichage();
}


/* Test 1
for (int i=0; i<monde.L;i++){
  for(int j=0;j<monde.H;j++){
    cout<<monde.mat[i][j]<<" ";
  }
  cout<<endl;
}
return 0;
*/
}