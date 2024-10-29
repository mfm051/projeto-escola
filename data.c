#include "data.h"

int comparaData(Data a, Data b) {
    if (a.ano == b.ano && a.mes == b.mes && a.dia == b.dia)
        return 0;
    else if ((a.ano > b.ano) || 
             (a.ano == b.ano && a.mes > b.mes) ||
             (a.ano == b.ano && a.mes == b.mes && a.dia > b.dia))
        return 1;
    else
        return -1;
}