#include "estoque.h"
#include <stdlib.h>
#include <assert.h>


Estoque* estoque_novo (int qtd_produtos, Produto *produtos) {
    Estoque *novo_estoque;

    if (produtos == NULL) {
        produtos = (Produto *) malloc(ESTOQUE_MAX_SIZE*sizeof(Produto));
    }

    novo_estoque = (Estoque *) malloc(sizeof(Estoque));
    novo_estoque->qtd_produtos = qtd_produtos;
    novo_estoque->produtos = produtos;

    return novo_estoque;
}

int estoque_cheio (Estoque *estoque) {
    return estoque->qtd_produtos == ESTOQUE_MAX_SIZE;
}

Produto* estoque_busca_nome (Estoque* estoque, char *nome_produto) {
    int i;

    for (i = 0; i < estoque->qtd_produtos; i++) {
        if (estoque->produtos[i].nome == nome_produto)
            return &estoque->produtos[i];
    }

    return NULL;
}

Produto* estoque_busca_codigo (Estoque *estoque, int codigo) {
    int i;

    for (i = 0; i < estoque->qtd_produtos; i++) {
        if (estoque->produtos[i].codigo == codigo)
            return &estoque->produtos[i];
    }

    return NULL;
}

Produto* estoque_busca_fabricante (Estoque *estoque, char* fabricante) {
    int i;

    for (i = 0; i < estoque->qtd_produtos; i++) {
        if (estoque->produtos[i].fabricante == fabricante) {
            return &estoque->produtos[i];
        }
    }

    return NULL;
}

void estoque_add_produto (Estoque *estoque, Produto *produto) {
    estoque->produtos[estoque->qtd_produtos] = *produto;
    estoque->qtd_produtos++;
}

void estoque_listar (Estoque *estoque){

    int i;

    for (i = 0; i < estoque->qtd_produtos; i++) {
       produto_listar (&estoque->produtos[i]);
    }
}

int estoque_salvar (Estoque *estoque, FILE *bd) {
    assert (bd != NULL);

    int i;

    for (i = 0; i < estoque->qtd_produtos; i++){
        if (produto_salvar (&estoque->produtos[i], bd) == -1)
            return -1;
    }

    return 1;
}

void estoque_baixo (Estoque *estoque, int qtd) {

    int i;

    for (i = 0; i < estoque->qtd_produtos; i++){
        if (estoque->produtos[i].quantidade <= qtd)
            produto_listar(&estoque->produtos[i]);
    }
}

void estoque_repor (Estoque *estoque, int codigo, Data *validade, int qtd) {
    Produto *prod = estoque_busca_codigo(estoque, codigo);

    assert (prod != NULL);

    prod->quantidade += qtd;
    prod->validade = validade;
}


// void estoque_validade (Estoque *estoque, Data *data) {
//     int i;

//     for (i = 0; i < estoque->qtd_produtos; i++){
//         if (estoque->produtos[i].validade <= data)
//             produto_listar(&estoque->produtos[i]);
//     }
// }
