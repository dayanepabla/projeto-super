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
 * Limpa o terminal, ou seja, apaga todos os caracteres existentes
 * e move o cursor para a primeira coluna da primeira linha.
 */
void limpar_terminal ();

/*
 * Requisita informações de produto ao usuário e cria um novo produto.
 */
Produto *ler_produto ();

#endif
