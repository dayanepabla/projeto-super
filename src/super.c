#include <stdio.h>
#include "estoque.h"
//#include "produto.h"

int main () {

    FILE *bd;
    Produto *prod, *prod1;
    Data *data;
    Estoque estoque;

    estoque = estoque_novo(0,NULL);
    bd = fopen ("bd.txt", "w");
    mes = data_novo (2013, 12, 1);
    prod = produto_novo ("Mouse", "Eletronico", 1300, 34.20, 5, "Microsoft", "Mouse sem fio",
                          data, 2, 5);
    prod1 = produto_novo ("Teclada", "Eletronico", 1301, 84.20, 400, "Positivo", "Teclado sem fio",
                          data, 2, 5);

/*    produto_listar (prod);                                                                    ;
    // printf("%i/%i/%i\n", mes.ano, mes.mes, mes.dia);
    produto_salvar(prod, bd);
    printf ("Rodando\n");*/
    //estoque_listar(estoque);
    estoque_add_produto (estoque, prod);
    estoque_add_produto (estoque, prod1);
    estoque_listar (estoque);
    estoque_salvar (estoque, bd);
    estoque_baixo (estoque, 10);
 +    ///produto_listar (prod);                                                                    ;
 +    // printf("%i/%i/%i\n", data.ano, data.mes, data.dia);
 +    //produto_salvar(prod, bd);
 +    //printf ("Rodando\n");
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
