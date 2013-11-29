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
