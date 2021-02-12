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

  printf("Polynome 1 : ");
  ecrire_polynome_float(p1);

  printf("Polynome 2 : ");
  ecrire_polynome_float(p2);

  p_polyf_t p3 = NULL;

  egalite_polynome(p1, p2) ? printf("P1 et P2 sont egaux\n") : printf("P1 et P2 ne sont pas egaux\n");

  p3 = addition_polynome(p1, p2);
  printf("Addition entre P1 et P2 : ");
  ecrire_polynome_float(p3);

  p3 = multiplication_polynome_scalaire(p1, 3);
  printf("Multiplication Scalaire P1 et 3 : ");
  ecrire_polynome_float(p3);

  p3 = multiplication_polynomes(p1, p2);
  printf("Multiplication entre P1 et P2 : ");
  ecrire_polynome_float(p3);

  p3 = puissance_polynome(p1, 3);
  printf("P1 Puissance 3 : ");
  ecrire_polynome_float(p3);

  p3 = composition_polynome(p1, p2);
  printf("Composition entre P1 et P2 : ");
  ecrire_polynome_float(p3);
}
