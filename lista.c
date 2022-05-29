#include "lista.h"

void crearLista(t_lista *pl)
{
    *pl=NULL;
}

booleano listaVacia(const t_lista *pl)
{
    return *pl==NULL;
}

booleano listaLlena(const t_lista *pl, unsigned tamDato)
{
    t_nodo *aux= malloc(sizeof(t_nodo));
    void *info = malloc (tamDato);

    free(aux);
    free(info);

    return aux==NULL ||info==NULL;
}

void vaciarLista(t_lista *pl)
{
    t_nodo *elim;

    while (*pl)
    {
        elim=*pl;
        *pl=elim->sig;

        free(elim->info);
        free(elim);
    }
}

void vaciarLista_y_Mostrar (t_lista *pl, Mostrar mostrar)
{
    t_nodo *elim;

    while (*pl)
    {
        elim=*pl;
        *pl=elim->sig;

        mostrar(elim->info);
        free(elim->info);
        free(elim);
    }
}

booleano enlistar_al_ppio(t_lista *pl,const void *dato, unsigned tamDato)
{
    t_nodo *nue= malloc (sizeof(t_nodo));

    if (!nue)
        return falso;

    nue->info= malloc (tamDato);
    if (!nue->info)
    {
        free(nue);
        return falso;
    }

    memcpy(nue->info, dato, tamDato);
    nue->tamInfo = tamDato;

    nue->sig=*pl;
    *pl=nue;

    return verdadero;
}

booleano enlistar_en_orden(t_lista *pl,const void *dato, unsigned tamDato, Cmp cmp)
{
    t_nodo *nue= malloc (sizeof(t_nodo));

    if (!nue)
        return falso;

    nue->info = malloc(tamDato);
    if(!nue->info)
    {
        free(nue);
        return falso;
    }

    memcpy(nue->info, dato, tamDato);
    nue->tamInfo = tamDato;

    while ( (*pl)->sig && cmp( (*pl)->info, dato ) < 0)
        pl=&(*pl)->sig;


    if ((*pl)->sig)
    {
       nue->sig=*pl;
       *pl=nue;
    }
    else
    {
       (*pl)->sig=nue;
        nue->sig=NULL;
    }

    return verdadero;
}

booleano enlistar_al_final(t_lista *pl,const void *dato, unsigned tamDato)
{
    t_nodo *nue = (t_nodo *)malloc(sizeof(t_nodo));

    while(*pl)
        pl=&(*pl)->sig;

    if (!nue)
        return falso;

    nue->info=malloc(tamDato);
    if (!nue->info)
    {
        free(nue);
        return falso;
    }

    memcpy(nue->info, dato, tamDato);
    nue->tamInfo = tamDato;
    nue->sig=NULL;
    *pl= nue;

   return verdadero;
}

booleano enlistar_en_orden_y_acumular(t_lista *pl,const void *dato, unsigned tamDato, Cmp cmp, Acum acum)
{
    t_nodo *nue;

    while ( (*pl)->sig && cmp( (*pl)->info, dato ) < 0)
        pl=&(*pl)->sig;


    if (cmp( (*pl)->info, dato ) == 0)
    {
        acum((*pl)->info, dato);
        return verdadero;
    }

    nue=malloc (sizeof(t_nodo));
    if (!nue)
        return falso;

    nue->info = malloc(tamDato);
    if(!nue->info)
    {
        free(nue);
        return falso;
    }

    memcpy(nue->info, dato, tamDato);
    nue->tamInfo = tamDato;

    if ((*pl)->sig)
    {
       nue->sig=*pl;
       *pl=nue;
    }
    else
    {
       (*pl)->sig=nue;
        nue->sig=NULL;
    }

    return verdadero;
}


booleano desenlistar_al_ppio(t_lista *pl, void *dato, unsigned tamDato)
{
    t_nodo *elim=*pl;

    if (!elim)
        return falso;

    memcpy(dato, elim->info, MIN(elim->tamInfo, tamDato));

    *pl=elim->sig;

    free(elim->info);
    free(elim);

    return verdadero;
}

booleano desenlistar_dato (t_lista *pl, void *dato, unsigned tamDato, Cmp cmp)
{
    t_nodo *elim;

    if (!*pl)
        return falso;

    while ( (*pl)->sig && cmp((*pl)->info, dato)!= 0 )
        pl= &(*pl)->sig;

    if (!*pl || cmp((*pl)->info, dato)!=0)
        return falso;

    elim=*pl;
    memcpy(dato, elim->info, MIN(elim->tamInfo, tamDato) );
    *pl=elim->sig;

    free(elim->info);
    free(elim);

    return verdadero;
}

booleano desenlistar_al_final(t_lista *pl, void *dato, unsigned tamDato)
{
    t_nodo *elim;

    if (!*pl)
        return falso;

    while( (*pl)->sig)
        pl=&(*pl)->sig;

    elim=*pl;
    memcpy(dato, elim->info, MIN(elim->tamInfo, tamDato));

    free(elim->info);
    free(elim);

    *pl=NULL;

    return verdadero;
}

/// Elimina todos los nodos que cumplan con la clave de busqueda y devuelve en dato el valor acumulado
booleano desenlistar_dato_y_acumular (t_lista *pl, void *dato, unsigned tamDato, Cmp cmp, Acum acum)
{
    t_nodo *elim;

    if (!*pl)
        return falso;

    /// Desenlista la primer ocurrencia
    while ( (*pl)->sig && cmp((*pl)->info, dato)!= 0 )
        pl= &(*pl)->sig;

    if (!*pl || cmp((*pl)->info, dato)!=0)
        return falso;

    elim=*pl;
    memcpy(dato, elim->info, MIN(elim->tamInfo, tamDato) );
    *pl=elim->sig;

    free(elim->info);
    free(elim);

    /// Desenlistar y acumular (si llego aca, entonces dato fue cargado en la variable y eliminado de la lista)
    while ( *pl )
    {
        if ( cmp((*pl)->info, dato)==0)
        {
            elim=*pl;
            acum(dato, elim->info);
            *pl=elim->sig;
            free(elim->info);
            free(elim);
        }
        else
            pl= &(*pl)->sig;
    }

    return verdadero;
}

booleano verLista_al_ppio(t_lista *pl, void *dato, unsigned tamDato)
{
    t_nodo *aux=*pl;

    if (!aux)
        return falso;

    memcpy(dato, aux->info, MIN(aux->tamInfo, tamDato));

    return verdadero;
}

booleano verLista_dato(t_lista *pl, void *dato, unsigned tamDato, Cmp cmp)
{
    t_nodo *aux;

    if (!*pl)
        return falso;

    while ( (*pl)->sig && cmp((*pl)->info, dato)!= 0 )
        pl= &(*pl)->sig;

    if (!*pl || cmp((*pl)->info, dato)!=0)
        return falso;

    aux=*pl;
    memcpy(dato, aux->info, MIN(aux->tamInfo, tamDato) );

    return verdadero;
}

booleano verLista_al_final(t_lista *pl, void *dato, unsigned tamDato)
{
    t_nodo *aux;

    if (!*pl)
        return falso;

    while((*pl)->sig)
        pl= &(*pl)->sig;

    aux=*pl;

    memcpy(dato, aux->info, MIN(aux->tamInfo,tamDato));
    return verdadero;
}

void verLista_desde_ppio(t_lista *pl, Mostrar mostrar)
{
    while (*pl)
    {
        mostrar( (*pl)->info );
        pl=&(*pl)->sig;
    }
}

void verLista_desde_final(t_lista *pl, Mostrar mostrar)
{

    if (*pl)
    {
        verLista_desde_final (&(*pl)->sig, mostrar);
        mostrar((*pl)->info);
    }
}

int verLista_desde_ppio_y_contar(t_lista *pl, Mostrar mostrar)
{
    int n=0;

    while (*pl)
    {
        n++;
        mostrar( (*pl)->info );
        pl=&(*pl)->sig;
    }
    return n;
}

int verLista_desde_final_y_contar(t_lista *pl, Mostrar mostrar)
{
    int n;

    if (*pl)
    {
        n=verLista_desde_final_y_contar (&(*pl)->sig, mostrar);
        mostrar((*pl)->info);
        return n+1;
    }
    return 0;
}

t_lista *buscarMenor  (t_lista *pl, Cmp cmp)
{
    t_lista *menor = pl;

    pl=&(*pl)->sig;

    while (*pl)
    {
        if (cmp( (*pl)->info, (*menor)->info) < 0)
            menor=pl;
        pl=&(*pl)->sig;
    }

    return menor;
}


void ordenarLista_con_dup (t_lista *pl, Cmp cmp)
{
  t_lista lord;         /// lista ordenada (no es un puntero a lista)
  t_lista *pult=&lord;  /// puntero a lista ordenada (se mantiene al final de dicha lista)
  t_lista *menor;       /// puntero de lista que apunta al menor nodo de dicha lista

  /// Aca voy desenganchado los menores
  while ( *pl )
  {
      menor=buscarMenor(pl, cmp);       /// Encuentro menor nodo
      *pult=*menor;                     /// Inserto el menor nodo en la lista ordena -- al final
      *menor=(*menor)->sig;             /// desengancho el menor nodo de ptrLista
      pult=&(*pult)->sig;               /// posiciono el puntero en el ultimo
  }

  *pl=lord;                       /// copio la direccion de lord en ptr lista

}


void ordenarLista_sin_dup (t_lista *pl, Cmp cmp, Acum acum)
{
    t_lista lord;
    t_lista *pult=&lord;
    t_lista *menor;
    t_nodo *elim;

    while ( *pl )
    {
        menor=buscarMenor(pl, cmp);

        if (pult!=&lord && cmp(  (*menor)->info, elim->info ) == 0)
        {
            acum(elim->info, (*menor)->info );
            *menor=(*menor)->sig;
        }
        else
        {
            *pult=*menor;
            elim=*menor;
            *menor=(*menor)->sig;
            pult=&(*pult)->sig;
            *pult=NULL;
        }
    }

    *pl=lord;
}

int eliminarDuplicados_lista (t_lista *pl, Cmp cmp)
{
    t_lista *pl_act;
    t_nodo *elim;
    int n=0;

    while ( (*pl) )
    {
        pl_act=&(*pl)->sig;

        while ((*pl_act))
        {
            if ( cmp( (*pl)->info, (*pl_act)->info ) == 0 )
            {
                n++;
                elim=*pl_act;
                *pl_act=(*pl_act)->sig;
                free(elim->info);
                free(elim);
            }
            else
                pl_act=&(*pl_act)->sig;
        }

        pl=&(*pl)->sig;
    }

    return n;
}

int eliminarDuplicados_lista_y_acumular (t_lista *pl, Cmp cmp, Acum acum)
{
    t_lista *pl_act;
    t_nodo *elim;
    int n=0;

    while ( (*pl) )
    {
        pl_act=&(*pl)->sig;

        while ((*pl_act))
        {
            if ( cmp( (*pl)->info, (*pl_act)->info ) == 0 )
            {
                n++;
                elim=*pl_act;
                acum((*pl)->info, elim->info);
                *pl_act=(*pl_act)->sig;
                free(elim->info);
                free(elim);
            }
            else
                pl_act=&(*pl_act)->sig;
        }

        pl=&(*pl)->sig;
    }

    return n;
}
