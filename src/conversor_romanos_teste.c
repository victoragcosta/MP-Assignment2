#include "conversor_romanos.h"
#include <stdlib.h>
#include <stdio.h>
#include <gtest/gtest.h>

//======Testes======//

/**
  Teste que testa a conversão de um número romano vazio para arábico.
  A função deve retornar 0 para passar no teste.
*/
TEST(Converter,Vazio){
  ASSERT_EQ(0, Converter((char*)"\0")) << "Não reconhece o 0";
}

/**
  Testa para todos os números somente com I.
  O teste pega os 3 primeiros números da tabela
  de todos os romanos e os testa. São eles I, II e III.
  Para passar devem retornar 1, 2 e 3 respectivamente.

  O teste serve para ver a funcionalidade do mecanismo
  de soma dos valores da função converte.
*/
TEST(Converter,AlgarismoI){
  FILE *dados;
  int i, valor;
  char romano[31];
  dados = fopen("../numeros_romanos.txt", "r");
  ASSERT_NE((FILE*)NULL, dados) << "Não foi possível abrir conjunto de numeros romanos";
  
  for(i = 1; i <= 3; i++){
    fscanf(dados, "%d: %s", &valor, &romano[0]);
    EXPECT_EQ(valor, Converter(romano)) << "Não foi capaz de Converter " << valor << ": " << romano;
  }

  fclose(dados);
}

/**
  Testa para a adição do algarismo V.
  Para passar a função Converter deve retornar 5.

  O teste objetiva observar os padrões de uma tabela
  de valores na função Converter, para facilitar em
  testes futuros a generalização.
*/
TEST(Converter,AlgarismoV){
  ASSERT_EQ(5, Converter((char*)"V")) << "Não foi possível Converter o 5: V";
}

/**
  Testa o mecanismo de detecção de casos em que ocorre a subtração do valor.
  Para passar a função Converter deve retornar 4.

  Esse teste vê testa a função Converter afim de ver a capacidade da função
  de fazer com o caso mais simples de subtração nos romanos.
*/
TEST(Converter,CasoEspecialIV){
  ASSERT_EQ(4, Converter((char*)"IV")) << "Não foi possível Converter o 4: IV";
}

/**
  Testa a capacidade de conversão de números com algarismos I, V e X.
  Para passar deve retornar números iguais aos da tabela em numeros_romanos.txt.
  
  Esse teste visou auxiliar no desenvolvimento de condicionais para 
  uma lista relacional mais genérica, facilitando a expansão posterior.
  Ela também auxilia na generalização do caso especial de subtração.
*/
TEST(Converter,NumerosComX){
  FILE *dados;
  int i, valor;
  char romano[31];
  dados = fopen("../numeros_romanos.txt", "r");
  ASSERT_NE((FILE*)NULL, dados) << "Não foi possível abrir conjunto de numeros romanos";
  
  for(i = 1; i <= 39; i++){
    fscanf(dados, "%d: %s", &valor, &romano[0]);
    EXPECT_EQ(valor, Converter(romano)) << "Não foi capaz de Converter " << valor << ": " << romano;
  }

  fclose(dados);
}

/**
  Testa uma quantidade maior de números contendo I, V, X e L.
  Para passar deve retornar números iguais aos da tabela em numeros_romanos.txt.

  Esse teste visa auxiliar na expansão da tabela e
  também a verificar se o desenvolvimento de casos
  especiais estava conseguindo generalizar para outros
  números.
*/
TEST(Converter,NumerosComL){
  FILE *dados;
  int i, valor;
  char romano[31];
  dados = fopen("../numeros_romanos.txt", "r");
  ASSERT_NE((FILE*)NULL, dados) << "Não foi possível abrir conjunto de numeros romanos";
  
  for(i = 1; i <= 89; i++){
    fscanf(dados, "%d: %s", &valor, &romano[0]);
    EXPECT_EQ(valor, Converter(romano)) << "Não foi capaz de Converter " << valor << ": " << romano;
  }

  fclose(dados);
}

/**
  Testa todos os números romanos até 3999.
  Para passar deve retornar números iguais aos da tabela em numeros_romanos.txt.

  Este era o teste final para ver se a conversão realmente funcionava.
  Passando esse teste, basta desenvolver para tratar números inválidos.
*/
TEST(Converter,Todos){
  FILE *dados;
  int i, valor;
  char romano[31];
  dados = fopen("../numeros_romanos.txt", "r");
  ASSERT_NE((FILE*)NULL, dados) << "Não foi possível abrir conjunto de numeros romanos";
  
  for(i = 1; i <= 3999; i++){
    fscanf(dados, "%d: %s", &valor, &romano[0]);
    EXPECT_EQ(valor, Converter(romano)) << "Não foi capaz de Converter " << valor << ": " << romano;
  }

  fclose(dados);
}

/**
  Testa com números válidos com letras maiúsculas ou minúsculas.
  Para passar basta converter corretamente ignorando a diferenciação
  entre maiúsculas e minúsculas.

  Este teste significa que a função se torna mais robusta e genérica,
  protegida.
*/
TEST(Converter,NumerosLowerCase){
  char romano4[]="iV", romano14[]="Xiv";
  EXPECT_EQ(4, Converter(romano4));
  EXPECT_EQ(14, Converter(romano14));
}

//====Fim Testes====//

/**
  Função main que coloca os testes a funcionar.
  \param argc Inteiro com a quantidade de argumentos passados na prompt de comando.
  \param argv Vetor de ponteiro pra char contendo todos os argumentos passados pela prompt de comando.
  \return Inteiro retornando códigos de erro ou 0, quando for bem sucedido.
*/
int main(int argc, char *argv[])
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

/**
  \file
  \brief Arquivo com a main e os testes a serem rodados.
*/