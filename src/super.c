#include <stdio.h>
#include <assert.h>
#include "estoque.h"

#define BD_NAME "bd.txt"

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
    FILE *bd;
    bd = fopen(BD_NAME, "a");

    // Verifica se o arquivo abriu com sucesso.
    assert(bd != NULL);
}

void inicial () {

    int op;

    printf("\t\t\tSUPERMERCADO\t\t\t\n");
    printf("1. Cliente\n2. Funcionário\n3. Sair\n");
    scanf ("%i", &op);
    if (op == 1){
        cliente();
    } if (op == 2) {
        funcionario();
    }
}

void busca () {
    int op;

    printf("Buscar produto\n");
    printf("1. Buscar por nome\n");
    printf("2. Buscar por fabricante\n");
    printf("3. Buscar por categoria\n");
    printf("4. Sair\n");
    scanf ("%i", &op);
}

void cliente (){
    busca ();
}

void funcionario () {
    int op;

    printf("1. Buscar produto\n2. Repor estoque\n3. Cadastrar produtos novos\n");
    scanf ("%i", &op);
    switch (op) {
        case 1:
            busca();
            break;
        case 2:
        case 3:
        default:
            printf("Opção inválida!\n");
    }
}


    return 0;
}
