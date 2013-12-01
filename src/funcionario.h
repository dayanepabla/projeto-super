#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include "estoque.h"


typedef enum {
    // Opções de busca.
    FUNCIONARIO_BUSCA_NOME = 1,
    FUNCIONARIO_BUSCA_CODIGO = 2,
    FUNCIONARIO_BUSCA_FABRICANTE = 3,

    // Opções de produto.
    FUNCIONARIO_PRODUTO_ADD = 4,
    FUNCIONARIO_PRODUTO_RM = 5,

    // Opções de estoque.
    FUNCIONARIO_ESTOQUE_REPOR = 6
} FuncionarioOpcoes;


/*
 * Exibe o menu de opções para o funcionário.
 */
int funcionario_menu ();

/*
 * Busca um produto, por nome, no estoque.
 */
void funcionario_busca_nome (Estoque *estoque);

#endif
