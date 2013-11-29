#include "produto.h"

#define ESTOQUE_MAX_SIZE 100

struct _estoque {
    int qtd_produtos;
    Produto *produtos;
};

typedef struct _estoque Estoque;

/*
 * Inicializa um produto.
 * Se produtos for NULL inicializa uma lista de tamanho ESTOQUE_MAX_SIZE.
 */
Estoque* estoque_novo (int qtd_produtos, Produto *produtos);

/*
 * Retorna TRUE caso o estoque esteja cheio e FALSE caso contrário.
 */
int estoque_cheio (Estoque *estoque);

/*
 * Busca um produto por nome e retorna um ponteiro para o produto.
 */
Produto* estoque_busca_nome (Estoque* estoque, char *nome_produto);

/*
 * Busca um produto no estoque, por nome do fabricante.
 */
Produto* estoque_busca_fabricante (Estoque *estoque, char* fabricante);

/*
 * Adiciona um novo produto ao estoque.
 */
void estoque_add_produto (Estoque *estoque, Produto *produto);

/*
 * Salva produtos do estoque no banco de dados.
 */
void estoque_listar (Estoque *estoque);

/*
 * Salva o estoque no banco de dados.
 *
 * Retorna 1 se estiver tudo certo, -1 caso contrário.
 */
int estoque_salvar (Estoque *estoque, FILE *bd);

/*
 * Lista produtos com estoque baixo.
 * qtd define a quantidade máxima de produtos em estoque.
 */
void estoque_baixo (Estoque *estoque, int qtd);

/*
 * Lista produtos com a data de validade próxima.
 */
// void estoque_validade (Estoque *estoque, Data *data);
