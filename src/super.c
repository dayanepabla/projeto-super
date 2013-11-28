#include <stdio.h>
//#include "estoque.h"
#include "produto.h"

int main () {

    FILE *bd;
    Produto *prod;
    Data *mes;
    bd = fopen ("bd.txt", "w");
    mes = data_novo (2013, 12, 1);
    prod = produto_novo ("Mouse", "Eletronico", 1300, 34.20, 500, "Microsoft", "Mouse sem fio",
                          mes, 2, 5);

    produto_listar (prod);                                                                    ;
    // printf("%i/%i/%i\n", mes.ano, mes.mes, mes.dia);
    produto_salvar(prod, bd);
    printf ("Rodando\n");

 /*   Estoque *estoque;
    char *nome, *categoria, *fabricante, *descricao;
    int codigo, quantidade, corredor, prateleira;
    float preco;
    Data validade;

    estoque = estoque_novo (0, NULL);
    nome = categoria = fabricante = descricao = NULL;*/
/*
        printf("Quantidade de itens no estoque: %i\n", estoque->qtd_produtos);
        printf("\t\t\tCADASTRAR PRODUTO\t\t\t\n");

        printf("Nome: ");
        scanf("%s", nome);

        printf("categoria: ");
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

        printf("Validade do produto: \n");
        scanf("%i %i %i\n", &validade.ano, &validade.mes, &validade.dia);

        printf("corredor: ");
        scanf("%i", &corredor);

        printf("Prateleira: ");
        scanf("%i", &prateleira);*/

    return 0;
}
