#ifndef CLIENTE_H
#define CLIENTE_H


typedef enum {
    CLIENTE_OPCAO_BUSCA_NOME = 1,
    CLIENTE_OPCAO_BUSCA_PRECO = 2
} ClienteOpcoes;


/*
 * Exibe o menu de opções de cliente. Retorna a opção
 * selecionada pelo cliente.
 */
int cliente_menu ();

#endif
