#ifndef DATA_H
#define DATA_H

struct _data{
    int ano;
    int mes;
    int dia;
};

typedef struct _data Data;

/*
* Retorna um objeto do tipo data.
*/
Data* data_novo(int ano, int mes, int dia);

/*
 * Retorna um objeto representando a data atual.
 */
Data* data_atual();

#endif
