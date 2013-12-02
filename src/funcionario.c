#include "funcionario.h"
#include "utils.h"

int funcionario_menu () {
    int opcao;

    // Limpa o terminal e exibe o cabeçalho
    limpar_terminal ();
    cabecalho ("Opções para funcionário");

    // Opções de busca.
    printf("Buscar produto\n");
    printf("  [%i] por nome\n", FUNCIONARIO_BUSCA_NOME);
    printf("  [%i] por código\n", FUNCIONARIO_BUSCA_CODIGO);
    printf("  [%i] por fabricante\n", FUNCIONARIO_BUSCA_FABRICANTE);

    // Opções de produtos.
    printf("Produto\n");
    printf("  [%i] cadastrar\n", FUNCIONARIO_PRODUTO_ADD);
    printf("  [%i] remover\n", FUNCIONARIO_PRODUTO_RM);

    // Opções de estoque.
    printf("Estoque\n");
    printf("  [%i] repor\n", FUNCIONARIO_ESTOQUE_REPOR);

    rodape ();

    scanf ("%i", &opcao);

    return opcao;
}

void funcionario_busca_nome (Estoque *estoque) {
    int results;
    char *nome = NULL;
    Produto *produtos = NULL;

    limpar_terminal ();
    cabecalho ("Buscar produto por nome");

    printf ("Digite o nome do produto: ");
    scanf (" %s\n", nome);

    results = estoque_busca_nome (estoque, nome, produtos);

    printf("%i\n", results);

    aguarde ();
}
