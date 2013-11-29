#include <stdlib.h>
#include "carrinho.h"


Carrinho* carrinho_novo (int qtd_produtos, Produto *produtos) {
    Carrinho *novo_carrinho;

    if (produtos == NULL) {
        produtos = (Produto *) malloc(CARRINHO_MAX_SIZE*sizeof(Produto));
    }

    novo_carrinho = (Carrinho *) malloc(sizeof(Carrinho));
    novo_carrinho->qtd_produtos = qtd_produtos;
    novo_carrinho->produtos = produtos;

    return novo_carrinho;
}

int carrinho_cheio (Carrinho *carrinho) {
    return carrinho->qtd_produtos == CARRINHO_MAX_SIZE;
}

void carrinho_add_produto (Carrinho *carrinho, Produto *prod) {
    if (carrinho_cheio (carrinho))
        return;

    carrinho->produtos[carrinho->qtd_produtos] = *prod;
    carrinho->qtd_produtos++;
}

void carrinho_listar (Carrinho *carrinho) {
    int i;

    for (i = 0; i < carrinho->qtd_produtos; ++i) {
        produto_listar (&carrinho->produtos[i]);
    }
}
