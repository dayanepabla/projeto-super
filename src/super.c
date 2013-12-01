#include <stdio.h>
#include <assert.h>

#include "estoque.h"
#include "utils.h"

#define BD_NAME "bd.txt"


FILE *bd;
Estoque *estoque;


/*
 * Inicialização do sistema.
 */
void init ();

/*
 * Menu inicial.
 */
void inicial ();

/*
 * Encerra o programa.
 */
void sair ();

/*
 * Exibe a tela de cliente.
 */
void cliente ();

/*
 * Exibe a tela funcionário.
 */
void funcionario ();

/*
 * Exibe a tela de busca.
 */
void busca ();


int main () {
    init();
    inicial ();
    sair ();

    return 0;
}

void init () {
    bd = fopen(BD_NAME, "a");

    // Verifica se o arquivo abriu com sucesso.
    assert(bd != NULL);

    estoque = estoque_novo(0, NULL);
}

void sair () {
    limpar_terminal ();
    printf("Encerrando aplicação... salvando produtos... saindo... até logo!\n");
}

void inicial () {

    int op;

    limpar_terminal();

    cabecalho("Bem vindo!");
    printf("1. Cliente\n");
    printf("2. Funcionário\n");
    printf("3. Sair\n");
    scanf ("%i", &op);

    if (op == 1){
        cliente();
    } if (op == 2) {
        funcionario();
    }
}

void busca () {
    int op;

    limpar_terminal ();

    cabecalho("Buscar produto");
    printf("1. Buscar por nome\n");
    printf("2. Buscar por fabricante\n");
    printf("3. Buscar por categoria\n");
    printf("4. Sair\n");
    scanf ("%i", &op);
}

void cliente (){
    busca ();
}

void funcionario (){
    int op;
    char nome[50], categoria[50], fabricante[50], descricao[50];
    int codigo, quantidade, corredor, prateleira, dia, mes, ano;
    float preco;
    Produto* prod;
    Data* validade;

    limpar_terminal ();

    printf("1. Buscar produto\n");
    printf("2. Repor estoque\n");
    printf("3. Cadastrar produtos novos\n");
    printf("4. Sair\n");
    scanf ("%i", &op);
    switch (op) {
        case 1:
            busca();
            break;
        case 2:
        case 3:

            printf("Nome: ");
            scanf("%s", nome);

            printf("Categoria: ");
            scanf("%s", categoria);

            printf("Código: ");
            scanf("%i", &codigo);

            printf("Preço: ");
            scanf("%f", &preco);

            printf("Quantidade: ");
            scanf("%i", &quantidade);

            printf("Fabricante: ");
            scanf("%s", fabricante);

            printf("Descricao: ");
            scanf("%s", descricao);

            printf("Validade: ");
            scanf("%i %i %i", &ano, &mes, &dia);

            printf("Corredor: \n");
            scanf("%i", &corredor);

            printf("Prateleira: ");
            scanf("%i", &prateleira);

            validade = data_novo(ano, mes, dia);
            prod = produto_novo(nome, categoria, codigo, preco, quantidade,
                                fabricante, descricao, validade, corredor, prateleira);
            estoque_add_produto(estoque, prod);

            break;
        case 4:
        default:
            printf("Opção inválida!\n");
    }

}
