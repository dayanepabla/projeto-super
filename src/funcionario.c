#include "funcionario.h"
#include "utils.h"

int funcionario_menu () {
    int opcao;

    // Limpa o terminal e exibe o cabeçalho
    limpar_terminal ();
    cabecalho ("Opções para funcionário");

    // Opções de busca.
    printf("Buscar produto\n");
    printf("  [1] por nome\n");
    printf("  [2] por código\n");
    printf("  [3] por fabricante\n");

    // Opções de produtos.
    printf("Produtos\n");
    printf("  [4] cadastrar\n");
    printf("  [5] remover\n");

    // Opções de estoque.
    printf("Estoque\n");
    printf("  [6] repor\n");

    rodape ();

    scanf ("%i", &opcao);

    return opcao;
}
