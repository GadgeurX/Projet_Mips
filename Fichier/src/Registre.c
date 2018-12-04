

#include <stdio.h>
#include <stdlib.h>


Registre Init(){
  Registre reg = malloc(sizeof(Registre));
  reg.zero = 0;
  reg.at = 0;
  reg.v = [1,0];
  reg.a = [0,0,0,0];
  reg.t = [0,0,0,0,0,0,0,0];
  reg.s = [0,0,0,0,0,0,0,0];
  reg.t2 = [0,0];
  reg.k = [0,0];
  reg.gp = 0;
  reg.sp = 0;
  reg.fp = 0;
  reg.ra = 0;


}
