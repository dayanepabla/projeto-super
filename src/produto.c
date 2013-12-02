#include "produto.h"
#include <stdlib.h>
#include <assert.h>
#include <string.h>

Produto* produto_novo(char *nome, char *categoria, int codigo, float preco, int quantidade,
                       char *fabricante, char *descricao, Data* validade, int corredor, int prateleira){

    Produto *novo_produto;

    // Alocação de memória dos ponteiros.
    novo_produto = (Produto *) malloc(sizeof(Produto));
    novo_produto->nome = (char *) malloc(strlen(nome)*sizeof(char));
    novo_produto->categoria = (char *) malloc(strlen(categoria)*sizeof(char));
    novo_produto->fabricante = (char *) malloc(strlen(fabricante)*sizeof(char));
    novo_produto->descricao = (char *) malloc(strlen(descricao)*sizeof(char));

    strcpy(novo_produto->nome, nome);
    strcpy(novo_produto->categoria, categoria);
    strcpy(novo_produto->fabricante, fabricante);
    strcpy(novo_produto->descricao, descricao);

    novo_produto->codigo = codigo;
    novo_produto->preco = preco;
    novo_produto->quantidade = quantidade;
    novo_produto->validade = validade;
    novo_produto->corredor = corredor;
    novo_produto->prateleira = prateleira;

    return novo_produto;
 }

int produto_salvar (Produto *prod, FILE *bd) {

    assert (bd != NULL);

    fprintf(bd, "[produto]\n");
    fprintf(bd, "nome: %s\n", prod->nome);
    fprintf(bd, "categoria: %s\n", prod->categoria);
    fprintf(bd, "codigo: %i\n", prod->codigo);
    fprintf(bd, "preco: %.2f\n", prod->preco);
    fprintf(bd, "quantidade: %i\n", prod->quantidade);
    fprintf(bd, "fabricante: %s\n", prod->fabricante);
    fprintf(bd, "descricao: %s\n", prod->descricao);
    fprintf(bd, "validade: %i/%i/%i\n", prod->validade->ano, prod->validade->mes, prod->validade->dia);
    fprintf(bd, "corredor: %i\n", prod->corredor);
    fprintf(bd, "prateleira: %i\n\n", prod->prateleira);

    return 1;
}

void produto_listar (Produto *prod) {
    assert (prod != NULL);

    // printf("| Nome          | Categoria      | Validade    |Loc.  | Qtd.  | Preço   |\n");
    printf("| %s  | %s | %i/%i/%i | %i-%i| %i | %f |\n",
        prod->nome, prod->categoria, prod->validade->dia, prod->validade->mes, prod->validade->ano,
        prod->corredor, prod->prateleira, prod->quantidade, prod->preco);                                                      ;
}
