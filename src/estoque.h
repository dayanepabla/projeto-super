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

 /*
  * Busca um produto por nome e retorna um ponteiro para o produto.
  */
Produto* estoque_busca_nome (Estoque estoque, char *nome_produto);
