#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <signal.h>

#include "estoque.h"
#include "cliente.h"
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

/*
 * Exibe a tela de cliente.
 */
void cliente ();

/*
 * Exibe a tela funcionário.
 */
void funcionario ();


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
            funcionario();
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
                // busca();
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
