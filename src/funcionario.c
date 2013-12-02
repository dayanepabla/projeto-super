#include "funcionario.h"
#include "utils.h"
#include "filtros.h"

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
    printf("  [%i] listar por nome\n", FUNCIONARIO_ESTOQUE_LISTAR_NOME);

    rodape ();

    scanf ("%i", &opcao);

    return opcao;
}

void funcionario_busca_nome (Estoque *estoque) {
    Produto *produto;
    char *nome = NULL;

    limpar_terminal ();
    cabecalho ("Buscar produto por nome");

    printf ("Digite o nome do produto: ");
    scanf (" %s\n", nome);

    produto = estoque_busca_nome (estoque, nome);

    if (produto == NULL)
        printf("\nNenhum produto encontrado!\n");
    else
        produto_listar (produto);

    aguarde ();
}

void funcionario_busca_codigo (Estoque *estoque) {
    Produto *produto;
    int codigo;

    limpar_terminal ();
    cabecalho ("Buscar produto por código");

    printf("Digite o código do produto: ");
    scanf (" %i\n", &codigo);

/*    produto = estoque_busca_codigo (estoque, codigo);

    if (produto == NULL)
        printf("\nNenhum produto encontrado!\n");
    else
        produto_listar (produto);
*/
    aguarde ();
}

void funcionario_busca_fabricante (Estoque *estoque) {
    Produto *produto;
    char *fabricante = NULL;

    limpar_terminal ();
    cabecalho ("Buscar produto por fabricante");

    printf("Digite o nome do fabricante do produto: \n");
    scanf (" %s\n", fabricante);

/*    produto = estoque_busca_fabricante (estoque, fabricante);

    if (produto == NULL)
        printf("\nNenhum produto encontrado!\n");
    else
        produto_listar (produto);*/

    aguarde ();
}

void funcionario_listar_nome (Estoque *estoque) {
    limpar_terminal ();
    cabecalho ("Listagem do estoque em ordem alfabética");

    filtros_nome (estoque->produtos, estoque->qtd_produtos);
    estoque_listar (estoque);

    aguarde ();
}

void funcionario_produto_rm (Estoque *estoque) {
    Produto *produto;
    int codigo;

    limpar_terminal ();
    cabecalho ("Remover produto do estoque");

    printf("Digite o código do produto: \n");
    scanf ("%i", &codigo);

    aguarde ();
}

void funcionario_estoque_repor (Estoque *estoque) {
    Produto *produto;
    int codigo;

    limpar_terminal ();
    cabecalho ("Repor produto no estoque");

    printf("Digite o código do produto: ");
    scanf ("%i", &codigo);

    aguarde ();
}

void funcionario_add (Estoque *estoque) {
    Produto *produto;

    limpar_terminal ();
    cabecalho ("Adição de produto ao estoque");

    produto = ler_produto ();
    estoque_add_produto (estoque, produto);

    aguarde ();
}
