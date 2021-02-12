//
// Created by Clément Nguyen on 08/02/2021.
//

#include "stdio.h"
#include "stdlib.h"
#include "Poly_Creux.h"

void create_poly(Poly_creux **p, float x, int y)
{
    Poly_creux *t; // on ajoute au precedent monome le nouveau monome pour former un nouveau polynome
    Poly_creux *q;
    q = *p;
    if (q == NULL)
    {
        t = malloc(sizeof(Poly_creux));
        t->coef = x;
        t->exp = y;
        *p = t;
        t->next = malloc(sizeof(Poly_creux));
        t = t->next;
        t->next = NULL;
    }
    else
    {
        t->coef = x;
        t->exp = y;
        t->next = malloc(sizeof(Poly_creux));
        t = t->next;
        t->next = NULL;
    }
}

void display_poly(Poly_creux *p)
{
    while (p != NULL)
    {
        printf("%0.1fx^%d", p->coef, p->exp); // 1 chiffre apres la virgule
        p = p->next;
        if (p != NULL)
        {
            printf(" + ");
        }
    }
}

void add_poly(Poly_creux **result, Poly_creux *p1, Poly_creux *p2)
{
    Poly_creux *res;
    res = malloc(sizeof(Poly_creux));
    res->next = NULL;
    *result = res;
    while (p1->next && p2->next)
    {
        if (p1->exp > p2->exp) // 1er cas
        {
            res->exp = p1->exp;
            res->coef = p1->coef;
            p1 = p1->next;
        }
        else if (p1->exp < p2->exp) // 2eme cas
        {
            res->exp = p2->exp;
            res->coef = p2->coef;
            p2 = p2->next;
        }
        else
        { // le reste
            res->exp = p1->exp;
            res->coef = p1->coef + p2->coef;
            p1 = p1->next;
            p2 = p2->next;
        }
        res->next = malloc(sizeof(Poly_creux));
        res = res->next;
        res->next = NULL;
    }
}

Poly_creux *mult_poly(Poly_creux *result, Poly_creux *poly1, Poly_creux *poly2)
{
    Poly_creux *first, *second;
    first = poly1;
    second = poly2;
    while (first != NULL)
    {
        while (second != NULL)
        {
            int coeff, power;
            coeff = first->coef * second->coef;
            power = first->exp + second->exp;
            create_poly(&result, coeff, power); // creation dun nouveau polynome avec les nouvelles valeurs
            second = second->next;
        }
        second = poly2;
        first = first->next;
    }

    Poly_creux *p1, *p2, *p3; // on rassemble les monomes de meme degres
    p1 = result;
    while (p1 != NULL && p1->next != NULL)
    {
        p2 = p1;
        while (p2->next != NULL)
        {
            if (p1->exp == p2->next->exp)
            {
                p1->coef = p1->coef + p2->next->coef;
                p3 = p2->next;
                p2->next = p2->next->next;
            }
            else
            {
                p2 = p2->next;
            }
        }
        p1 = p1->next;
    }
    return result;
}

Poly_creux *power_poly(Poly_creux *p, int n)
{
    int i = 1;
    Poly_creux *temp = p;
    while (i != n)
    {
        p = mult_poly(p, p, temp);
        i++;
    }
    return p;
}