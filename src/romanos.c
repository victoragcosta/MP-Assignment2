#ifndef ROMANOS_C
#define ROMANOS_C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int converter(char *romano)
{
	int valores[2][2];
	valores[1][1] = 'I';
	valores[1][2] = 1;

	valores[2][1] = 'V';
	valores[2][2] = 5;

	int i = 0, soma = 0;
	while(romano[i] != '\0' && i <= 30){
		if((unsigned int)i+1 < strlen(romano) && romano[i] == valores[1][1] && romano[i+1] == valores[1+1][1]){
			soma += valores[1+1][2] - valores[1][2];
			i+=2;
		}
		if(romano[i] == valores[1][1])
			soma += valores[1][2];
		if(romano[i] == valores[2][1])
			soma += valores[2][2];
		i++;
	}

	return soma;
}

#endif