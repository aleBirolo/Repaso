#include "main.h"

#define TAM 5

int main()
{
    t_persona persona[TAM]={};
    t_lista lista;
    int i;

    for (i=0 ; i<TAM; i++)
    {
        persona[i].cod=rand()%TAM +1;
        persona[i].sueldo=(i+1)*100;
    }

    crearLista(&lista);

    for (i=0 ; i<TAM; i++)
    {
        enlistar_al_final(&lista, &persona[i], sizeof(t_persona));
    }


    verLista_desde_ppio(&lista, mostrarPersona);
    i=eliminarDuplicados_lista_y_acumular(&lista, compararPersona, acumularSueldo);
    printf ("\n\n Cantidad de registros  duplicados: %d\n",i);
    verLista_desde_ppio(&lista, mostrarPersona);

    return 0;
}


int compararPersona (const void *d1, const void *d2)
{
    t_persona *p1=(t_persona *)d1,
              *p2=(t_persona *)d2;
    int cmp;

    cmp = p1->cod - p2->cod;

    return cmp;
}

void mostrarPersona (const void *d)
{
    t_persona *p=(t_persona *)d;

    printf ("%d %.2f\n", p->cod, p->sueldo);
}

void acumularSueldo ( void *d1, const void *d2)
{
    t_persona *p1=(t_persona *)d1,
              *p2=(t_persona *)d2;

    p1->sueldo+=p2->sueldo;
}
