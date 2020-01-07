#include "boucle.h"

#include <stdio.h>

void* boucle( void *arg ) {

    int *a = (int *)arg;

    printf("arg (int) : %d\n", *a );

    unsigned long max = 1000000000;

    for ( unsigned long i = 0 ; i < max ; i++ );

    printf("fin\n");
}