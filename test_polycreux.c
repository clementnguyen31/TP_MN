#include <stdio.h>
#include <stdlib.h>

#include "Poly_Creux.h"


int main (int argc, char **argv)
{
  Poly_creux *p1, *p2;
    p1 = p2 = NULL;

    create_poly(&p1, 3, 2);
    create_poly(&p1, 1, 0);
    display_poly(p1);
    printf("\n");

    create_poly(&p2, 5, 1);
    create_poly(&p2, 6, 0);
    display_poly(p2);
    printf("\n");

    Poly_creux *res;
    //add_poly(&res, p1, p2);
    //display_poly(res);
    printf("\n");

    Poly_creux *poly = NULL;
    poly = mult_poly(poly, p1, p2);
    //display_poly(poly);
    printf("\n");

    Poly_creux *test;
    test = power_poly(p1, 40);
    display_poly(test);
    printf("\n");

}
