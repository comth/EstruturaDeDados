struct lista {
int info;
struct lista* prox;
};
typedef struct lista Lista;

/* fun��o de cria��o: retorna uma lista vazia */
Lista* lst_cria (void)
{
return NULL;
}

Lista* lst_insere (Lista* l, int i)
{
Lista* novo = (Lista*) malloc(sizeof(Lista));
novo->info = i;
novo->prox = l;
return novo;
}

int main (void)
{
Lista* l; /* declara uma lista n�o inicializada */
l = lst_cria(); /* cria e inicializa lista como vazia */
l = lst_insere(l, 23); /* insere na lista o elemento 23 */
l = lst_insere(l, 45); /* insere na lista o elemento 45 */
return 0;
}

void lst_imprime (Lista* l)
{
Lista* p;
for (p = l; p != NULL; p = p->prox)
printf(�info = %d\n�, p->info);
}

/* fun��o vazia: retorna 1 se vazia ou 0 se n�o vazia */
int lst_vazia (Lista* l)
{
return (l == NULL);
}



#include <stdio.h>
#include "lista.h"
int main (void)
{
Lista* l; /* declara uma lista n�o iniciada */
l = lst_cria(); /* inicia lista vazia */
l = lst_insere(l, 23); /* insere na lista o elemento 23 */
l = lst_insere(l, 45); /* insere na lista o elemento 45 */
l = lst_insere(l, 56); /* insere na lista o elemento 56 */
l = lst_insere(l, 78); /* insere na lista o elemento 78 */
lst_imprime(l); /* imprimir�: 78 56 45 23 */
l = lst_retira(l, 78);
lst_imprime(l); /* imprimir�: 56 45 23 */
l = lst_retira(l, 45);
lst_imprime(l); /* imprimir�: 56 23 */
lst_libera(l);
return 0;
}