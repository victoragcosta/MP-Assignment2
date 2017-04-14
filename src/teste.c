#include <stdlib.h>
#include <stdio.h>
#include <gtest/gtest.h>
#include "romanos.h"

//======Testes======//
TEST(Converter,Vazio){
	char romano[]="";
	ASSERT_EQ(0, converter(romano));
}


//====Fim Testes====//

int main(int argc, char *argv[])
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}