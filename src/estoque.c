#include "estoque.h"
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "utils.h"


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

Estoque* estoque_novo_de_arquivo (FILE *bd) {
    assert (bd != NULL);

    size_t len = 0;
    char *header;
    Produto *produto;
    Estoque *novo_estoque;

    novo_estoque = estoque_novo (0, NULL);

    while (getline(&header,&len, bd) != -1 && !feof(bd)) {
        float preco;
        Data* validade;
        char nome[100], categoria[100], fabricante[100], descricao[100];
        int ano, mes, dia, corredor, prateleira, codigo, quantidade;

        if (strlen (header) == 0 || strcmp(header, "[produto]") == 0)
            continue;

        fscanf(bd, "nome: %s\n", nome);
        fscanf(bd, "categoria: %s\n", categoria);
        fscanf(bd, "codigo: %i\n", &codigo);
        fscanf(bd, "preco: %f\n", &preco);
        fscanf(bd, "quantidade: %i\n", &quantidade);
        fscanf(bd, "fabricante: %s\n", fabricante);
        fscanf(bd, "descricao: %s\n", descricao);
        fscanf(bd, "validade: %i/%i/%i\n", &ano, &mes, &dia);
        fscanf(bd, "corredor: %i\n", &corredor);
        fscanf(bd, "prateleira: %i\n\n", &prateleira);

        validade = data_novo (ano, mes, dia);
        produto = produto_novo(nome, categoria, codigo, preco, quantidade,
                    fabricante, descricao, validade, corredor, prateleira);

        estoque_add_produto (novo_estoque, produto);
    }

    return novo_estoque;
}

int estoque_cheio (Estoque *estoque) {
    return estoque->qtd_produtos == ESTOQUE_MAX_SIZE;
}

Produto* estoque_busca_nome (Estoque* estoque, char *nome_produto) {
    int i;

    for (i = 0; i < estoque->qtd_produtos; i++) {
        if (strcmp(estoque->produtos[i].nome, nome_produto) == 0)
            return &estoque->produtos[i];
    }

    return NULL;
}

void estoque_lista_categoria (Estoque* estoque, char *categoria_produto) {
    int i;

    tabela_produto ();

    for (i = 0; i < estoque->qtd_produtos; i++) {
        if (strcmp(estoque->produtos[i].categoria, categoria_produto) == 0)
            produto_listar (&estoque->produtos[i]);
    }

    hr ();
}

Produto* estoque_busca_codigo (Estoque *estoque, int codigo) {
    int i;

    for (i = 0; i < estoque->qtd_produtos; i++) {
        if (estoque->produtos[i].codigo == codigo)
            return &estoque->produtos[i];
    }

   return NULL;
}

void estoque_busca_fabricante (Estoque *estoque, char* fabricante) {
    int i, k;

    tabela_produto ();

    for (i = k = 0; i < estoque->qtd_produtos; i++) {
        if (strcmp(estoque->produtos[i].fabricante, fabricante) == 0)
            produto_listar (&estoque->produtos[i]);
    }

    hr ();
}

void estoque_add_produto (Estoque *estoque, Produto *produto) {
    estoque->produtos[estoque->qtd_produtos] = *produto;
    estoque->qtd_produtos++;
}

void estoque_rm_produto (Estoque *estoque, Produto *produto) {
    int i;

    assert (produto != NULL);

    for (i = 0; i < estoque->qtd_produtos; ++i) {
        if (estoque->produtos[i].codigo == produto->codigo) {
            estoque->qtd_produtos--;
            pswap (&estoque->produtos[i], produto);

            return;
        }
    }
}

void estoque_listar (Estoque *estoque){

    int i;

    tabela_produto ();

    for (i = 0; i < estoque->qtd_produtos; i++) {
       produto_listar (&estoque->produtos[i]);
    }

    hr ();
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

int estoque_baixo (Estoque *estoque, int qtd) {

    int i, k;

    for (i = k = 0; i < estoque->qtd_produtos; i++){
        if (estoque->produtos[i].quantidade <= qtd)
            k++;
    }

    return k;
}

void estoque_repor (Estoque *estoque, int codigo, Data *validade, int qtd) {
    Produto *produto = NULL;

    produto = estoque_busca_codigo (estoque, codigo);

    assert (produto != NULL);

    produto[0].quantidade += qtd;
    produto[0].validade = validade;
}


int estoque_validade (Estoque *estoque, Data *data) {
    int i, k;

    for (i = k = 0; i < estoque->qtd_produtos - 1; i++){
        int mes, ano;

        mes = estoque->produtos[i].validade->mes;
        ano = estoque->produtos[i].validade->ano;

        if (ano <= data->ano) {
            if (mes >= data->mes + 1) {
                k++;
            }
        }
    }

    return k;
}
