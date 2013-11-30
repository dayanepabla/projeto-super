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

/*
 * Indica se o carrinho está cheio ou não.
 *
 * Retorna TRUE caso a quantidade de produtos no carrinho seja igual a
 * CARRINHO_MAX_SIZE e FALSE caso contrário.
 */

int carrinho_cheio (Carrinho *carrinho);

/*
 * Adiciona um produto ao carrinho.
 */
void carrinho_add_produto (Carrinho *carrinho, Produto *prod);

/*
 * Lista os produtos do carrinho de compras.
 */
void carrinho_listar (Carrinho *carrinho);

/*
 * Retorna o subtotal dos produtos que estão no carrinho de compras.
 */
float carrinho_subtotal (Carrinho *carrinho);
