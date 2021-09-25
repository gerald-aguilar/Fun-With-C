#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

//some global varible
int input = 0;

void *server(void *arg)
{
    input = (*((int *)arg)) + input;
    printf("i has value: %d\n", input);

    return NULL;
}

void start_servers(void)
{
    //thread identifiers
    pthread_t threadOne, threadTwo;
    int increment = 1;

    //create 2 threads!
    pthread_create(
        &threadOne,
        0,
        server,
        &increment);

    pthread_create(
        &threadTwo,
        0,
        server,
        &increment);

    //tells the program to allow the thread processes to terminate before continuing.
    pthread_join(threadOne, NULL);
    pthread_join(threadTwo, NULL);
}

int main(void)
{

    //run our multithreaded program
    start_servers();

    return EXIT_SUCCESS;
}