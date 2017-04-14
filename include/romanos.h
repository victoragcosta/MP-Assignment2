#ifndef ROMANOS_H
#define ROMANOS_H

typedef struct tpTabela{
	int valor;
	char algarismo;
}tabela;

int converter(char *romano);
int criarTabela(tabela **relacao);
void descobrirTabela(FILE *fp, int maiorNum);
int fimDaString(int posicao, char *romano);
int casoEspecial(tabela* relacao, int tamanhoRelacao, char atual, char proximo);
int findAlgarismo(char algarismo, tabela *relacao, int tamanho);

#endif