#ifndef CLIENTE_H
#define CLIENTE_H

#include "estoque.h"
#include "carrinho.h"

typedef enum {
    // Opções de busca.
    CLIENTE_BUSCA_NOME = 1,
    CLIENTE_BUSCA_FABRICANTE = 2,
    CLIENTE_BUSCA_CATEGORIA = 3,

    // Opções de carrinho.
    CLIENTE_CARRINHO_LISTAR = 4,
    CLIENTE_CARRINHO_ADD = 5,
    CLIENTE_CARRINHO_RM = 6,
    CLIENTE_CARRINHO_SUBTOTAL = 7,
    CLIENTE_CARRINHO_FECHAR_COMPRA = 8
} ClienteOpcoes;


/*
 * Exibe o menu de opções de cliente. Retorna a opção
 * selecionada pelo cliente.
 */
int cliente_menu ();

/*
 * Busca um produto, por nome, no estoque.
 */
void cliente_busca_nome (Estoque* estoque);

/*
 * Busca um produto, por fabricante, no estoque.
 */
void cliente_busca_fabricante (Estoque *estoque);

/*
 * Busca produto, por categoria, no estoque.
 */
void cliente_busca_categoria (Estoque* estoque);

/*
 * Lista produtos do carrinho do cliente.
 */
void cliente_carrinho_listar (Carrinho* carrinho);

/*
 * O cliente adiciona produtos ao carrinho.
 */
void cliente_carrinho_add (Estoque *estoque, Carrinho *carrinho);

/*
 * Remove um produto do carrinho.
 */
void cliente_carrinho_rm (Carrinho *carrinho);

/*
 * Exibe o subtotal do carrinho de compras.
 */
void cliente_subtotal (Carrinho *carrinho);

#endif
