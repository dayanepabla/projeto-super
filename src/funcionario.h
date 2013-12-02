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
    FUNCIONARIO_ESTOQUE_REPOR = 6,
    FUNCIONARIO_ESTOQUE_LISTAR_NOME = 7,
    FUNCIONARIO_ESTOQUE_LISTAR_PRECO = 8
} FuncionarioOpcoes;


/*
 * Exibe o menu de opções para o funcionário.
 */
int funcionario_menu ();

/*
 * Busca um produto, por nome, no estoque.
 */
void funcionario_busca_nome (Estoque *estoque);

/*
 * Busca um produto, por código, no estoque.
 */
void funcionario_busca_codigo (Estoque *estoque);

/*
 * Busca um produto, por fabricante, no estoque.
 */
void funcionario_busca_fabricante (Estoque *estoque);

/*
 * Lista os produtos do estoque em ordem alfabética.
 */
void funcionario_listar_nome (Estoque *estoque);

/*
 * Lista os produtos do estoque pelo preço, do menor
 * para o maior.
 */
void funcionario_listar_preco (Estoque *estoque);

/*
 * Remove produto do estoque.
 */
void funcionario_produto_rm (Estoque *estoque);

/*
 * Repõe produto do estoque.
 */
void funcionario_estoque_repor (Estoque *estoque);

/*
 * Adição de produto ao estoque.
 */
void funcionario_add (Estoque *estoque);

#endif
