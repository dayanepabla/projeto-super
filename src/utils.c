#include "utils.h"
#include <stdio.h>


void cabecalho (char *tela) {
    printf("\t\t\tSUPERMERCADO\t\t\t\n");

    if (tela)
        printf("%s\n", tela);
}

void limpar_terminal () {
    printf("\033[2J\033[1;1H");
}

Produto *ler_produto () {
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
    scanf("%i %i %i", &ano, &mes, &dia);

    printf("Corredor: \n");
    scanf("%i", &corredor);

    printf("Prateleira: ");
    scanf("%i", &prateleira);

    validade = data_novo(ano, mes, dia);

    return produto_novo(nome, categoria, codigo, preco, quantidade,
                        fabricante, descricao, validade, corredor, prateleira);
}
