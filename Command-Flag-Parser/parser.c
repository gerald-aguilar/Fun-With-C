#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void parameterCheck(char *flag, char *flagCheck, int *i, int argc, char *argv[], int *setVariable)
{
    if (strcmp(flag, flagCheck) == 0 && *setVariable == 0)
    {
        //get the lambda option
        if (*i + 1 < argc)
        {
            (*i)++;
            double val = atof(argv[*i]);
            *setVariable = *setVariable + 1;

            printf("user called %s with input %.2f\n", flagCheck, val);
        }
        else
        {
            fprintf(stderr, "Missing parameter following flag!\n");
            exit(1);
        }
    }
    else if (strcmp(flag, flagCheck) == 0 && *setVariable == 1)
    {
        fprintf(stderr, "Duplicate option flag: %s\n", flag);
        exit(1);
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
        if (strcmp(flag, "-lambda") == 0)
        {
            parameterCheck(flag, "-lambda", &i, argc, argv, &lambdaSet);
        }
        else if (strcmp(flag, "-mu") == 0)
        {
            parameterCheck(flag, "-mu", &i, argc, argv, &muSet);
        }
        else if (strcmp(flag, "-r") == 0)
        {
            parameterCheck(flag, "-r", &i, argc, argv, &rSet);
        }
        else if (strcmp(flag, "-B") == 0)
        {
            parameterCheck(flag, "-B", &i, argc, argv, &bSet);
        }
        else if (strcmp(flag, "-P") == 0)
        {
            parameterCheck(flag, "-P", &i, argc, argv, &pSet);
        }
        else
        {
            //tfile
        }
    }

    return 0;
}