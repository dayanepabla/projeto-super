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

void cliente_busca_nome (Estoque* estoque) {
    Produto *produto;
    char nome[100];

    limpar_terminal ();
    cabecalho ("Buscar produto por nome");

    printf ("Digite o nome do produto: ");
    scanf (" %s", nome);
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

void cliente_busca_fabricante (Estoque *estoque) {
    char fabricante[100];

    limpar_terminal ();
    cabecalho ("Buscar produto por fabricante");

    printf("Digite o nome do fabricante do produto: ");
    scanf (" %s", fabricante);
    printf("\n");

    estoque_busca_fabricante (estoque, fabricante);

    aguarde ();
}

void cliente_busca_categoria (Estoque* estoque) {
    char categoria[100];

    limpar_terminal ();
    cabecalho ("Buscar produto por categoria");

    printf("Digite o nome da categoria do produto: ");
    scanf (" %s", categoria);
    printf("\n");

    estoque_lista_categoria (estoque, categoria);

    aguarde ();
}

void cliente_carrinho_listar (Carrinho* carrinho) {
    limpar_terminal ();
    cabecalho ("Produtos do seu carrinho");

    if (carrinho_vazio (carrinho))
        printf("O carrinho de compras está vazio!\n");
    else
        carrinho_listar (carrinho);

    aguarde ();
}

void cliente_carrinho_add (Estoque* estoque, Carrinho* carrinho) {
    int qtd, codigo;
    Produto* produto;

    limpar_terminal ();
    cabecalho ("Inserir produto no carrinho");

    printf ("Entre com o código do produto: ");
    scanf ("%i", &codigo);

    printf ("Quantos itens deseja adicionar: ");
    scanf ("%i", &qtd);

    produto = estoque_busca_codigo (estoque, codigo);
    carrinho_add_produto (carrinho, produto, qtd);

    aguarde ();
}

void cliente_carrinho_rm (Carrinho *carrinho) {
    int qtd, codigo;

    limpar_terminal ();
    cabecalho ("Retirar produto do carrinho");

    printf ("Entre com o código do produto: ");
    scanf ("%i", &codigo);

    printf ("Quantos itens deseja remover: ");
    scanf ("%i", &qtd);

    aguarde ();
}

void cliente_subtotal (Carrinho *carrinho) {
    limpar_terminal ();
    cabecalho ("Subtotal");

    printf("Subtotal: %.2f\n", carrinho_subtotal (carrinho));

    aguarde ();
}

void cliente_carrinho_fechar_compra (Carrinho *carrinho) {
    limpar_terminal ();
    cabecalho ("Total");

    printf("Total: %.2f\n", carrinho_total (carrinho));

    aguarde ();
}
