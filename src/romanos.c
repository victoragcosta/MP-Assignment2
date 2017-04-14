#ifndef ROMANOS_C
#define ROMANOS_C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "romanos.h"

int converter(char *romano)
{
	tabela valores[4];
	valores[0].algarismo = 'I';
	valores[0].valor = 1;

	valores[1].algarismo = 'V';
	valores[1].valor = 5;

	valores[2].algarismo = 'X';
	valores[2].valor = 10;

	valores[3].algarismo = '\0';
	valores[3].valor = -1;

	unsigned int i = 0, soma = 0;
	while(romano[i] != '\0' && i < strlen(romano)){
		if(!fimDaString(i+1, romano) && casoEspecial(valores, 4, romano[i], romano[i+1])){
			soma += findAlgarismo(romano[i+1], valores, 4) - findAlgarismo(romano[i], valores, 4);
			i++;
		} else {
			soma += findAlgarismo(romano[i], valores, 4);
		}
		i++;
	}

	return soma;
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