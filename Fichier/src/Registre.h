#include <stdio.h>
#include <stdlib.h>

typedef struct Registre Registre
struct Registre {
  int zero;
  int at;
  int v[2];
  int a[4];
  int t[8];
  int s[8];
  int t2[2];
  int k[2];
  int gp;
  int sp;
  int fp;
  int ra;
};

Registre Init();
