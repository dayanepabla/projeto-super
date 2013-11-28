#include "estoque.h"
#include <stdlib.h>


Estoque* estoque_novo (int qtd_produtos, Produto *produtos) {
    Estoque *novo_estoque;

    if (produtos == NULL) {
        produtos = (Produto *) malloc(ESTOQUE_MAX_SIZE*sizeof(Produto));
    }

    novo_estoque = (Estoque *) malloc(sizeof(Estoque));
    novo_estoque->qtd_produtos = qtd_produtos;
    novo_estoque->produtos = produtos;

    return novo_estoque;
}

Produto* estoque_busca_nome (Estoque* estoque, char *nome_produto) {
    int i;

    for (i = 0; i < estoque->qtd_produtos; i++) {
        if (estoque->produtos[i].nome == nome_produto)
            return &estoque->produtos[i];
    }

    return NULL;
    }

void estoque_add_produto (Estoque *estoque, Produto *produto) {
    estoque->produtos[estoque->qtd_produtos] = *produto;
    estoque->qtd_produtos++;
  }

void estoque_listar (Estoque *estoque){

    int i;

    for (i = 0; i < estoque->qtd_produtos; i++) {
       produto_listar (&estoque->produtos[i]);
    }
}
int estoque_salvar (Estoque *estoque,FILE *bd) {
    int i;

    if (bd == NULL)
        return -1;
    for (i = 0; i < estoque->qtd_produtos; i++){
        if (produto_salvar (&estoque->produtos[i], bd) == -1)
            return -1
    }
    return 1;
}
