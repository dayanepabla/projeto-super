#include "produto.h"

struct _estoque {
    int qtd_produtos;
    Produto *produtos;
};

typedef struct _estoque Estoque;

/*
 * Inicializa um produto.
 */
 Estoque estoque_novo (int qtd_produtos, Produto *produtos);
