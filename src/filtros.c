#include "filtros.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "utils.h"

Produto* filtros_nome (Produto *produtos, int qtd) {
    int i, j;
    Produto *produtos_cp;

    produtos_cp = (Produto *) malloc(sizeof(Produto)*qtd);

    memcpy (produtos_cp, produtos, sizeof(Produto)*qtd);

    for (j = 0; j < qtd; ++j) {
        for (i = 0; i < qtd; ++i) {
            if (strcmp (produtos[i].nome, produtos[i + 1].nome) > 0)
                pswap (&produtos[i], &produtos[i + 1]);
        }
    }

    return produtos_cp;
}
