/*
  polyf_t   : structure polynome
  p_polyf_t : pointeur sur un polynome
*/

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

typedef struct {
  int degre ;
  float *coeff;
} polyf_t, *p_polyf_t;


typedef struct { //La pair donne pour chaque terme du polynome son coefficient et sa puissance ce qui évite d'ajouter les termes nuls inutiles
  int degre ;
  float coeff;
} pair;

typedef struct {
  int degre ;   //Le degré maximum de notre polynome
  struct pair *pairs;  //Notre polynome est ainsi un table de pairs qui sont les termes 
} polyf_creux_t, *p_polyf_creux_t;


p_polyf_t creer_polynome (int degre) ;

void init_polynome (p_polyf_t p, float x) ;

void detruire_polynome (p_polyf_t p) ;

p_polyf_t lire_polynome_float (char *nom_fichier) ;

void ecrire_polynome_float (p_polyf_t p) ;

int egalite_polynome (p_polyf_t p1, p_polyf_t p2) ;

p_polyf_t addition_polynome (p_polyf_t p1, p_polyf_t p2) ;

p_polyf_t multiplication_polynome_scalaire (p_polyf_t p, float alpha) ;

float eval_polynome (p_polyf_t p, float x) ;

p_polyf_t multiplication_polynomes (p_polyf_t p1, p_polyf_t p2) ;

p_polyf_t puissance_polynome (p_polyf_t p, int n) ;

p_polyf_t composition_polynome (p_polyf_t p, p_polyf_t q) ;

float composition_polynome2 (p_polyf_t p, p_polyf_t q, float n) ;