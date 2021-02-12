//
// Created by Clément Nguyen on 08/02/2021.
//

#ifndef POLYNOME_CREUX_POLY_CREUX_H
#define POLYNOME_CREUX_POLY_CREUX_H

typedef struct Poly_creux
{
    int exp;
    float coef;
    struct Poly_creux *next;
} Poly_creux;

void create_poly(Poly_creux **p, float c, int e);
void display_poly(Poly_creux *p);
Poly_creux * add_poly(Poly_creux *poly1, Poly_creux *poly2);
Poly_creux * mult_poly(Poly_creux *poly1, Poly_creux *poly2);
Poly_creux * power_poly(Poly_creux *p, int n);

#endif //POLYNOME_CREUX_POLY_CREUX_H
