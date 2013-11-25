#include <stdio.h>
// #include "produto.h"
#include "estoque.h"
// #include "data.h"

//Função cadastrar
//Função Busca
//Abri, alterar e salvar arquivo
//Ordenar datas de validades
//Fução alerta
	//Data de validade
	//Estoque baixo
//Função carrinho

int main () {

    // FILE *bd;
    Produto prod, prod1;
    Data mes;
    Estoque nov_est;
    // bd = fopen ("bd.txt", "w");

    mes = data_novo (2013, 12, 1);

    prod = produto_novo ("Mouse", "Eletronico", 1300, 34.20, 500, "Microsoft", "Mouse sem fio",
                          mes, 2, 5);
    prod1 = produto_novo ("Teclado", "Eletronico", 1300, 34.20, 500, "Microsoft", "Mouse sem fio",
                          mes, 2, 5);

    Produto produtos[] = { prod, prod1 };

    nov_est = estoque_novo (2, produtos);

    Produto* result = estoque_busca_nome (nov_est, "Teclado");

    if (result != NULL) {
        printf("%s\n", result->nome);
    }

        /* code */


    // printf("%s, %s, %i, %f, %i, %s, %s, %i/%i/%i, %i, %i\n", prod.nome, prod.categoria, prod.codigo, prod.preco,
    //                                                          prod.quantidade, prod.fabricante, prod.descricao,
    //                                                          prod.validade.ano, prod.validade.mes,
    //                                                          prod.validade.dia, prod.corredor, prod.prateleira);                                                      ;
    // // printf("%i/%i/%i\n", mes.ano, mes.mes, mes.dia);
    // produto_salvar(prod, bd);
    printf ("Rodando\n");

    return 0;
}

/*int main () {
    int op, op_f, op_c, cad;

    printf("\n\n\t\t\t\t SUPERMERCADO \n\n\n");
    printf("MENU\n\n1 - Funcionário\n2 - Cliente\n3 - Sair\n\nOpção: ");
    scanf("%d",&op);
    switch ( op ) {
        case 1:
        {
        	printf("MENU\n\n1 - Buscar produto\n2 - Repor estoque\n3 - Cadastrar novos produtos\n4 - Sair\n\nOpção: ");
        	scanf ("%d", &op_f);

                if (op_f == 1 ){
                	//Função Busca
                }
                if (op_f == 2){
                    //Produto
                    //Add ao banco de dados
                }
                if (op_f == 3) {
                	printf("Cadastrar novo produto por:\n1 - Teclado\n2 - Arquivo\n");
                	scanf ("%d",&cad);
                	if (cad == 1){
                		//Função Produto
                		//Add ao banco de dados
                	} else {
                		//Carregar arquivo
                		//Add ao banco de dados
                	}
                }
                if (op_f == 4) {
                	break;
                }
        }
        case 2:
        {
            printf("MENU\n\n1 - Buscar produto\n2 - Carrinho de compras\n3 - Sair\n\nOpção: ");
            scanf ("%d", &op_c);
            	if (op_c == 1) {
            		//Função Busca
            	}
            	if (op_c == 2) {
            		//Função carrinho
            	} else {
            		break;
            	}
        }
        case 3:
        {
            break;
        }

    return 0;
}*/

