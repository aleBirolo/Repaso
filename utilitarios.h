#ifndef UTILITARIOS_H_INCLUDED
#define UTILITARIOS_H_INCLUDED

#include <stdlib.h>
#include <memory.h>
#define MIN(x,y) (x<=y ? x: y)

typedef enum
{
    verdadero=1,
    falso=0
}booleano;

typedef struct s_nodo
{
    void *info;
    unsigned tamInfo;
    struct s_nodo *sig;
}t_nodo;

typedef struct
{
    int cod;
    float sueldo;
}t_persona;

typedef int (*Cmp)(const void *, const void *);
typedef void (*Mostrar)(const void *);
typedef void (*Acum)(void *, const void *);

void intercambio ( void *d1,  void *d2, unsigned tamDato);

#endif // UTILITARIOS_H_INCLUDED


