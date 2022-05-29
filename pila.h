#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include "utilitarios.h"

typedef t_nodo *t_pila;

void crearPila(t_pila *pc);
booleano pilaVacia(const t_pila *pc);
booleano pilaLlena(const t_pila *pc, unsigned tamDato);
booleano apilar(t_pila *pc,const void *dato, unsigned tamDato);
booleano desapilar(t_pila *pc, void *dato, unsigned tamDato);
booleano verPila(const t_pila *pc, void *dato, unsigned tamDato);
void vaciarPila(t_pila *pc);
#endif // PILA_H_INCLUDED
