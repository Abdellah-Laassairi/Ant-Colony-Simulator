#include "constantes.h"

#ifndef FOURMI_H
#define FOURMI_H

struct fourmi
{
	int Fx,Fy,direction;
  int mode;
  t_monde monde;		// position de la fourmiliËre
};
struct cord
{
	int Fx,Fy;
		// position de la fourmiliËre
};
void DeplaceFourmi(fourmi & f);
fourmi DeplaceFourmie (fourmi  f, t_monde environnement);

#endif