#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

//global variables
int num = 0;
//mutex
pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;

//processes
void *addToNum(void *arg)
{
    //lock the data
    pthread_mutex_lock(&mtx);

    //add arg to num
    num = num + *((int *)arg);

    //unlock the data
    pthread_mutex_unlock(&mtx);
    return 0;
}

//main
int main(void)
{
    //thread identifier
    pthread_t t;

    //process input argument
    int input = 1;

    //use a loop this time to create the threaded process
    for (int i = 0; i < 2; i++)
    {
        //create the thread
        pthread_create(&t, 0, addToNum, &input);

        //sync the threads using pthread_join
        pthread_join(t, 0);
    }

    printf("the value of num is: %d\n", num);

    return EXIT_SUCCESS;
}