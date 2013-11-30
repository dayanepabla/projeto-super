#include <stdio.h>
#include "carrinho.h"
//#include "estoque.h"
//#include "produto.h"

int main () {

    Data *data;
    Produto *prod;
    EStoque *estoque;

    data = data_novo (2013, 12, 1);
    estoque = estoque_novo (0, NULL);
    prod = produto_novo ("Mouse", "Eletronico", 1300, 34.20, 500, "Microsoft", "Mouse sem fio",
                         data, 2, 5);

    estoque_add_produto (estoque, prod);

    printf("%d\n", estoque_cheio (estoque));

    produto_listar (estoque_busca_fabricante (estoque, "Micr osoft"));

    return 0;
}
