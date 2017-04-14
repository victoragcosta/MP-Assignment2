#ifndef ROMANOS_C
#define ROMANOS_C

#include <stdlib.h>

int converter(char *romano)
{
	char valores[1][2];
	valores[1][1] = 'I';
	valores[1][2] = 1;

	int i = 0, soma = 0;
	while(romano[i] != '\0' && i <= 30){
		if(romano[i] == valores[1][1])
			soma += valores[1][2];
		i++;
	}

	return soma;
}

#endif