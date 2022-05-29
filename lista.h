#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include "utilitarios.h"

typedef t_nodo *t_lista;

void crearLista(t_lista *pl);
booleano listaVacia(const t_lista *pl);
booleano listaLlena(const t_lista *pl, unsigned tamDato);
void vaciarLista(t_lista *pl);
void vaciarLista_y_Mostrar (t_lista *pl, Mostrar mostrar);

/// Admite duplicados
booleano enlistar_al_ppio(t_lista *pl,const void *dato, unsigned tamDato);
booleano enlistar_en_orden(t_lista *pl,const void *dato, unsigned tamDato, Cmp cmp);
booleano enlistar_al_final(t_lista *pl,const void *dato, unsigned tamDato);

/// Sin duplicados
booleano enlistar_en_orden_y_acumular(t_lista *pl,const void *dato, unsigned tamDato, Cmp cmp, Acum acum);

/// Sin duplicados
booleano desenlistar_al_ppio(t_lista *pl, void *dato, unsigned tamDato);
booleano desenlistar_dato (t_lista *pl, void *dato, unsigned tamDato, Cmp cmp);
booleano desenlistar_al_final(t_lista *pl, void *dato, unsigned tamDato);

/// Admite duplicados
booleano desenlistar_dato_y_acumular (t_lista *pl, void *dato, unsigned tamDato, Cmp cmp, Acum acum);

booleano verLista_al_ppio(t_lista *pl, void *dato, unsigned tamDato);
booleano verLista_dato(t_lista *pl, void *dato, unsigned tamDato, Cmp cmp);
booleano verLista_al_final(t_lista *pl, void *dato, unsigned tamDato);

void verLista_desde_ppio(t_lista *pl, Mostrar mostrar);
void verLista_desde_final(t_lista *pl, Mostrar mostrar);

int verLista_desde_ppio_y_contar(t_lista *pl, Mostrar mostrar);
int verLista_desde_final_y_contar(t_lista *pl, Mostrar mostrar);

t_lista *buscarMenor  (t_lista *pl, Cmp cmp);
void ordenarLista_con_dup (t_lista *pl, Cmp cmp);
void ordenarLista_sin_dup (t_lista *pl, Cmp cmp, Acum acum);

int eliminarDuplicados_lista (t_lista *pl, Cmp cmp);
int eliminarDuplicados_lista_y_acumular (t_lista *pl, Cmp cmp, Acum acum);

#endif // LISTA_H_INCLUDED
