#include <stdio.h>
#include <stdlib.h>

#include "poly.h"


int main (int argc, char **argv)
{
  p_polyf_t p1, p2 ;
  
  if (argc != 3)
    {
      fprintf (stderr, "deux paramètres (polynomes,fichiers) sont à passer \n") ;
      exit (-1) ;
    }
      
  p1 = lire_polynome_float (argv [1]) ;
  p2 = lire_polynome_float (argv [2]) ;

  ecrire_polynome_float (p1) ;
  printf("\n");
  ecrire_polynome_float (p2) ;
  printf("\n");

  p_polyf_t p3 = puissance_polynome(p1,3);
  ecrire_polynome_float(p3);
 
  p_polyf_t p4 = composition_polynome(p1,p2);
  ecrire_polynome_float(p4);
}
