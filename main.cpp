#include "agent.h"
#include "boucle.h"

#include <stdio.h>
#include <unistd.h>

int main () {

    int arg = 0;

    printf(" --- CREATION DE L'AGENT 1 --- \n");

    Agent ag1 = Agent( boucle, &arg );

    printf(" --- INVOKE DE L'AGENT 1 --- \n");

    ag1.invoke();
    sleep(1);

    printf(" --- SUSPEND DE L'AGENT 1 --- \n");

    ag1.suspend();
    sleep(1);

    printf(" --- RESUME DE L'AGENT 1 --- \n");

    ag1.resume();
    sleep(1);

    printf(" --- DESTRUCTION DE L'AGENT 1 --- \n");

    ag1.destroy();

    return 0;
}