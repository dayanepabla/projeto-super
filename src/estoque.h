#ifndef ESTOQUE_H
#define ESTOQUE_H

#include "produto.h"

#define ESTOQUE_MAX_SIZE 100

struct _estoque {
    int qtd_produtos;
    Produto *produtos;
};

typedef struct _estoque Estoque;

/*
 * Inicializa um objeto Estoque.
 * Se produtos for NULL inicializa uma lista de tamanho ESTOQUE_MAX_SIZE.
 */
Estoque* estoque_novo (int qtd_produtos, Produto *produtos);

/*
 * Inicializa um objeto Estoque, carregando os produtos do arquivo especificado
 * por bd.
 */
Estoque* estoque_novo_de_arquivo (FILE *bd);

/*
 * Retorna TRUE caso o estoque esteja cheio e FALSE caso contrário.
 */
int estoque_cheio (Estoque *estoque);

/*
 * Busca um produto por nome.
 */
Produto* estoque_busca_nome (Estoque* estoque, char *nome_produto);

/*
 * Lista produtos por categoria.
 */
void estoque_lista_categoria (Estoque* estoque, char *categoria_produto);

/*
 * Busca um produto no estoque pelo código.
 *
 * Obs.: Assume que o campo código é único.
 */
Produto* estoque_busca_codigo (Estoque *estoque, int codigo);

/*
 * Busca um produto no estoque, por nome do fabricante.
 */
void estoque_busca_fabricante (Estoque *estoque, char* fabricante);

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
int estoque_baixo (Estoque *estoque, int qtd);

/*
 * Repõe um produto no estoque.
 */
void estoque_repor (Estoque *estoque, int codigo, Data *validade, int qtd);

/*
 * Lista produtos com a data de validade próxima.
 */
void estoque_validade (Estoque *estoque, Data *data);

#endif
