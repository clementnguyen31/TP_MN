#include <stdio.h>
#include <stdlib.h>

#include "poly.h"

int main(int argc, char **argv)
{
  p_polyf_t p1, p2;

  if (argc != 3)
  {
    fprintf(stderr, "deux paramètres (polynomes,fichiers) sont à passer \n");
    exit(-1);
  }

  p1 = lire_polynome_float(argv[1]);
  p2 = lire_polynome_float(argv[2]);

  ecrire_polynome_float(p1);
  ecrire_polynome_float(p2);
  
  p_polyf_t p3;
  p3 = multiplication_polynomes(p1, p2);
  ecrire_polynome_float(p3);

  egalite_polynome(p1, p2) ? printf("egale\n") : printf(" pas egale\n");

  p_polyf_t p4 = multiplication_polynome_scalaire(p1, 5);
  ecrire_polynome_float(p4);

  float res = eval_polynome(p1, 0);
  printf("%f", res);

}
