#include <stdio.h>
#include <stdlib.h>

#include "Poly_Creux.h"

int main(int argc, char **argv)
{
  Poly_creux *p1, *p2;
  p1 = p2 = NULL;

  create_poly(&p1, 4, 2);
  create_poly(&p1, 2, 1);
  create_poly(&p1, 5, 0);
  printf("Polynome 1 : ");
  display_poly(p1);
  printf("\n");

  create_poly(&p2, 3, 2);
  create_poly(&p2, 10, 1);
  create_poly(&p2, 8, 0);
  printf("Polynome 2 : ");
  display_poly(p2);
  printf("\n");

  Poly_creux *res;
  res = add_poly(p1, p2);
  printf("Addition entre P1 et P2 : ");
  display_poly(res);
  printf("\n");

  Poly_creux *poly = NULL;
  poly = mult_poly(p1, p2);
  printf("Multiplication entre P1 et P2 : ");
  display_poly(poly);
  printf("\n");

  Poly_creux *test;
  test = power_poly(p1, 3);
  printf("P1 Puissance 3 : ");
  display_poly(test);
  printf("\n");
}
