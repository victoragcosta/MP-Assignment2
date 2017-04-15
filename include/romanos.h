#ifndef MP_TRAB2_ROMANOS_H_
#define MP_TRAB2_ROMANOS_H_

#include <stdio.h>

/**
	Uma estrutura para guardar as relações de valor entre
	algarismos romanos e arábicos. Ele é utilizado em vetores
	dessa struct considerando que a tabela só precisa ser
	criada uma vez e nunca modificada. Ela foi feita para
	relacionar V com seu valor de 5, I com seu valor de 1
	e etc.
*/
typedef struct tpTabela{
	int valor;				/**<Valor do algarismo romano.*/
	char algarismo;			/**<Algarismo romano.*/
}tabela;

int converter(char *romano);														/**<Função que converte um número romano em arábico.*/
int criarTabela(tabela **relacao);													/**<Gera a tabela de relacionamentos romano arábico.*/
void descobrirTabela(FILE *fp, int maiorNum);										/**<Gera um .txt com as relações diretas de romano e arábico.*/
int fimDaString(int posicao, char *romano);											/**<Checa se é índice é fim da string passada.*/
int casoEspecial(tabela* relacao, int tamanhoRelacao, char atual, char proximo);	/**<Checa se os dois algarismos consecutivos fazem um caso especial.*/
int findAlgarismo(char algarismo, tabela *relacao, int tamanho);					/**<Acha a existencia do algarismo na tabela e retorna o valor correspondente.*/

#endif