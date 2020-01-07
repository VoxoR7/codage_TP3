#include <inttypes.h>
#include <pthread.h>

class Agent {

    private:

        void* ( *fct ) ( void* arg );
        void *arg;
        pthread_t thread;

    public:

        Agent( void *(*F)(void *), void *arg ); /* Equivalent du create */
        void invoke();
        void suspend();
        void resume();
        void destroy();
};