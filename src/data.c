#include <stdlib.h>
#include <time.h>
#include "data.h"

Data* data_novo(int ano, int mes, int dia){
    Data *nova_data;

    nova_data = (Data *) malloc(sizeof(Data));
    nova_data->ano = ano;
    nova_data->mes = mes;
    nova_data->dia = dia;

    return nova_data;
 }

Data* data_atual() {
    int ano, mes, dia;
    struct tm * local;
    time_t t;

    t = time(NULL);
    local = localtime (& t);
    dia = local->tm_mday;
    mes = local->tm_mon + 1;
    ano = local->tm_year + 1900;

    return data_novo(ano, mes, dia);
}
