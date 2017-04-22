#ifndef MP_TRAB2_INCLUDE_CONVERSOR_ROMANOS_H_
#define MP_TRAB2_INCLUDE_CONVERSOR_ROMANOS_H_

#include <stdio.h>

/**
  Uma estrutura para guardar as relações de valor entre
  algarismos romanos e arábicos. Ele é utilizado em vetores
  dessa struct considerando que a tabela só precisa ser
  criada uma vez e nunca modificada. Ela foi feita para
  relacionar V com seu valor de 5, I com seu valor de 1
  e etc.
*/
typedef struct TpTabela{
  int valor;        /**<Valor correspondente da notação arábica do algarismo romano.*/
  char algarismo;     /**<Algarismo romano.*/
}Tabela;

int Converter(char *romano);  /**<Função que converte um número romano em arábico.*/
int CriarTabela(Tabela **relacao);  /**<Gera a tabela de relacionamentos romano arábico.*/
void DescobrirTabela(FILE *fp, int maior_num);  /**<Gera um .txt com as relações diretas de romano e arábico.*/
int FimDaString(int posicao, char *romano);  /**<Checa se é índice é fim da string passada.*/
int CasoEspecial(Tabela* relacao, int tamanho_relacao, char atual, char proximo);  /**<Checa se os dois algarismos consecutivos fazem um caso especial.*/
int FindAlgarismo(char algarismo, Tabela *relacao, int tamanho_relacao);  /**<Acha a existencia do algarismo na tabela e retorna o valor correspondente.*/
int FindIndice(char algarismo, Tabela *relacao, int tamanho_relacao);  /**<Retorna o indice da posição do algarismo procurado.*/
int ValidarNumeroRomano(char *romano);  /**<Confirma a validade do número romano.*/

#endif