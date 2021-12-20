#include <iostream>
#include <random>
using std::cerr;
using std::cout;
using std::endl;
#include <fstream>
using std::ifstream;
#include <cstdlib> 
#include <string>
#include "proba.h"
#include "fourmi.h"

using namespace std;


//Fonction modulo 8
int modulo8(int x){
int y;
y = (x + 8) % 8;
return y;
}

//fonction positionpossible
bool PositionPossible(int x, int y, t_monde monde){
  
  if((x>=monde.L) || (x<0) || (y>=monde.H)|| (y<0) || (monde.mat[x][y]==-1)){
     return false;
  }
  else{
    return true;
  }

}


//Deplace Fourmi
/*
fourmi DeplaceFourmie (fourmi & f, t_monde environnement){

int tdx [8]= {+1,+1,0,-1,-1,-1, 0,+1};// deplacement en x
int tdy [8]= {0,+1,+1,+1, 0,-1,-1,-1}; // deplacement en y
int p_toutdroit[8]={12,2,1,1,0,1,1,2}; // coefficients de ponderation
int dir,i;
t_poids ponderation;
 // ponderation pour le tirage
//debut
// 1) choix d'une direction, en privilegiant la direction "tout droit"
for(int  i= 0 ; i<=7;i++){
dir = modulo8(i - f.direction);
ponderation[i] = p_toutdroit[dir];

}

// ponderation nulle quand le deplacement n'est pas possible
for(int  i= 0 ; i<7;i++){
if (!(PositionPossible(f.Fx+tdx[i], f.Fy+tdy[i],environnement)) ){
  ponderation[i] = 0;
}
}
// determination de la direction par tirage au sort suivant la ponderation

f.direction = nalea_pondere(ponderation);


  if ((PositionPossible(f.Fx+tdx[f.direction], f.Fy+tdy[f.direction],environnement)) ){
    f.Fx = f.Fx + tdx[f.direction];
    f.Fy = f.Fy + tdy[f.direction];
    //cout<<f.direction<<endl;
  }else{
    f.Fx=f.Fx;
    f.Fy=f.Fy;
  }


return f;
}
*/

fourmi DeplaceFourmie (fourmi f, t_monde environnement){

int tdx[8] = {+1,+1,0,-1,-1,-1, 0,+1};// deplacement en x
int tdy[8] = {0,+1,+1,+1, 0,-1,-1,-1}; // deplacement en y
int i=0;
int p_toutdroit[8]={12,2,1,1,0,1,1,2}; // coefficients de ponderation
int dir;
t_poids ponderation;
 // ponderation pour le tirage
//debut
// 1) choix d'une direction, en privilegiant la direction "tout droit"
for(int  i= 0 ; i<=7;i++){
dir = modulo8(i - f.direction);
ponderation[i] = p_toutdroit[dir];
}


  bool cond = true;
  while(cond){
  i= nalea_pondere(ponderation);
  if ((PositionPossible(f.Fx+tdx[i], f.Fy+tdy[i],environnement)) ){
  cond = false;
  f.Fx = f.Fx + tdx[i];
  f.Fy = f.Fy + tdy[i];

  }

}

return f;
}

/*
void DeplaceFourmi(fourmi & f){

  int al=nalea(8);

  switch(al){
    case 0 : 
        f.Fx=f.Fx+1;
        break;
    case 1 : 
        f.Fy=f.Fy+1;
        f.Fx=f.Fx+1;
        break;
    case 2 : 
        f.Fy=f.Fy+1;
        break;
    case 3 :
        f.Fy=f.Fy+1;
        f.Fx=f.Fx-1;
        break;
    case 4 :
        f.Fx=f.Fx-1;
        break;
    case 5 :
        f.Fy=f.Fy-1;
        f.Fx=f.Fx-1;
        break;
    case 6 :
        f.Fy=f.Fy-1;

        break;
    case 7 :
        f.Fy=f.Fy-1;
        f.Fx=f.Fx+1;
        break;
  }

}
  */