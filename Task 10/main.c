//
//  main.c
//  Task 10
//
//  Created by Pavel iPro on 01.02.2024.
//

//  Задача 1
/*
#include <stdio.h>
#include <string.h>
 
const int line_width = 1024;
void change_symbols(int size, char *line)
{
    int i = 0, j;
    char a;
    while (i < size)
    {
        while (line[i] == ' ')
            i++;
        j = i + 1;
        while (line[j] == ' ')
            j++;
        if (j >= size)
            break;
            a = line[i];
            line[i] = line[j];
            line[j] = a;
            i = j + 1;
    }
}
 
 int main(int argc, const char * argv[])
{
    char line[line_width];
    FILE *fp;
     
    fp = fopen("input.txt", "r");
    fscanf(fp, "%[^\n]", line);
    fclose(fp);
    change_symbols(strlen(line), line);
    fp = fopen("output.txt", "w");
    fprintf(fp, "%s", line);
    fclose(fp);
    return 0;
}
*/
 //  Задача 2
 /*
#include <stdio.h>

enum States { Start, In, Out };

int main(int argc, const char * argv[])
{
    FILE *f_in   = fopen("input.txt", "r");
    FILE *f_out  = fopen("output.txt", "w");
    int a, state = Start;
    while ((a = fgetc(f_in)) != EOF)
    {
        switch (state)
        {
            case Start:
                if (a != ' ')
                {
                    state = In;
                    fputc(a, f_out);
                }
                break;
            case In:
                if (a == ' ')
                    state = Out;
                else
                    fputc(a, f_out);
                break;
            case Out:
                if (a != ' ')
                {
                    state = In;
                    fputc(' ', f_out);
                    fputc(a, f_out);
                }
                break;
        }
    }
    fclose(f_in);
    fclose(f_out);
    return 0;
}
*/
 //  Задача 3
 ///*
#include <stdio.h>
#include <string.h>

#define SIZE 10001

void input(char *strIn)
{
    FILE *in;
    in = fopen("input.txt", "r");
    while(fscanf(in, "%[^\n]", strIn) == 1);
    fclose(in);
}

void extension(char *strExt, char *buffer)
{
    for(int i = strlen(strExt) - 1; i >= 0; i--)
    {
        if(strExt[i] == '/')
        {
            strcpy(buffer, strExt);
            strcat(buffer, ".html");
            break;
        }
        else if(strExt[i] == '.')
        {
            for(int j = 0; j < i; j++)
                buffer[j] = strExt[j];
            memcpy(buffer,strExt,i);
            strcat(buffer, ".html");
            break;
        }
    }
}

void output(char *strOut)
{
    FILE *out;
    out = fopen("output.txt", "w");
    fprintf(out, "%s", strOut);
    fclose(out);
}

int main(int argc, char **argv)
{
    char str[SIZE], strFinal[SIZE];;
    input(str);
    extension(str, strFinal);
    output(strFinal);
    return 0;
}
