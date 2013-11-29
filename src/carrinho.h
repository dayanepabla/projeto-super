#include "produto.h"

#define CARRINHO_MAX_SIZE 100


struct _carrinho {
    int qtd_produtos;
    Produto *produtos;
};

typedef struct _carrinho Carrinho;

/*
 * Inicializa o carrinho.
 * Inicializa um produto. Se produtos for NULL inicializa
 * uma lista de tamanho CARRINHO_MAX_SIZE.
 */
Carrinho* carrinho_novo (int qtd_produtos, Produto *produtos);
