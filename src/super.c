#include <stdio.h>
#include "carrinho.h"
//#include "estoque.h"
//#include "produto.h"

int main () {

    Data *data;
    Produto *prod;
    Carrinho *carrinho;

    data = data_novo (2013, 12, 1);
    carrinho = carrinho_novo (0, NULL);
    prod = produto_novo ("Mouse", "Eletronico", 1300, 34.20, 500, "Microsoft", "Mouse sem fio",
                         data, 2, 5);

    carrinho_add_produto (carrinho, prod);

    printf("%d\n", carrinho_cheio (carrinho));

    carrinho_listar (carrinho);

    return 0;
}
