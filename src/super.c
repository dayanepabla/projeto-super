#include <stdio.h>
#include "estoque.h"

int main () {
    Estoque *estoque;
    char *nome, *categoria, *fabricante, *descricao;
    int codigo, quantidade, corredor, prateleira;
    float preco;
    Data validade;

    estoque = estoque_novo (0, NULL);
    nome = categoria = fabricante = descricao = NULL;

    while (1) {
        printf("Quantidade de itens no estoque: %i\n", estoque->qtd_produtos);
        printf("\t\t\tCADASTRAR PRODUTO\t\t\t\n");

        printf(" nome: \n");
        scanf("%s", nome);

        // printf(" codigo: \n");
        // scanf("%i", &codigo);

        // printf(" categoria: \n");
        // scanf("%s", categoria);

        // printf(" preco: \n");
        // scanf("%2f", &preco);

        // printf(" quantidade: \n");
        // scanf("%i", &quantidade);

        // printf(" fabricante: \n");
        // scanf("%s", fabricante);

        // printf(" descricao: \n");
        // scanf("%s", descricao);

        // printf(" validade: \n");
        // scanf(" %i/%i%i", &validade.ano, &validade.mes, &validade.dia);

        // printf(" corredor: \n");
        // scanf("%i", &corredor);

        // printf(" prateleira: \n");
        // scanf("%i", &prateleira);
    }

    return 0;
}
