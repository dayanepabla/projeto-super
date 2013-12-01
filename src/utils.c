#include "utils.h"
#include <stdio.h>


void cabecalho (char *tela) {
    printf("\t\t\tSUPERMERCADO\t\t\t\n");

    if (tela)
        printf("%s\n", tela);
}

void limpar_terminal () {
    printf("\033[2J\033[1;1H");
}
