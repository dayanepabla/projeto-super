#include "cliente.h"
#include <stdio.h>
#include "utils.h"

int cliente_menu () {
    int opcao;

    // Limpa o terminal e exibe o cabeçalho
    limpar_terminal ();
    cabecalho ("Opções para cliente");

    // Opções de busca.
    printf("Buscar produto\n");
    printf("  [%i] por nome\n", CLIENTE_BUSCA_NOME);
    printf("  [%i] por fabricante\n", CLIENTE_BUSCA_FABRICANTE);
    printf("  [%i] por categoria\n", CLIENTE_BUSCA_CATEGORIA);

    // Opções do carrinho.
    printf("Carrinho de compras\n");
    printf("  [%i] listar\n", CLIENTE_CARRINHO_LISTAR);
    printf("  [%i] inserir\n", CLIENTE_CARRINHO_ADD);
    printf("  [%i] retirar\n", CLIENTE_CARRINHO_RM);
    printf("  [%i] subtotal\n", CLIENTE_CARRINHO_SUBTOTAL);
    printf("  [%i] fechar compra\n", CLIENTE_CARRINHO_FECHAR_COMPRA);

    rodape ();

    scanf ("%i", &opcao);

    return opcao;
}
