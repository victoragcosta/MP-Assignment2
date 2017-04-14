#ifndef ROMANOS_C
#define ROMANOS_C

#include <stdlib.h>

int converter(char *romano)
{
	char valores[2][2];
	valores[1][1] = 'I';
	valores[1][2] = 1;

	valores[2][1] = 'V';
	valores[2][2] = 5;

	int i = 0, soma = 0;
	while(romano[i] != '\0' && i <= 30){
		if(romano[i] == valores[1][1])
			soma += valores[1][2];
		if(romano[i] == valores[2][1])
			soma += valores[2][2];
		i++;
	}

	return soma;
}

#endif