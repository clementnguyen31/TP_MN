//
// Created by Clément Nguyen on 08/02/2021.
//

#include "stdio.h"
#include "stdlib.h"
#include "Poly_Creux.h"

void create_poly(Poly_creux **p, float x, int y)
{
    Poly_creux *t;
    Poly_creux *q;
    q = *p;
    if (q == NULL)
    {
        t = malloc(sizeof(struct Poly_creux));
        t->coef = x;
        t->exp = y;
        *p = t;
        t->next = malloc(sizeof(struct Poly_creux));
        t = t->next;
        t->next = NULL;
    }
    else
    {
        t->coef = x;
        t->exp = y;
        t->next = malloc(sizeof(struct Poly_creux));
        t = t->next;
        t->next = NULL;
    }
}

void display_poly(Poly_creux *p)
{
    while (p != NULL)
    {
        printf("%fx^%d", p->coef, p->exp);
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
    res = malloc(sizeof(struct Poly_creux));
    res->next = NULL;
    *result = res;
    while (p1->next && p2->next)
    {
        if (p1->exp > p2->exp)
        {
            res->exp = p1->exp;
            res->coef = p1->coef;
            p1 = p1->next;
        }
        else if (p1->exp < p2->exp)
        {
            res->exp = p2->exp;
            res->coef = p2->coef;
            p2 = p2->next;
        }
        else
        {
            res->exp = p1->exp;
            res->coef = p1->coef + p2->coef;
            p1 = p1->next;
            p2 = p2->next;
        }
        res->next = malloc(sizeof(struct Poly_creux));
        res = res->next;
        res->next = NULL;
    }
    
}

Poly_creux *mult_poly(Poly_creux *result, Poly_creux *p1, Poly_creux *p2)
{
    Poly_creux *temp;
    Poly_creux *res = result;
    int coefficient, exposent;

    temp = p2;

    if (p1 == NULL && p2 == NULL)
    {
        return NULL;
    }
    if (p1 == NULL)
    {
        res = p2;
    }
    else if (p2 == NULL)
    {
        res = p1;
    }
    else
    {
        while (p1 != NULL)
        {
            while (p2 != NULL)
            {
                coefficient = p1->coef * p2->coef;
                exposent = p1->exp + p2->exp;
                p2 = p2->next;
                create_poly(&res, coefficient, exposent);
            }
            p2 = temp;
            p1 = p1->next;
        }
    }
    return res;
}

Poly_creux *power_poly(Poly_creux *p, int n)
{
    int i = 1;
    Poly_creux *temp;
    Poly_creux *temp2 = p;
    while (i != n)
    {
        temp = mult_poly(temp, p, temp2);
        i++;
    }
    return temp;
}