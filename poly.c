#include <stdio.h>
#include <stdlib.h>
#include "poly.h"
#include <x86intrin.h>

float power(float x,int y){
  int i = 0;
  float res = 1;
  while(i != y){
    res = res*x;
    i++;
  }
  return res;
}



p_polyf_t creer_polynome (int degre)
{
  p_polyf_t p ;
  
  p = (p_polyf_t) malloc(sizeof (polyf_t)) ;
  p->degre = degre ;

  p->coeff = (float *) malloc((degre+1) * sizeof (float))  ;

  return p ;
}

void detruire_polynome (p_polyf_t p)
{
  free (p->coeff) ;
  free (p) ;

  return ;
}

void init_polynome (p_polyf_t p, float x)
{
  register unsigned int i ;

  for (i = 0 ; i <= p->degre; ++i)
    p->coeff [i] = x ;

  return ;
}



p_polyf_t lire_polynome_float (char *nom_fichier)
{
  FILE *f ;
  p_polyf_t p ;
  int degre ;
  int i  ;
  int cr ;
  
  f = fopen (nom_fichier, "r") ;
  if (f == NULL)
    {
      fprintf (stderr, "erreur ouverture %s \n", nom_fichier) ;
      exit (-1) ;
    }
  
  cr = fscanf (f, "%d", &degre) ;
  if (cr != 1)
    {
      fprintf (stderr, "erreur lecture du degre\n") ;
      exit (-1) ;
    }
  p = creer_polynome (degre) ;
  
  for (i = 0 ; i <= degre; i++)
    { 
      cr = fscanf (f, "%f", &p->coeff[i]) ;
       if (cr != 1)
    {
      fprintf (stderr, "erreur lecture coefficient %d\n", i) ;
      exit (-1) ;
    }
       
    }

  fclose (f) ;

  return p ;
}

void ecrire_polynome_float (p_polyf_t p)
{
  int i ;

  printf ("%f + %f x ", p->coeff [0], p->coeff [1]) ;
  
  for (i = 2 ; i <= p->degre; i++)
    {  
      printf ("+ %f X^%d ", p->coeff [i], i) ;
    }
  
  printf ("\n") ;

  return ;
}

int egalite_polynome (p_polyf_t p1, p_polyf_t p2)
{
  if(p1->degre == p2->degre){
    for(int i = 0; i<p1->degre+1;i++){
      if(p1->coeff[i] != p2->coeff[i]){
        return 0;
      }
    }
    return 1;
  }
  return 0;
}

p_polyf_t addition_polynome (p_polyf_t p1, p_polyf_t p2)
{
  p_polyf_t p3 ;
  register unsigned int i ;
  
  p3 = creer_polynome (max (p1->degre, p2->degre));

  for (i = 0 ; i <= min (p1->degre, p2->degre); ++i)
    {
      p3->coeff [i] = p1->coeff [i] + p2->coeff [i] ;
    }

  if (p1->degre > p2->degre)
    {
      for (i = (p2->degre + 1) ; i <= p1->degre; ++i)
	p3->coeff [i] = p1->coeff [i] ;
    }
  else if (p2->degre > p1->degre)
    {
      for (i = (p1->degre + 1) ; i <= p2->degre; ++i)
	p3->coeff [i] = p2->coeff [i] ;
    }
    
  return p3 ;
}

p_polyf_t multiplication_polynome_scalaire (p_polyf_t p, float alpha)
{
  for(int i = 0; i<p->degre+1;i++){
    p->coeff[i] = p->coeff[i]*alpha;
  }
  return p;

}

float eval_polynome (p_polyf_t p, float x)
{
  float res = 0.0;
  for(int i = 0; i<p->degre+1;i++){
    res = res + p->coeff[i]*power(x,i);
  }
  return res;
}

p_polyf_t multiplication_polynomes (p_polyf_t p1, p_polyf_t p2)
{
  p_polyf_t p = creer_polynome(p1->degre + p2->degre);
  for(int i = 0; i<p->degre+1;i++){
    p->coeff[i] = 0;
  }

  for(int j = 0; j<p1->degre+1;j++){
    for(int k = 0; k<p2->degre+1;k++){
      p->coeff[j+k] = p->coeff[j+k] + p1->coeff[j]*p2->coeff[k];
    }
  }
  return p;
}

p_polyf_t puissance_polynome (p_polyf_t p, int n)
{
  int i = 1;
  p_polyf_t temp = p;
  while(i != n){
    p = multiplication_polynomes (p,temp);
    i++;
  }
  return p;
}

p_polyf_t composition_polynome (p_polyf_t p, p_polyf_t q)
{
  printf("%d\n",1);
  p_polyf_t p3 = creer_polynome(p->degre*q->degre);

  init_polynome(p3,0.0);

  for(int i = 1; i< p->degre+1;i++){
    p3 = addition_polynome(multiplication_polynome_scalaire(puissance_polynome(q,i),p->coeff[i]), p3);
  }
  return p3;
}


