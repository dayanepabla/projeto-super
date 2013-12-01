#ifndef CLIENTE_H
#define CLIENTE_H


typedef enum {
    // Opções de busca.
    CLIENTE_BUSCA_NOME = 1,
    CLIENTE_BUSCA_PRECO = 2,
    CLIENTE_BUSCA_FABRICANTE = 3,

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

#endif
