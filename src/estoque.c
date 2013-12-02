#include "estoque.h"
#include <stdlib.h>
#include <string.h>
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

Estoque* estoque_novo_de_arquivo (FILE *bd) {
    assert (bd != NULL);

    Produto *produto;
    Estoque *novo_estoque;

    novo_estoque = estoque_novo (0, NULL);

    while (!feof (bd)) {
        float preco;
        Data* validade;
        char nome[100], categoria[100], fabricante[100], descricao[100];
        int ano, mes, dia, corredor, prateleira, codigo, quantidade;

        fscanf(bd, "%s\n", nome);
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

int estoque_busca_nome (Estoque* estoque, char *nome_produto, Produto *resultados) {
    int i, k;

    resultados = (Produto *) malloc(ESTOQUE_MAX_SIZE*sizeof(Produto));

    for (i = k = 0; i < estoque->qtd_produtos; i++) {
        if (estoque->produtos[i].nome == nome_produto)
            resultados[k++] = estoque->produtos[i];
    }

    return k;
}

Produto* estoque_lista_categoria (Estoque* estoque, char *categoria_produto) {
    int i;

    for (i = 0; i < estoque->qtd_produtos; i++) {
        if (estoque->produtos[i].categoria == categoria_produto)
            return &estoque->produtos[i];
    }

    return NULL;
}

int estoque_busca_codigo (Estoque *estoque, int codigo, Produto *resultados) {
    int i, k;
    resultados = (Produto *) malloc(ESTOQUE_MAX_SIZE*sizeof(Produto));

    for (i = k = 0; i < estoque->qtd_produtos; i++) {
        if (estoque->produtos[i].codigo == codigo)
            resultados[k++] = estoque->produtos[i];
    }

   return k;
}

int estoque_busca_fabricante (Estoque *estoque, char* fabricante, Produto *resultados) {
    int i, k;

    resultados = (Produto *) malloc(ESTOQUE_MAX_SIZE*sizeof(Produto));

    for (i = k = 0; i < estoque->qtd_produtos; i++) {
        if (estoque->produtos[i].fabricante == fabricante)
            resultados[k++] = estoque->produtos[i];
    }

    return k;
}

void estoque_add_produto (Estoque *estoque, Produto *produto) {
    estoque->produtos[estoque->qtd_produtos] = *produto;
    estoque->qtd_produtos++;
}

void estoque_listar (Estoque *estoque){

    int i;

    printf("+-----------------------------------------------------------------------+\n");
    printf("| Nome          | Categoria      | Validade    |Loc.  | Qtd.  | Preço   |\n");

    for (i = 0; i < estoque->qtd_produtos; i++) {
       produto_listar (&estoque->produtos[i]);
    }

    printf("+-----------------------------------------------------------------------+\n");
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

    int results;
    Produto *produtos = NULL;

    results = estoque_busca_codigo(estoque, codigo, produtos);

    assert (results > 0);

    produtos[0].quantidade += qtd;
    produtos[0].validade = validade;
}


// void estoque_validade (Estoque *estoque, Data *data) {
//     int i;

//     for (i = 0; i < estoque->qtd_produtos; i++){
//         if (estoque->produtos[i].validade <= data)
//             produto_listar(&estoque->produtos[i]);
//     }
// }
