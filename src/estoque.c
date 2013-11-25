#include "estoque.h"

 Estoque estoque_novo (int qtd_produtos, Produto *produtos) {
    Estoque novo_estoque;
    novo_estoque.qtd_produtos = qtd_produtos;
    novo_estoque.produtos = produtos;

    return novo_estoque;
 }
