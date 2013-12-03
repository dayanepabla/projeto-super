#ifndef UTILS_H
#define UTILS_H

#include "produto.h"

/*
 * Exibe um cabeçalho devidamente formatado. Aceita uma string
 * representando o nome da tela atual.
 */
void cabecalho (char *tela);

/*
 * Exibe um rodapé informativo.
 */
void rodape ();

/*
 * Aguarda que o usuário c antes de continuar.
 */
void aguarde ();

/*
 * Imprime uma linha pontilhada.
 */
void hr ();

/*
 * Imprime o cabeçalho da tabela de produtos.
 */
void tabela_produto ();

/*
 * Limpa o terminal, ou seja, apaga todos os caracteres existentes
 * e move o cursor para a primeira coluna da primeira linha.
 */
void limpar_terminal ();

/*
 * Requisita informações de produto ao usuário e cria um novo produto.
 */
Produto *ler_produto ();

/*
 * Imprime uma lista de produtos.
 */
// void listar_produtos (Produto *produtos);

/*
 * Swap entre ponteiros do tipo Produto.
 */
void pswap (Produto *prod1, Produto *prod2);

/*
 * Lista todos os produtos apontados por produtos.
 */
void listar_varios_produtos (Produto *produtos, int qtd_produtos);

#endif
