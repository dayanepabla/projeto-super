#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "globals.h"


void cabecalho (char *tela) {
    printf("==========================================================================\n\n");
    printf("\t\t\t\tSUPERMERCADO\t\t\t\n\n");
    printf("==========================================================================\n");
    printf("Existem %i produto(s) no estoque.\n\n", estoque->qtd_produtos);

    if (tela)
        printf("Você está em: %s\n\n", tela);
}

void rodape () {
    printf("\n\nUse Control<C> para encerrar a qualquer momento.\n");
    printf("Sua opção: ");
}

void aguarde () {
    printf("Digite 'c' para continuar...\n");
    while (getchar() != 'c');
}

void limpar_terminal () {
    printf("\033[2J\033[1;1H");
}

Produto* ler_produto () {
    float preco;
    Data* validade;
    char nome[50], categoria[50], fabricante[50], descricao[50];
    int codigo, quantidade, corredor, prateleira, dia, mes, ano;

    printf("Nome: ");
    scanf("%s", nome);

    printf("Categoria: ");
    scanf("%s", categoria);

    printf("Código: ");
    scanf("%i", &codigo);

    printf("Preço: ");
    scanf("%f", &preco);

    printf("Quantidade: ");
    scanf("%i", &quantidade);

    printf("Fabricante: ");
    scanf("%s", fabricante);

    printf("Descricao: ");
    scanf("%s", descricao);

    printf("Validade (aaaa/mm/dd): ");
    scanf("%i/%i/%i", &ano, &mes, &dia);

    printf("Corredor: ");
    scanf("%i", &corredor);

    printf("Prateleira: ");
    scanf("%i", &prateleira);

    validade = data_novo(ano, mes, dia);

    Produto *prod = produto_novo(nome, categoria, codigo, preco, quantidade,
                        fabricante, descricao, validade, corredor, prateleira);

    produto_listar(prod);

    return prod;
}

void pswap (Produto *prod1, Produto *prod2) {
    size_t psize;
    Produto *aux;

    psize = sizeof(Produto);
    aux = (Produto *) malloc(psize);

    // Copia prod1 para aux.
    memcpy(aux, prod1, psize);

    // Copia prod2 para prod1.
    memcpy(prod1, prod2, psize);

    // Finaliza o swap copiando de aux para prod2.
    memcpy(prod2, aux, psize);
}
