#include "utilitarios.h"

/// No se usa
void intercambio ( void *d1,  void *d2, unsigned tamDato)
{
    void *aux = malloc(tamDato);

    if (!aux)
        return;

    memcpy(aux, d1, tamDato);
    memcpy(d1, d2, tamDato);
    memcpy(d2, aux, tamDato);
}
