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
    printf("  [1] por nome\n");
    printf("  [2] por fabricante\n");

    // Opções do carrinho.
    printf("Carrinho de compras\n");
    printf("  [3] listar\n");
    printf("  [4] inserir\n");
    printf("  [5] retirar\n");
    printf("  [6] subtotal\n");
    printf("  [7] fechar compra\n");

    rodape ();

    scanf ("%i", &opcao);

    return opcao;
}
