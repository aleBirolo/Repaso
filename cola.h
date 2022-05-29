#ifndef COLA_H_INCLUDED
#define COLA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include "utilitarios.h"

typedef struct
{
    t_nodo *pri,
           *ult;
}t_cola;

void crearCola(t_cola *pc);
booleano colaVacia(const t_cola *pc);
booleano colaLlena(t_cola *pc, unsigned tamDato);
booleano encolar(t_cola *pc, const void *dato, unsigned tamDato);
booleano desencolar(t_cola *pc, void *dato, unsigned tamDato);
booleano verCola(const t_cola *pc, void *dato, unsigned tamDato);
void vaciarCola(t_cola *pc);

#endif // COLA_H_INCLUDED
