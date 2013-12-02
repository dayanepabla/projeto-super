#ifndef FILTROS_H
#define FILTROS_H

#include "produto.h"


/*
 * Filtra por ordem alfabética.
 */
void filtros_nome (Produto *produtos, int qtd);

/*
 * Filtra por menor preço.
 */
void filtros_menor_preco (Produto *produtos, int qtd);

/*
 * Filtra por quantidade em estoque, menores primeiro.
 */
void filtros_menor_quantidade (Produto *produtos, int qtd);

#endif
