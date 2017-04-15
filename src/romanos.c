#ifndef ROMANOS_C
#define ROMANOS_C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "romanos.h"

tabela *valores = NULL;//decidi colocar como global para ler menos o arquivo
int tamanhoValores = criarTabela(&valores);//guarda-se o tamanho

/** Converte os algarismos de romano para arábico.
	\param romano ponteiro para char (atuando como string) contendo o número romano que se deseja converter.
	\return o valor inteiro do número romano. Retorna -1 se não for valor romano válido.
 */
int converter(char *romano)
{
	if(valores == NULL)//se não tiver a tabela, a função não tem como funcionar
		exit(4);//fecha o programa

	unsigned int i = 0, soma = 0;
	while(i < strlen(romano) && romano[i] != '\0'){//itera até o fim da string do número romano
		//Testa se está no fim antes (problemas de segmentation fault) e depois se ele se enquadra num caso de subtração
		if(!fimDaString(i+1, romano) && casoEspecial(valores, tamanhoValores, romano[i], romano[i+1])){
			//caso se enquadre no caso, ele soma o valor do próximo(maior) menos o atual(menor)
			soma += findAlgarismo(romano[i+1], valores, tamanhoValores) - findAlgarismo(romano[i], valores, tamanhoValores);
			i++;//pula 1 a mais por já ter processado duas letras de uma vez
		} else {
			//se for caso normal, apenas soma o valor correspondente
			soma += findAlgarismo(romano[i], valores, tamanhoValores);
		}
		i++;//itera para o proximo algarismo
	}

	return soma;//o valor do romano é a soma de todos os valores
}

/**	Aloca em memória uma lista com as relações entre todos os algarismos romanos com arábicos.
	\param relacao o endereço de memória de um ponteiro de tabela.
	\return o tamanho da tabela criada.
*/
int criarTabela(tabela **relacao)
{
	tabela bufferTabela[50];//para criar a tabela
	int valor, registroBuffer;
	char algarismo;
	
	/* Aqui tentamos abrir a tabela de um .txt, caso não exista
	 * ela chama uma função que gera essa tabela
	 */
	FILE *arquivoRelacao;
	arquivoRelacao = fopen("../valores.txt", "r");
	if(arquivoRelacao == NULL){//se não houver arquivo
		FILE *numeros;
		numeros = fopen("../numeros_romanos.txt", "r");//a partir de todos os romanos até 3999
		if(numeros == NULL)
			exit(2);
		descobrirTabela(numeros, 3000);//cria a tabela
		fclose(numeros);
	}
	arquivoRelacao = fopen("../valores.txt", "r");//tenta abrir de novo
	if(arquivoRelacao == NULL)
		exit(3);

	registroBuffer = 0;//itera pelo bufferTabela
	do{
		fscanf(arquivoRelacao, "%4d: %1c\n", &valor, &algarismo);//le do arquivo valor e algarismo
		bufferTabela[registroBuffer].valor = valor;//associa valor
		bufferTabela[registroBuffer].algarismo = algarismo;//associa algarismo
		registroBuffer++;//próximo registro
	}while(!feof(arquivoRelacao));//até o fim do arquivo
	registroBuffer++;//pra se equivaler ao tamanho

	*relacao = (tabela*)malloc(sizeof(tabela)*registroBuffer);//gera o espaço para retorno por referencia
	int i;
	for(i = 0; i < registroBuffer; i++){//copia todos os valores para o retorno
		(*relacao)[i].valor = bufferTabela[i].valor;
		(*relacao)[i].algarismo = bufferTabela[i].algarismo;
	}
	fclose(arquivoRelacao);
	return registroBuffer; //retorna tamanho
}

/**
	Essa função gera um arquivo .txt relacionando o algarismo romano
	com o valor dele. Ele faz isso lendo a partir de uma tabela com
	3999 números romanos e achando os que contém apenas 1 letra, tendo
	assim o valor verdadeiro do algarismo romano.
	\param fp Ponteiro para arquivo contendo o arquivo aberto com 3999 números romanos.
	\param maiorNum Valor inteiro dizendo qual o maior número a ser olhado na lista.
	\return Nada.
*/
 void descobrirTabela(FILE *fp, int maiorNum)
{
	int indiceLinha, valor;
	char recebido[50];

	/* abre um arquivo para escrever a relação de algarismos e valores */
	FILE *arquivoRelacao;
	arquivoRelacao = fopen("../valores.txt", "w");
	if(arquivoRelacao == NULL)
		exit(1);

	/* Copia para o arquivo todos os números romanos que contém apenas um caracter,
	 * que representa uma relação direta entre valor e algarismo
	 */
	for(indiceLinha = 0; indiceLinha < maiorNum; indiceLinha++){
		fscanf(fp, "%4d: %49s", &valor, recebido);//pega valor e algarismo
		if(strlen(recebido) == 1)//checa se é apenas 1 caracter
			fprintf(arquivoRelacao, "%d: %s\n", valor, recebido);//copia
	}

	fclose(arquivoRelacao);
}

/**
	Testa se o índice aponta para o fim da string.
	\param posicao Um valor inteiro representando o índice da string.
	\param romano Ponteiro para char atuando como uma string.
	\return Um inteiro representando verdadeiro ou falso.
*/
int fimDaString(int posicao, char *romano){return (unsigned int)posicao >= strlen(romano);}

/**
	Testa se o caracter atual e o próximo formam
	um caso de subtração dos algarismos romanos.
	Ele checa se o proximo tem valor maior que o anterior.
	\param relacao A tabela relacionando algarismos romanos com os valores deles.
	\param tamanhoRelacao Comprimento da tabela.
	\param atual Caracter que vem antes.
	\param proximo Caracter que vem depois.
	\return Um inteiro representando verdadeiro ou falso.
*/
int casoEspecial(tabela *relacao, int tamanhoRelacao, char atual, char proximo)
{
	int valorAtual = findAlgarismo(atual, relacao, tamanhoRelacao);
	int valorProx =  findAlgarismo(proximo, relacao, tamanhoRelacao);
	return valorAtual < valorProx;
}

/**
	Acha o valor correspondente ao algarismo romano passado.
	\param algarismo Algarismo da qual se quer o valor correspondente.
	\param relacao Tabela contendo as relações entre algarismo e valor.
	\param tamanho Comprimento da tabela relacional.
	\return Retorna o valor do algarismo passado. Retorna -1 se não existir na tabela.
*/
int findAlgarismo(char algarismo, tabela *relacao, int tamanho)
{
	int i = 0;
	while(i < tamanho && relacao[i].algarismo != algarismo)//percorre a lista toda ou até achar o algarismo na lista.
		i++;
	if(relacao[i].algarismo == algarismo)//testa se realmente é o valor procurado, poderia ter sido apenas o fim da lista.
		return relacao[i].valor;//retorna o valor do algarismo.
	return -1;//retorna -1 se não houver valor
}

/**
	\file
	Pacote de funções para converter números romanos em arábicos.
*/

#endif