#include "funcionario.h"
#include <string.h>
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
    printf("  [%i] listar por preco\n", FUNCIONARIO_ESTOQUE_LISTAR_PRECO);
    printf("  [%i] listar por quantidade\n", FUNCIONARIO_ESTOQUE_LISTAR_QUANTIDADE);

    rodape ();

    scanf ("%i", &opcao);

    return opcao;
}

void funcionario_busca_nome (Estoque *estoque) {
    Produto *produto;
    char nome[100];

    limpar_terminal ();
    cabecalho ("Buscar produto por nome");

    printf ("Digite o nome do produto: ");
    scanf ("%s", nome);
    printf("\n");

    produto = estoque_busca_nome (estoque, nome);

    if (produto == NULL)
        printf("\nNenhum produto chamado %s encontrado!\n", nome);
    else {
        tabela_produto ();
        produto_listar (produto);
        hr ();
    }

    aguarde ();
}

void funcionario_busca_codigo (Estoque *estoque) {
    int codigo;
    Produto *produto;

    limpar_terminal ();
    cabecalho ("Buscar produto por código");

    printf("Digite o código do produto: ");
    scanf (" %i", &codigo);
    printf("\n");

    produto = estoque_busca_codigo (estoque, codigo);

    if (produto == NULL)
        printf("\nNenhum produto encontrado!\n");
    else {
        tabela_produto ();
        produto_listar (produto);
        hr ();
    }

    aguarde ();
}

void funcionario_busca_fabricante (Estoque *estoque) {
    char fabricante[100];

    limpar_terminal ();
    cabecalho ("Buscar produto por fabricante");

    printf("Digite o nome do fabricante do produto: ");
    scanf (" %s", fabricante);
    printf("\n");

    estoque_busca_fabricante (estoque, fabricante);

    aguarde ();
}

void funcionario_listar_nome (Estoque *estoque) {
    limpar_terminal ();
    cabecalho ("Listagem do estoque em ordem alfabética");

    filtros_nome (estoque->produtos, estoque->qtd_produtos);
    estoque_listar (estoque);

    aguarde ();
}

void funcionario_listar_preco (Estoque *estoque) {
    limpar_terminal ();
    cabecalho ("Listagem do estoque por preço");

    filtros_menor_preco (estoque->produtos, estoque->qtd_produtos);
    estoque_listar (estoque);

    aguarde ();
}

void funcionario_listar_quantidade (Estoque *estoque) {
    limpar_terminal ();
    cabecalho ("Listagem do estoque por preço");

    filtros_menor_quantidade (estoque->produtos, estoque->qtd_produtos);
    estoque_listar (estoque);

    aguarde ();
}

void funcionario_produto_rm (Estoque *estoque) {
    int codigo;
    char confirmacao[5];
    Produto *produto;

    limpar_terminal ();
    cabecalho ("Remover produto do estoque");

    printf("Digite o código do produto: ");
    scanf ("%i", &codigo);
    printf("\n");

    produto = estoque_busca_codigo (estoque, codigo);

    if (produto == NULL)
        return;

    // Exibe o produto antes da remoção.
    tabela_produto (produto);
    produto_listar (produto);
    hr ();

    printf("\nTem certeza que deseja remover este produto? (Sim/Nao) ");
    scanf(" %s", confirmacao);

    if (strcmp (confirmacao, "Sim") == 0)
        estoque_rm_produto (estoque, produto);

    aguarde ();
}

void funcionario_estoque_repor (Estoque *estoque) {
    int qtd, codigo;
    Data *validade;

    limpar_terminal ();
    cabecalho ("Repor produto no estoque");

    printf("Digite o código do produto: ");
    scanf ("%i", &codigo);

    printf("Digite quantidade do produto: ");
    scanf ("%i", &qtd);

    validade = data_atual ();
    estoque_repor (estoque, codigo, validade, qtd);

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
