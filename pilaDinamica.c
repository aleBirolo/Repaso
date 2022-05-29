#include "pila.h"

void crearPila(t_pila *pc)
{
    *pc=NULL;
}

booleano pilaVacia(const t_pila *pc)
{
    return *pc==NULL;
}

booleano pilaLlena(const t_pila *pc, unsigned tamDato)
{
    t_nodo *aux= malloc (sizeof(t_nodo));
    void *datoAux = malloc (tamDato);

    free (aux);
    free(datoAux);
    return aux==NULL ||datoAux==NULL;
}

booleano apilar(t_pila *pc,const void *dato, unsigned tamDato)
{
    t_nodo *nue= malloc (sizeof(t_nodo));

    if (nue !=NULL)
    {
        nue->info=malloc(tamDato);

        if ( nue->info == NULL)
        {
            free (nue);
            return falso;
        }
    }

    memcpy (nue->info, dato, tamDato);
    nue->tamInfo=tamDato;
    nue->sig = *pc;
    *pc=nue;

    return verdadero;
}

booleano desapilar(t_pila *pc, void *dato, unsigned tamDato)
{
    t_nodo *elim;

    if (*pc == NULL)
        return falso;

    elim=*pc;


    memcpy(dato, elim->info,MIN(elim->tamInfo, tamDato));
    *pc=elim->sig;

    free(elim->info);
    free(elim);

    return verdadero;
}

booleano verPila(const t_pila *pc, void *dato, unsigned tamDato)
{
    t_nodo *nodo;

    if (*pc==NULL)
        return falso;

    nodo=*pc;
    memcpy(dato, nodo->info, MIN(nodo->tamInfo, tamDato));

    return verdadero;
}

void vaciarPila(t_pila *pc)
{
    t_nodo *elim;

    while (*pc)
    {
        elim=*pc;
        *pc=elim->sig;
        free(elim->info);
        free(elim);
    }
}
