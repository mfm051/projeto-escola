#ifndef DATA_H
#define DATA_H

typedef struct 
{
    int dia;
    int mes;
    int ano;
} Data;

int comparaData(Data a, Data b);

#endif