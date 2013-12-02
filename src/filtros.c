#include "filtros.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "utils.h"

void filtros_nome (Produto *produtos, int qtd) {
    int i, j;

    for (j = 0; j < qtd - 1; ++j) {
        for (i = 0; i < qtd - 1; ++i) {
            if (strcmp (produtos[i].nome, produtos[i + 1].nome) > 0)
                pswap (&produtos[i], &produtos[i + 1]);
        }
    }
}

void filtros_menor_preco (Produto *produtos, int qtd) {
    int i, j;

    for (j = 0; j < qtd -1; ++j) {
        for (i = 0; i < qtd - 1; ++i) {
            if (produtos[i].preco > produtos[i + 1].preco)
                pswap (&produtos[i], &produtos[i + 1]);
        }
    }
}
