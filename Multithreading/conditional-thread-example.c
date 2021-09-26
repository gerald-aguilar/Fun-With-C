#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

//globals
int numLoops = 3;
int flag = 0;
//mutex
pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cnd = PTHREAD_COND_INITIALIZER;

void *processOne(void *arg)
{
    pthread_mutex_lock(&mtx);
    int value = *((int *)arg);

    printf("Step %d\n", value);

    //signal
    if (value == 2)
    {
        //change the condition variable
        flag = 1;
        //signal to thread two
        pthread_cond_signal(&cnd);
    }

    pthread_mutex_unlock(&mtx);
    return NULL;
}

void *processTwo(void *arg)
{
    pthread_mutex_lock(&mtx);

    //wait for process one to complete
    if (flag == 0)
    {
        pthread_cond_wait(&cnd, &mtx);
    }

    printf("Process two complete!\n");

    pthread_mutex_unlock(&mtx);
    return NULL;
}

int main()
{
    pthread_t threadIdentifier;
    pthread_t threadTwo;

    //thread two
    pthread_create(&threadTwo, 0, processTwo, NULL);

    //create threads for process one
    for (int i = 0; i < numLoops; i++)
    {
        pthread_create(&threadIdentifier, 0, processOne, &i);
        pthread_join(threadIdentifier, 0);
    }

    pthread_join(threadTwo, 0);

    return 0;
}