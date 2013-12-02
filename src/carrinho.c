#include "carrinho.h"
#include <stdlib.h>
#include <assert.h>
#include "utils.h"


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

int carrinho_vazio (Carrinho *carrinho) {
    return carrinho->qtd_produtos == 0;
}

void carrinho_add_produto (Carrinho *carrinho, Produto *prod) {
    if (carrinho_cheio (carrinho))
        return;

    carrinho->produtos[carrinho->qtd_produtos] = *prod;
    carrinho->qtd_produtos++;
}

void carrinho_rm_produto (Carrinho *carrinho, int indice) {
    // Verifica se o indice é nulo.
    assert (indice >= 0);

    // Determina a última posição do vetor produtos e atualiza
    // a quantidade de produtos.
    int ultimo = (carrinho->qtd_produtos > 0) ? --carrinho->qtd_produtos : 0;

    // Troca o produto indicado por indice e o ultimo na lista
    // de produtos do carrinho.
    pswap (&carrinho->produtos[indice], &carrinho->produtos[ultimo]);
}

void carrinho_listar (Carrinho *carrinho) {
    int i;

    for (i = 0; i < carrinho->qtd_produtos; ++i) {
        produto_listar (&carrinho->produtos[i]);
    }
}

float carrinho_subtotal (Carrinho *carrinho){
    int i;
    Produto *prod;
    float subtotal = 0.0;

    for (i = 0; i < carrinho->qtd_produtos; i++) {
        prod = &carrinho->produtos[i];

        subtotal += (prod->preco * prod->quantidade);
    }

    return subtotal;
}

float carrinho_total (Carrinho *carrinho) {
    int i;
    Produto *prod;
    float total = 0.0;

    for (i = 0; i < carrinho->qtd_produtos; i++) {
        prod = &carrinho->produtos[i];

        total += (prod->preco * prod->quantidade);
    }
    return total;
}
