#include "agent.h"

#include <unistd.h>
#include <stdio.h>
#include <signal.h>

typedef struct fonction_s {

    void *(*fct)(void *);
    void *arg;
    pthread_t thread;
} fonction_t;

void handler( int sig ) {

    printf("Mise en pause de l'agent\n");
    pause();
    printf("Reprise de l'agent\n");
}

void* create ( void* arg ) {

    printf("0\n");

    struct sigaction sig;
    sig.sa_handler = handler;
    sig.sa_flags = 0;
    sigemptyset( &sig.sa_mask );

    printf("1\n");

    sigaction( SIGUSR1, &sig, NULL );

    fonction_t *f = (fonction_t *)arg;

    printf("kill thread\n");

    kill( getpid(), SIGUSR1 );

    printf("lancement de la fonction\n");

    (*f).fct( (*f).arg );
}

Agent::Agent( void *(*f)(void *), void *a ) {

    fonction_t fonction;

    fonction.fct = f;
    fonction.arg = a;
    fonction.thread = thread;

    void* ( *fct ) ( void* arg ) = create;

    printf("lancement du thread\n");
    if ( pthread_create( &thread, NULL, create, &fonction ))
        printf("probleme\n");
    else
        printf("thread lancé\n");
}

void Agent::invoke() {

    printf("invoke D\n");

    pthread_kill( thread, SIGUSR2 );

    printf("invoke F\n");
}

void Agent::suspend() {

    pthread_kill( thread, SIGUSR1 );
}

void Agent::resume() {

    pthread_kill( thread, SIGUSR2 );
}

void Agent::destroy() {

    pthread_exit( &thread);
}