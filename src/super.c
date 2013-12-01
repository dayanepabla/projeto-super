#include <stdio.h>
#include <assert.h>

#include "estoque.h"
#include "produto.h"
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

void cliente () {
    busca ();
}

void funcionario () {
    int op;
    Produto *produto;

    limpar_terminal ();
    cabecalho ("Opções de funcionário");

    printf("1. Buscar produto\n");
    printf("2. Repor estoque\n");
    printf("3. Cadastrar produtos novos\n");
    printf("4. Sair\n");

    scanf ("%i", &op);

    while (op != 5) {
        switch (op) {
            case 1:
                busca();
                break;
            case 2:
                break;
            case 3:
                limpar_terminal ();
                cabecalho ("Opções de funcionário > Cadastro de produto");

                // Lê as informações do produto do teclado
                // e adiciona ao estoque.
                produto = ler_produto();
                estoque_add_produto(estoque, produto);

                break;
            case 4:
                break;
            default:
                printf("Opção inválida!\n");
        }

        scanf ("%i", &op);
    }
}
