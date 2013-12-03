#include "carrinho.h"
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "utils.h"
#include "estoque.h"
#include "globals.h"


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

void carrinho_add_produto (Carrinho *carrinho, Produto *prod, int qtd) {
    Produto *prod_estoque, *prod_carrinho;

    if (carrinho_cheio (carrinho))
        return;

    // Busca o produto no estoque.
    prod_estoque = estoque_busca_codigo (estoque, prod->codigo);

    if (prod_estoque == NULL)
        return;

    // Verifica a disponibilidade em estoque da quantidade desejada.
    if (prod_estoque->quantidade < qtd)
        return;


    prod_carrinho = &carrinho->produtos[carrinho->qtd_produtos];

    // Faz uma cópia do produto para o carrinho.
    memcpy (prod_carrinho, prod_estoque, sizeof(Produto));

    // Atualiza as quantidades do produto.
    prod_estoque->quantidade -= qtd;
    prod_carrinho->quantidade = qtd;

    // Atualiza a quantidade de itens no carrinho.
    carrinho->qtd_produtos++;
}

void carrinho_rm_produto (Carrinho *carrinho, int codigo, int qtd) {
    Produto *prod_carrinho;

    // Busca o produto no carrinho.
    prod_carrinho = carrinho_busca_codigo (carrinho, codigo);

    if (prod_carrinho == NULL)
        return;

    // Remove a quantidade desejada.
    prod_carrinho->quantidade -= qtd;

    if (prod_carrinho->quantidade <= 0)
    {
        Produto *ultimo_produto;

        // Pega o último elemento do carrinho.
        ultimo_produto = &carrinho->produtos[carrinho->qtd_produtos];

        // Remove definitivamente o produto do carrinho.
        pswap (prod_carrinho, ultimo_produto);

        carrinho->qtd_produtos--;
    }
}

void carrinho_listar (Carrinho *carrinho) {
    int i;

    tabela_produto ();

    for (i = 0; i < carrinho->qtd_produtos; ++i) {
        produto_listar (&carrinho->produtos[i]);
    }

    hr ();
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

Produto* carrinho_busca_codigo (Carrinho *carrinho, int codigo) {
    int i;

    for (i = 0; i < carrinho->qtd_produtos; i++) {
        if (carrinho->produtos[i].codigo == codigo)
            return &carrinho->produtos[i];
    }

    return NULL;
}
