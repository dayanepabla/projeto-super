#include <stdio.h>
#include "estoque.h"

int main () {
    FILE *bd;
    Produto *prod, *prod1;
    Data *data;
    Estoque *estoque;

    estoque = estoque_novo (0, NULL);
    bd = fopen ("bd.txt", "w");
    data = data_novo (2013, 12, 1);
    prod = produto_novo ("Mouse", "Eletronico", 1300, 34.20, 5, "Microsoft", "Mouse sem fio",
                          data, 2, 5);
    prod1 = produto_novo ("Teclado", "Eletronico", 1301, 84.20, 400, "Positivo", "Teclado qualquer coisa",
                           data, 2, 5);
    estoque_add_produto (estoque, prod);
    estoque_add_produto (estoque, prod1);
    estoque_salvar (estoque, bd);
    estoque_baixo (estoque, 10);

    return 0;
}
