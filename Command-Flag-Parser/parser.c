#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//global
int missingParameter = 0;

void parameterCheck(char *flag, char *flagCheck, int *i, int argc, char *argv[], int *setVariable)
{
    if (strcmp(flag, flagCheck) == 0 && *setVariable == 0)
    {
        //get the lambda option
        if (*i + 1 < argc)
        {
            (*i)++;
            int lambda = atoi(argv[*i]);
            *setVariable = *setVariable + 1;

            printf("user called %s with input %d\n", flagCheck, lambda);
        }
        else
        {
            fprintf(stderr, "Missing parameter following flag!\n");
            exit(1);
        }
    }
    else if (*setVariable == 1)
    {
        fprintf(stderr, "Duplicate option flag: %s\n", flag);
    }
    else
    {
        fprintf(stderr, "Unknown option: %s\n", flag);
        exit(1);
    }
}

int main(int argc, char *argv[])
{
    printf("num args: %d\n", argc);

    int lambdaSet = 0, muSet = 0, rSet = 0, bSet = 0, pSet = 0, nSet = 0, tSet = 0;
    for (int i = 1; i < argc; i++)
    {
        char *flag = argv[i];
        parameterCheck(flag, "-lambda", &i, argc, argv, &lambdaSet);
        parameterCheck(flag, "-mu", &i, argc, argv, &muSet);
        parameterCheck(flag, "-r", &i, argc, argv, &rSet);
        parameterCheck(flag, "-B", &i, argc, argv, &bSet);
        parameterCheck(flag, "-P", &i, argc, argv, &pSet);
        //parameterCheck(flag, &i, argc, argv, &tSet);
    }

    return 0;
}