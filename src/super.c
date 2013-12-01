#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <signal.h>

#include "estoque.h"
#include "cliente.h"
#include "funcionario.h"
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
 * Encerra o programa.
 */
void sair (int signum);


int main () {
    int opcao;

    init();
    signal (SIGINT, sair);

    do {
        limpar_terminal();
        cabecalho("Bem vindo!");

        printf("[1] Cliente\n");
        printf("[2] Funcionário\n");

        rodape ();

        scanf ("%i", &opcao);

        if (opcao == 1) {
            // Lê a escolha do usuário.
            opcao = cliente_menu ();

        } else if (opcao == 2) {
            // Lê a escolha do usuário.
            opcao = funcionario_menu ();
        }

    } while (opcao != EOF);


    return 0;
}

void init () {
    bd = fopen(BD_NAME, "a");

    // Verifica se o arquivo abriu com sucesso.
    assert(bd != NULL);

    estoque = estoque_novo(0, NULL);
}

void sair (int signum) {
    limpar_terminal ();
    cabecalho ("Encerrando aplicação");

    printf("organizando o estoque...                            OK!\n");
    printf("varrendo os corredores...                           OK!\n");
    printf("contabilizando lucros...                            OK!\n");
    printf("salvando produtos...                                OK!\n");
    printf("saindo...                                           obrigado e até logo! :)\n");

    exit (EXIT_SUCCESS);
}

