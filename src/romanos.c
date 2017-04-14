#ifndef ROMANOS_C
#define ROMANOS_C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "romanos.h"
// #define TAMANHO_MAX_ROMANO 50

tabela *valores = NULL;
int tamanhoValores = criarTabela(&valores);

int converter(char *romano)
{
	if(valores == NULL)
		exit(4);

	unsigned int i = 0, soma = 0;
	while(romano[i] != '\0' && i < strlen(romano)){
		if(!fimDaString(i+1, romano) && casoEspecial(valores, tamanhoValores, romano[i], romano[i+1])){
			soma += findAlgarismo(romano[i+1], valores, tamanhoValores) - findAlgarismo(romano[i], valores, tamanhoValores);
			i++;
		} else {
			soma += findAlgarismo(romano[i], valores, tamanhoValores);
		}
		i++;
	}

	return soma;
}

int criarTabela(tabela **relacao)
{
	tabela bufferTabela[50];
	int valor, registroBuffer;
	char algarismo;
	
	FILE *arquivoRelacao;
	arquivoRelacao = fopen("valores.txt", "r");
	if(arquivoRelacao == NULL){
		FILE *numeros;
		numeros = fopen("../numeros_romanos.txt", "r");
		if(numeros == NULL)
			exit(2);
		descobrirTabela(numeros, 3000);
		fclose(numeros);
	}
	arquivoRelacao = fopen("valores.txt", "r");
	if(arquivoRelacao == NULL)
		exit(3);

	registroBuffer = 0;
	do{
		fscanf(arquivoRelacao, "%d: %c\n", &valor, &algarismo);
		bufferTabela[registroBuffer].valor = valor;
		bufferTabela[registroBuffer].algarismo = algarismo;
		registroBuffer++;
	}while(!feof(arquivoRelacao));
	registroBuffer++;

	*relacao = (tabela*)malloc(sizeof(tabela)*registroBuffer);
	int i;
	for(i = 0; i < registroBuffer; i++){
		(*relacao)[i].valor = bufferTabela[i].valor;
		(*relacao)[i].algarismo = bufferTabela[i].algarismo;
	}
	fclose(arquivoRelacao);
	return registroBuffer;
}

 void descobrirTabela(FILE *fp, int maiorNum)
{
	int indiceLinha, valor;
	char recebido[50];
	FILE *arquivoRelacao;
	arquivoRelacao = fopen("valores.txt", "w");
	if(arquivoRelacao == NULL)
		exit(1);

	for(indiceLinha = 0; indiceLinha < maiorNum; indiceLinha++){
		fscanf(fp, "%d: %s", &valor, recebido);
		if(strlen(recebido) == 1)
			fprintf(arquivoRelacao, "%d: %s\n", valor, recebido);
	}
	fclose(arquivoRelacao);
}

int fimDaString(int posicao, char *romano)
{
	return (unsigned int)posicao >= strlen(romano);
}

int casoEspecial(tabela *relacao, int tamanhoRelacao, char atual, char proximo)
{
	int valorAtual = findAlgarismo(atual, relacao, tamanhoRelacao);
	int valorProx =  findAlgarismo(proximo, relacao, tamanhoRelacao);
	return valorAtual < valorProx;
}

int findAlgarismo(char algarismo, tabela *relacao, int tamanho)
{
	int i = 0;
	while(i < tamanho && relacao[i].algarismo != algarismo)
		i++;
	if(relacao[i].algarismo == algarismo)
		return relacao[i].valor;
	return -1;
}

#endif