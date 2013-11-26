#include "estoque.h"

Estoque estoque_novo (int qtd_produtos, Produto *produtos) {
    Estoque novo_estoque;

    novo_estoque.qtd_produtos = qtd_produtos;
    novo_estoque.produtos = produtos;

    return novo_estoque;
}

Produto* estoque_busca_nome (Estoque estoque, char *nome_produto) {
    int i;

    for (i = 0; i < estoque.qtd_produtos; i++) {
        if (estoque.produtos[i].nome == nome_produto)
            return &estoque.produtos[i];
    }

    return NULL;
}

void estoque_add_produto (Estoque *estoque, Produto *produto) {
    estoque->produtos[estoque->qtd_produtos] = *produto;
    estoque->qtd_produtos++;
}
