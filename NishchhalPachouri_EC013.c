#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <wait.h>

// Internal Command

void pwd()
{
    char s[100];
    printf("%s\n", getcwd(s, 100));
}

void cd(char *a)
{
    chdir(a);
}

void echo(char *a)
{
    if ((a[0] == 'e') && (a[1] == 'c') && (a[2] == 'h') && (a[3] == 'o') && (a[4] == ' ') )
    {

        int n = strlen(a);
        int m = 5;
        if(a[5] == '\"')
        {
            m++;
            n--;
        }
        for (int i = m; i < n; i++)
        {
        
            printf("%c", a[i]);
        }
    }
    else
    {
        printf("Invalid Syntax : Command Not found");
    }
    printf("\n");
}

char **diffrentiator(char *input)
{
    char **command = malloc(8 * sizeof(char *));
    char *separator = " ";
    char *parsed;
    int index = 0;
    //I\0am\0 in OS VIVA
    parsed = strtok(input, separator);
    while (parsed != NULL)
    {
        command[index] = parsed;
        index++;

        parsed = strtok(NULL, separator);
    }

    command[index] = NULL;
    return command;
}

void ls(char *a, char *b)
{
    char *path = a;
    char *arg1 = b;

    int cpid = fork();
    int status;
    if (cpid == 0)
    {

        execlp(path, path, arg1, NULL);
        exit(0);
    }
    else
    {
        wait(&status);
    }
}

void mkdir(char *a, char *b)
{
    char *path = a;
    char *arg1 = b;

    int cpid = fork();
    int status;
    if (cpid == 0)
    {

        execlp(path, path, arg1, NULL);
        exit(0);
    }
    else
    {
        wait(&status);
    }
}

void cat(char *a, char *b)
{
    char *path = a;
    char *arg1 = b;

    int cpid = fork();
    int status;
    if (cpid == 0)
    {

        execlp(path, path, arg1, NULL);
        exit(0);
    }
    else
    {
        wait(&status);
    }
}

void rm(char *a, char *b)
{
    char *path = a;
    char *arg1 = b;

    int cpid = fork();
    int status;
    if (cpid == 0)
    {

        execlp(path, path, arg1, NULL);
        exit(0);
    }
    else
    {
        wait(&status);
    }
}

void date(char *a, char *b)
{
    char *path = a;
    char *arg1 = b;

    int cpid = fork();
    int status;
    if (cpid == 0)
    {

        execlp(path, path, arg1, NULL);
        exit(0);
    }
    else
    {
        wait(&status);
    }
}

void cmd_identify(char a[])
{
    char temp[100];
    strcpy(temp, a);

    char int1[] = "pwd";
    char int2[] = "cd";
    char int3[] = "echo";
    char ex1[] = "ls";
    char ex2[] = "mkdir";
    char ex3[] = "cat";
    char ex4[] = "rm";
    char ex5[] = "date";

    char **cmd;
    cmd = diffrentiator(a);

    // Internal command Comparision
    if (strcmp(cmd[0], int1) == 0)
    {
        pwd();
    }
    else if (strcmp(cmd[0], int2) == 0)
    {
        cd(cmd[1]);
    }
    else if (strcmp(cmd[0], int3) == 0)
    {
        echo(temp);
    }
    // External Command Comparision

    else if (strcmp(cmd[0], ex1) == 0)
    {
        ls(cmd[0], cmd[1]);
    }
    else if (strcmp(cmd[0], ex2) == 0)
    {
        mkdir(cmd[0], cmd[1]);
    }
    else if (strcmp(cmd[0], ex3) == 0)
    {
        cat(cmd[0], cmd[1]);
    }
    else if (strcmp(cmd[0], ex4) == 0)
    {
        rm(cmd[0], cmd[1]);
    }
    else if (strcmp(cmd[0], ex5) == 0)
    {
        date(cmd[0], cmd[1]);
    }
    else
    {
        printf("%s : Command not found",temp);
    }
}

int main()
{

    while (1)
    {
        printf("\nnishchhal007@NishchhalMSI:~$ ");

        char a[100];
        scanf("%[^\n]%*c", a);
        cmd_identify(a);

        printf("\n");
    }

    return 0;
}