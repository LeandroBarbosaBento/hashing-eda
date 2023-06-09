#include "hashing_perfeito.h"
#include "time.h"

int numeroB(int primo)
{
    srand(time(NULL)-1);
    int b = 1 + (rand( ) % primo-1);
    return b;
}

int numeroA(int primo)
{
    srand(time(NULL));
    int a = rand() % primo;
    return a;
}

int gerarPrimo(int chave)
{
    int primo, i;

    primo = chave + 1;

    for (i = 2; i < chave; i++)
    {
        if (primo % i == 0) {
            primo++;
            i = 2;
        }
        else if(i==chave-1) return primo;
    }

    return primo;
}


hashing_perfeito_t create_hashing_perfeito(int n, int maiorChave)
{
    hashing_perfeito_t x;

    x.v = malloc( (n) * sizeof(hashing_perfeito_t) );
    x.total_access = 0;
    x.number_of_keys = 0;
    x.size = n;
    x.primo = gerarPrimo(maiorChave);
    x.a = numeroA(x.primo);
    x.b = numeroB(x.primo);
    x.m = n;
  
    for(int i = 0; i <= n; i++){
        x.v[i].is_empty = 1;
    }

    return x;
}


hashing_perfeito_t* insert_hashing_perfeito(hashing_perfeito_t *x , int key)
{
    int h, i=0;
    int pointer;
    int a = x->a;
    int b = x->b;
  
    h = ((a*key+b) % x->primo)% x->m;

    if(x->v[h].is_empty)
    {   
        x->v[h].key = malloc( (1) * sizeof(hashing_perfeito_t) );
        x->v[h].is_empty = 0;
        x->v[h].key[0] = key;
        x->v[h].a = numeroA(x->primo - key);
        x->v[h].b = numeroB(x->primo - key);
        x->v[h].m = 1;
        x->v[h].size = 1;
        x->total_access++;
        x->number_of_keys++;
    }
    else
    {
        int h2;

        x->number_of_keys++;
        x->total_access += 2;
        x->v[h].size = x->v[h].size + 1;
        x->v[h].m = (x->v[h].size * x->v[h].size);

        int vetAux[x->v[h].m];
        int *vetAux2 = malloc( (x->v[h].m) * sizeof(hashing_perfeito_t) );

        for(int i=0; i< x->v[h].m; i++)
        {
            vetAux[i]=0;
            vetAux2[i]=0;
            if(x->v[h].key[i]!=0)
            vetAux[i] = x->v[h].key[i] ;
        }
      
        for(int i=0; i< x->v[h].m; i++)
        {
            if(vetAux[i]!=0)
            {
                h2 = (((x->v[h].a*vetAux[i]+x->v[h].b) % x->primo)% x->v[h].m);
                vetAux2[h2] = vetAux[i];
            }
        }

        h2 = (((x->v[h].a*key+x->v[h].b) % x->primo)% x->v[h].m);
        vetAux2[h2] = key;

        for(int i=0; i<x->v[h].m; i++) x->v[h].key[i] = vetAux2[i];
    }

    return x;
}


int buscaHashingPerfeito(hashing_perfeito_t *x, int key){
    int a, b, m, h, a2, b2, h2;

    a = x->a;
    b = x->b;
    h = (((a*key+b) % x->primo)% x->m);

    a2 =x->v[h].a;
    b2 = x->v[h].b;
    h2 = (((a2*key+b2) % x->primo)% x->v[h].m);
    int chave = x->v[h].key[h2]; 

    if(chave==key) return chave;
    else return -1;
}

float get_avarage_hashing_perfeito(hashing_perfeito_t * x)
{
    return (float) x->total_access / x->number_of_keys;
}

void show_data_hashing_perfeito(hashing_perfeito_t *x){
  printf("\n*****HASHING PERFEITO*****\n");
  printf("value a: %d\n", x->a);
  printf("value b: %d\n", x->b);
  printf("value prime: %d\n", x->primo);
  printf("total_access: %d\n", x->total_access);
  printf("number_of_keys: %d\n", x->number_of_keys);
  if(x->total_access != 0)
        printf("avarage access: %.3f\n", get_avarage_hashing_perfeito(x));

  printf("Table\n");
  int i, j;
  for(i=0; i<x->m; i++){
    printf("[%d]:", i);
    if(x->v[i].is_empty!=1){
       
      for(j=0; j<x->v[i].m; j++){
        printf("[%d]", x->v[i].key[j]);
      }
      printf(" ___ ");
      printf("a2: %d,", x->v[i].a);
      printf(" b2: %d", x->v[i].b);
    }
    printf("\n");
  }
}
