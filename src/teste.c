#include <stdlib.h>
#include <stdio.h>
#include <gtest/gtest.h>
#include "romanos.h"

//======Testes======//
TEST(Converter,Vazio){
	char romano[]="";
	ASSERT_EQ(0, converter(romano)) << "Não reconhece o 0";
}

TEST(Converter,AlgarismoI){
	FILE *dados;
	int i, valor;
	char romano[31];
	dados = fopen("../numeros_romanos.txt", "r");
	ASSERT_NE((FILE*)NULL, dados) << "Não foi possível abrir conjunto de numeros romanos";
	
	for(i = 1; i <= 3; i++){
		fscanf(dados, "%d: %s", &valor, &romano[0]);
		EXPECT_EQ(valor, converter(romano)) << "Não foi capaz de converter " << valor << ": " << romano;
	}

	fclose(dados);
}

TEST(Converter,AlgarismoV){
	ASSERT_EQ(5, converter((char*)"V\0")) << "Não foi possível converter o 5: V";
}

TEST(Converter,CasoEspecialIV){
	ASSERT_EQ(4, converter((char*)"IV\0")) << "Não foi possível converter o 4: IV";
}

TEST(Converter,NumerosComX){
	FILE *dados;
	int i, valor;
	char romano[31];
	dados = fopen("../numeros_romanos.txt", "r");
	ASSERT_NE((FILE*)NULL, dados) << "Não foi possível abrir conjunto de numeros romanos";
	
	for(i = 1; i <= 39; i++){
		fscanf(dados, "%d: %s", &valor, &romano[0]);
		EXPECT_EQ(valor, converter(romano)) << "Não foi capaz de converter " << valor << ": " << romano;
	}

	fclose(dados);
}

TEST(Converter,NumerosComL){
	FILE *dados;
	int i, valor;
	char romano[31];
	dados = fopen("../numeros_romanos.txt", "r");
	ASSERT_NE((FILE*)NULL, dados) << "Não foi possível abrir conjunto de numeros romanos";
	
	for(i = 1; i <= 89; i++){
		fscanf(dados, "%d: %s", &valor, &romano[0]);
		EXPECT_EQ(valor, converter(romano)) << "Não foi capaz de converter " << valor << ": " << romano;
	}

	fclose(dados);
}

//====Fim Testes====//

int main(int argc, char *argv[])
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}