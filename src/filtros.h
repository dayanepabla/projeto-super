#ifndef FILTROS_H
#define FILTROS_H

#include "produto.h"


/*
 * Filtra por ordem alfabética
 */
void filtros_nome (Produto *produtos, int qtd);

/*
 * Filtra por menor preço
 */
void filtros_menor_preco (Produto *produtos, int qtd);
#endif
