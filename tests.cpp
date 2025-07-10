//roymeoded2512@gmail.com

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "SquareMat.hpp"

//Operator(+) between two matrices:
TEST_CASE("Operator + between two matrices-->mat1+mat2"){
    mat::SquareMat mat1(2);
    mat::SquareMat mat2(2);

    mat1[0]=1;  
    mat1[1]=2; 
    mat1[2]=3;
    mat1[3]=4;

    mat2[0]=5;  
    mat2[1]=6;   
    mat2[2]=7;
    mat2[3]=8;

    mat::SquareMat ans=mat1+mat2;

    CHECK(ans[0]==6);
    CHECK(ans[1]==8);
    CHECK(ans[2]==10);
    CHECK(ans[3]==12);
}
//Cannot add two matrices with different sizes:
TEST_CASE("Operator + between two matrices with different sizes"){
    mat::SquareMat mat3(2);
    mat::SquareMat mat4(4);

    CHECK_THROWS_AS(mat3+mat4,std::invalid_argument);
}

//Operator(-) between two matrices:
TEST_CASE("Operator - between two matrices-->mat1-mat2"){
    mat::SquareMat mat5(2);
    mat::SquareMat mat6(2);

    mat5[0]=1;  
    mat5[1]=2; 
    mat5[2]=3;
    mat5[3]=4;

    mat6[0]=5;  
    mat6[1]=6;   
    mat6[2]=7;
    mat6[3]=8;

    mat::SquareMat ans2=mat5-mat6;

    CHECK(ans2[0]==-4);
    CHECK(ans2[1]==-4);
    CHECK(ans2[2]==-4);
    CHECK(ans2[3]==-4);
}
//Cannot substract two matrices with different sizes:
TEST_CASE("Operator - between two matrices with different sizes"){
    mat::SquareMat mat7(2);
    mat::SquareMat mat8(4);

    CHECK_THROWS_AS(mat7-mat8,std::invalid_argument);
}
//Unary operator (-)--->change the sign of the matrix's elements:
TEST_CASE("Unary operator: mat-->-(mat)"){
    mat::SquareMat mat9(2);

    mat9[0]=1;  
    mat9[1]=2; 
    mat9[2]=-2;
    mat9[3]=4;

    mat::SquareMat ans3=-mat9;

    CHECK(ans3[0]==-1);
    CHECK(ans3[1]==-2);
    CHECK(ans3[2]==2);
    CHECK(ans3[3]==-4);
}

//Operator(*) between two matrices:
TEST_CASE("Operator * between two matrices-->mat1*mat2"){
    mat::SquareMat mat10(2);
    mat::SquareMat mat11(2);

    mat10[0]=1;  
    mat10[1]=2; 
    mat10[2]=3;
    mat10[3]=4;

    mat11[0]=5;  
    mat11[1]=6;   
    mat11[2]=7;
    mat11[3]=8;

    mat::SquareMat ans4=mat10*mat11;

    CHECK(ans4[0]==19);
    CHECK(ans4[1]==22);
    CHECK(ans4[2]==43);
    CHECK(ans4[3]==50);
}
//Cannot multiply two matrices with different sizes:
TEST_CASE("Operator * between two matrices with different sizes"){
    mat::SquareMat mat12(2);
    mat::SquareMat mat13(4);

    CHECK_THROWS_AS(mat12*mat13,std::invalid_argument);
}
//scalar*matrix:
TEST_CASE("Multiply the matrix with scalar(on the left)"){
    mat::SquareMat mat14(2);
    mat14[0]=1;
    mat14[1]=2;
    mat14[2]=3;
    mat14[3]=4;

    double scalar=0.5;
    mat::SquareMat ans5=scalar*mat14;

    CHECK(ans5[0]==0.5);    
    CHECK(ans5[1]==1);
    CHECK(ans5[2]==1.5);
    CHECK(ans5[3]==2);

}
//matrix*scalar:
TEST_CASE("Multiply the matrix with scalar(on the right)"){
    mat::SquareMat mat15(2);
    mat15[0]=1;
    mat15[1]=2;
    mat15[2]=3;
    mat15[3]=4;

    double scalar2=0.5;
    mat::SquareMat ans6=mat15*scalar2;

    CHECK(ans6[0]==0.5);    
    CHECK(ans6[1]==1);
    CHECK(ans6[2]==1.5);
    CHECK(ans6[3]==2);

}

//Operator(%) between two matrices--->multiply each element mat1(i,j)*mat2(i,j):
TEST_CASE("Operator % between two matrices-->mat1(i,j)*mat2(i,j)"){
    mat::SquareMat mat16(2);
    mat::SquareMat mat17(2);

    mat16[0]=1;  
    mat16[1]=2; 
    mat16[2]=3;
    mat16[3]=4;

    mat17[0]=5;  
    mat17[1]=6;   
    mat17[2]=7;
    mat17[3]=8;

    mat::SquareMat ans7=mat16%mat17;

    CHECK(ans7[0]==5);
    CHECK(ans7[1]==12);
    CHECK(ans7[2]==21);
    CHECK(ans7[3]==32);
}
//Cannot multiply each element on  two matrices with different sizes:
TEST_CASE("Operator % between two matrices with different sizes"){
    mat::SquareMat mat18(2);
    mat::SquareMat mat19(4);

    CHECK_THROWS_AS(mat18%mat19,std::invalid_argument);
}

//Modulo with scalar:
TEST_CASE("Operator modulo %--->mat (%) scalar"){
    SUBCASE("Positive scalar"){
        mat::SquareMat mat20(2);

        mat20[0]=5;  
        mat20[1]=10; 
        mat20[2]=7;
        mat20[3]=13;

        double scalar3=4;
        mat::SquareMat ans8=mat20%scalar3;

        CHECK(ans8[0]==doctest::Approx(fmod(5,4)));
        CHECK(ans8[1]==doctest::Approx(fmod(10,4)));
        CHECK(ans8[2]==doctest::Approx(fmod(7,4)));
        CHECK(ans8[3]==doctest::Approx(fmod(13,4)));

    }

     SUBCASE("Zero scalar(throws)"){
        mat::SquareMat mat21(2);

        mat21[0]=5;  
        mat21[1]=10; 
        mat21[2]=7;
        mat21[3]=13;

        CHECK_THROWS_AS(mat21%0,std::invalid_argument);
     }
}

//Operator(/) matrix/scalar:
TEST_CASE("Operator (/) between matrix and scalar"){
    mat::SquareMat mat22(2);

    mat22[0]=1;  
    mat22[1]=2; 
    mat22[2]=3;
    mat22[3]=4;

    double scalar4=4;
    mat::SquareMat ans9=mat22/scalar4;

    CHECK(ans9[0]==0.25);
    CHECK(ans9[1]==0.5);
    CHECK(ans9[2]==0.75);
    CHECK(ans9[3]==1);
}
//Cannot divide  matrix with scalar 0:
TEST_CASE("Operator / between matrix with scalar 0"){
    mat::SquareMat mat23(2);

    mat23[0]=1;  
    mat23[1]=2; 
    mat23[2]=3;
    mat23[3]=4;

    CHECK_THROWS_AS(mat23/0,std::invalid_argument);
}

//Power operator(^):
TEST_CASE("Operator power(^)"){
    SUBCASE("Power 0 returns the ID matrix"){
        mat::SquareMat mat24(2);

        mat24[0]=1;  
        mat24[1]=2; 
        mat24[2]=3;
        mat24[3]=4;

        mat::SquareMat ans10=mat24^0;
        CHECK(ans10[0]==1);
        CHECK(ans10[1]==0);
        CHECK(ans10[2]==0);
        CHECK(ans10[3]==1);
    }
    SUBCASE("Power 1 returns the same matrix"){
        mat::SquareMat mat25(2);

        mat25[0]=1;  
        mat25[1]=2; 
        mat25[2]=3;
        mat25[3]=4;

        mat::SquareMat ans11=mat25^1;
        CHECK(ans11[0]==1);
        CHECK(ans11[1]==2);
        CHECK(ans11[2]==3);
        CHECK(ans11[3]==4);
    }
    SUBCASE("Power 2 returns (matrix)^2 "){
        mat::SquareMat mat26(2);

        mat26[0]=1;  
        mat26[1]=2; 
        mat26[2]=3;
        mat26[3]=4;

        mat::SquareMat ans12=mat26^2;
        CHECK(ans12[0]==7);
        CHECK(ans12[1]==10);
        CHECK(ans12[2]==15);
        CHECK(ans12[3]==22);
    }
    SUBCASE("Negative power--->throws"){
        mat::SquareMat mat27(2);

        mat27[0]=1;  
        mat27[1]=2; 
        mat27[2]=3;
        mat27[3]=4;

        CHECK_THROWS_AS(mat27^-1,std::invalid_argument);

    }
}
//Operator (++):
TEST_CASE("Prefix ++ operator"){
    mat::SquareMat mat28(2);

    mat28[0]=1;  
    mat28[1]=2; 
    mat28[2]=3;
    mat28[3]=4;

    mat::SquareMat& ans13=++mat28;

    CHECK(ans13[0]==2); 
    CHECK(ans13[1]==3); 
    CHECK(ans13[2]==4); 
    CHECK(ans13[3]==5); 
    CHECK(&ans13==&mat28);
}

TEST_CASE("Postfix ++ operator"){
    mat::SquareMat mat29(2);

    mat29[0]=1;  
    mat29[1]=2; 
    mat29[2]=3;
    mat29[3]=4;

    mat::SquareMat ans14=mat29++;

    CHECK(mat29[0]==2); 
    CHECK(mat29[1]==3); 
    CHECK(mat29[2]==4); 
    CHECK(mat29[3]==5); 
    CHECK(ans14[0]==1); 
    CHECK(ans14[1]==2); 
    CHECK(ans14[2]==3); 
    CHECK(ans14[3]==4); 
}
//Operator (--):
TEST_CASE("Prefix -- operator"){
    mat::SquareMat mat30(2);

    mat30[0]=1;  
    mat30[1]=2; 
    mat30[2]=3;
    mat30[3]=4;

    mat::SquareMat& ans15=--mat30;

    CHECK(ans15[0]==0); 
    CHECK(ans15[1]==1); 
    CHECK(ans15[2]==2); 
    CHECK(ans15[3]==3); 
    CHECK(&ans15==&mat30);
}

TEST_CASE("Postfix--operator"){
    mat::SquareMat mat31(2);

    mat31[0]=1;  
    mat31[1]=2; 
    mat31[2]=3;
    mat31[3]=4;

    mat::SquareMat ans16=mat31--;

    CHECK(mat31[0]==0); 
    CHECK(mat31[1]==1); 
    CHECK(mat31[2]==2); 
    CHECK(mat31[3]==3); 
    CHECK(ans16[0]==1); 
    CHECK(ans16[1]==2); 
    CHECK(ans16[2]==3); 
    CHECK(ans16[3]==4); 
}
//Operator ~-->(mat)^T:
TEST_CASE("Transpose operator ~"){

    mat::SquareMat mat32(2);

    mat32[0]=1;  
    mat32[1]=2; 
    mat32[2]=3;
    mat32[3]=4;

    mat::SquareMat ans17=~mat32;

    CHECK(ans17[0]==1); 
    CHECK(ans17[1]==3); 
    CHECK(ans17[2]==2); 
    CHECK(ans17[3]==4); 
}

//Index operator:
TEST_CASE("Index operator []"){
    SUBCASE("Access and modify elements"){
        mat::SquareMat mat33(2);

        mat33[0]=1;  
        mat33[1]=2; 
        mat33[2]=3;
        mat33[3]=4;

        CHECK(mat33[0]==1); 
        CHECK(mat33[1]==2); 
        CHECK(mat33[2]==3); 
        CHECK(mat33[3]==4); 

        mat33[0]=7;
        CHECK(mat33[0]==7);
    }
    SUBCASE("Out of bounds access throw"){
        mat::SquareMat mat34(2);
        CHECK_THROWS_AS(mat34[4],std::out_of_range);
        CHECK_THROWS_AS(mat34[-1],std::out_of_range);
    }

}

//Operator != ==:
TEST_CASE("Operators != =="){

    mat::SquareMat mat35(2);

    mat35[0]=1;  
    mat35[1]=2; 
    mat35[2]=3;
    mat35[3]=4; 

    mat::SquareMat mat36(2);

    mat36[0]=1;  
    mat36[1]=2; 
    mat36[2]=3;
    mat36[3]=4; 

    mat::SquareMat mat37(2);

    mat37[0]=1;  
    mat37[1]=2; 
    mat37[2]=5;
    mat37[3]=4;

    CHECK(mat35==mat36);
    CHECK_FALSE(mat35==mat37);

    CHECK(mat35!=mat37);
}

TEST_CASE("Cannot work with == != with different sizes"){
    mat::SquareMat mat38(2);
    mat::SquareMat mat39(3);

    CHECK_THROWS_AS(mat38==mat39,std::invalid_argument);    
    CHECK_THROWS_AS(mat38!=mat39,std::invalid_argument);
}
TEST_CASE("Comparison operators <, >, <=, >=") {
    mat::SquareMat mat40(2);
    mat::SquareMat mat41(2);
    mat::SquareMat mat42(3);

    mat40[0] = 1;
    mat40[1] = 2;
    mat40[2] = 3;
    mat40[3] = 4;

    mat41[0] = 2;
    mat41[1] = 3;
    mat41[2] = 4;
    mat41[3] = 5;

    CHECK(mat40 < mat41);
    CHECK(mat40 <= mat41);
    CHECK_FALSE(mat41 <= mat40);
    CHECK_FALSE(mat40 >= mat41);

   

    //Matrices with different sizes-->throws:
    CHECK_THROWS_AS(mat40 < mat42, std::invalid_argument);
    CHECK_THROWS_AS(mat40 > mat42, std::invalid_argument);
    CHECK_THROWS_AS(mat40 <= mat42, std::invalid_argument);
    CHECK_THROWS_AS(mat40 >= mat42, std::invalid_argument);
}

//Operator !--->determinant:Det(mat)
TEST_CASE("Determinant operator ! Det(mat)") {
    SUBCASE("1x1 matrix") {
        mat::SquareMat mat43(1);
        mat43[0] = 7;
        CHECK((!mat43) == doctest::Approx(7));
    }

    SUBCASE("2x2 matrix") {
        mat::SquareMat mat44(2);
        mat44[0] = 1;
        mat44[1] = 2;
        mat44[2] = 3;
        mat44[3] = 4;
        CHECK((!mat44) == doctest::Approx(-2));
    }

    SUBCASE("3x3 matrix") {
        mat::SquareMat mat45(3);
        mat45[0] = 6;
        mat45[1] = 1;
        mat45[2] = 1;
        mat45[3] = 4;
        mat45[4] = -2;
        mat45[5] = 5;
        mat45[6] = 2;
        mat45[7] = 8;
        mat45[8] = 7;
        CHECK((!mat45) == doctest::Approx(-306));
    }
}


//Operator +=--->mat1=mat1+mat2:
TEST_CASE("Operator += mat1=mat1+mat2") {
    SUBCASE("Regular addition") {
        mat::SquareMat mat46(2);
        mat::SquareMat mat47(2);
        mat46[0] = 1;
        mat46[1] = 2;
        mat46[2] = 3;
        mat46[3] = 4;

        mat47[0] = 5;
        mat47[1] = 6; 
        mat47[2] = 7; 
        mat47[3] = 8;

        mat46 += mat47;

        CHECK(mat46[0] == 6);
        CHECK(mat46[1] == 8);
        CHECK(mat46[2] == 10);
        CHECK(mat46[3] == 12);
    }

    SUBCASE("Different sizes should throw") {
        mat::SquareMat mat48(2);
        mat::SquareMat mat49(3);

        CHECK_THROWS_AS(mat48 += mat49, std::invalid_argument);
    }
}

//Operator -=--->mat1=mat1-mat2:
TEST_CASE("Operator -= mat1=mat1-mat2") {
    SUBCASE("Regular Substruction") {
        mat::SquareMat mat50(2);
        mat::SquareMat mat51(2);
        mat50[0] = 1;
        mat50[1] = 2;
        mat50[2] = 3;
        mat50[3] = 4;

        mat51[0] = 5;
        mat51[1] = 6; 
        mat51[2] = 7; 
        mat51[3] = 8;

        mat50 -= mat51;

        CHECK(mat50[0] == -4);
        CHECK(mat50[1] == -4);
        CHECK(mat50[2] == -4);
        CHECK(mat50[3] == -4);
    }

    SUBCASE("Different sizes should throw") {
        mat::SquareMat mat52(2);
        mat::SquareMat mat53(3);

        CHECK_THROWS_AS(mat52 -= mat53, std::invalid_argument);
    }
}

//*= -->Two operators:
TEST_CASE("Operator *= -->mat1=mat1*mat"){
        mat::SquareMat mat60(2);
        mat::SquareMat mat61(2);


        mat60[0]=1;
        mat60[1]=2;
        mat60[2]=3;
        mat60[3]=4;

        mat61[0]=5;
        mat61[1]=6;
        mat61[2]=7;
        mat61[3]=8;

        mat60*=mat61;

        CHECK(mat60[0]==19);
        CHECK(mat60[1]==22);
        CHECK(mat60[2]==43);
        CHECK(mat60[3]==50);

}
TEST_CASE("Try the *= operator with two matrices with different sizes"){

    mat::SquareMat mat62(2);
    mat::SquareMat mat63(3);

    CHECK_THROWS_AS(mat62 *= mat63, std::invalid_argument);


}
TEST_CASE("Try the *= operator with matrix and scalar"){

    mat::SquareMat mat64(2);

    mat64[0]=1;
    mat64[1]=2;
    mat64[2]=3;
    mat64[3]=4;

    double siakam=4.5;

    mat64*=siakam;

    CHECK(mat64[0]==4.5);
    CHECK(mat64[1]==9);
    CHECK(mat64[2]==13.5);
    CHECK(mat64[3]==18);
}
TEST_CASE("Try the /= operator with matrix and scalar"){

    mat::SquareMat mat65(2);

    mat65[0]=1;
    mat65[1]=2;
    mat65[2]=3;
    mat65[3]=4;

    double tyrees=0.5;

    mat65/=tyrees;

    CHECK(mat65[0]==2);
    CHECK(mat65[1]==4);
    CHECK(mat65[2]==6);
    CHECK(mat65[3]==8);
}
TEST_CASE("Try the /= operator with scalar 0-->throw"){

    mat::SquareMat mat66(2);
    double curry=0;

    CHECK_THROWS_AS(mat66 /= curry, std::invalid_argument);
}

//Operator %=--->mat1=mat1%mat2:
TEST_CASE("Operator %----->mat1=mat1%mat2"){
     mat::SquareMat mattt(2);
     mat::SquareMat matt(2);


    mattt[0]=1;
    mattt[1]=2;
    mattt[2]=3;
    mattt[3]=4;

    matt[0]=5;
    matt[1]=6;
    matt[2]=7;
    matt[3]=8;

    mattt%=matt;

    CHECK(mattt[0]==1);
    CHECK(mattt[1]==2);
    CHECK(mattt[2]==3);
    CHECK(mattt[3]==4);

}

//Operator %=--->mat1=mat1%scalar:
TEST_CASE("Operator %----->mat1=mat1 (%) scalar"){
     mat::SquareMat mat500(2);
     double scalar=3;


    mat500[0]=1;
    mat500[1]=2;
    mat500[2]=3;
    mat500[3]=4;


    mat500%=scalar;

    CHECK(mat500[0]==1);
    CHECK(mat500[1]==2);
    CHECK(mat500[2]==0);
    CHECK(mat500[3]==1);

}

TEST_CASE("Try the %= operator with scalar 0-->throw"){

    mat::SquareMat mat600(2);
    double brooks=0;

    CHECK_THROWS_AS(mat600 %= brooks, std::invalid_argument);
}

TEST_CASE("Try the %= operator with 2 matrices  with different sizes-->throw"){

    mat::SquareMat mat700(2);
    mat::SquareMat mat8700(3);

    CHECK_THROWS_AS(mat700 %= mat8700, std::invalid_argument);
}

TEST_CASE("Operator >> : print the matrix"){
    std::stringstream ss;
    mat::SquareMat mat777(2);
    mat777[0]=1;
    mat777[1]=2;
    mat777[2]=3;
    mat777[3]=4;

    ss<<mat777;

    std::string expected= "1 2 \n3 4 \n";
    CHECK(ss.str()==expected);
}


