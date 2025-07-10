//roymeoded2512@gmail.com

#include "SquareMat.hpp"
#include <iostream>

using namespace mat;

int main(){

    try{

        //Create square matrix on 3x3:
        SquareMat matrix(3);

        //Fill the elements of our matrix:
        for(int i=0;i<matrix.getSize()*matrix.getSize();i++){
            matrix[i]=i+1;
        }

        //Print the size of cthe matrix:
        std::cout<<"The size of the matrix is : "<<matrix.getSize()<<"x"<<matrix.getSize()<<std::endl;

        //Print the matrix, using operator<<:
        std::cout<<"Our matrix's elements:"<<std::endl;
        std::cout<<matrix<<std::endl;

        //Access to the operator []--> reading and writing:
        std::cout<<"\n**********Operator([])**********\n"<<std::endl;

        std::cout<<"\nOur matrix's elements:"<<std::endl;
        std::cout<<matrix<<std::endl;
        std::cout << "Accessing the element matrix[4] before changing: "<<matrix[4]<<std::endl;
        matrix[4]=20; //We change now the element
        std::cout << "Accessing the element matrix[4] after changing: "<<matrix[4]<<std::endl;

        std::cout<<"Our matrix after we change the element matrix[4]:"<<std::endl;
        std::cout<<matrix<<std::endl;

        std::cout<<"\n**********Operator(+)**********\n"<<std::endl;

        //Now lets show the operator+(between two matrices):
        SquareMat mat1(3);
        SquareMat mat2(3);

        for(int i=0;i<9;i++){
            mat1[i]=i+1; //1,2,3,4,5,6,7,8,9
            mat2[i]=i*2; //0,2,4,6,8,10,12,14,16
        }
        SquareMat mat3=mat1+mat2;

        std::cout<<"Matrix mat1:"<<std::endl<<mat1;
        std::cout<<"\nMatrix mat2:"<<std::endl<<mat2;
        std::cout<<"\nMatrix mat3(mat3=mat1+mat2):"<<std::endl<<mat3;

        std::cout<<"\n**********Operator(-)**********\n"<<std::endl;

        //Now lets show the operator+(between two matrices):
        SquareMat mat4(3);
        SquareMat mat5(3);

        for(int i=0;i<9;i++){
            mat4[i]=i+2; //2,3,4,5,6,7,8,9,10
            mat5[i]=i; //0,1,2,3,4,5,6,7,8
        }
        SquareMat mat6=mat4-mat5;

        std::cout<<"Matrix mat4:"<<std::endl<<mat4;
        std::cout<<"\nMatrix mat5:"<<std::endl<<mat5;
        std::cout<<"\nMatrix mat6(mat6=mat4-mat5):"<<std::endl<<mat6;

        std::cout<<"\n**********Operator(*)**********\n"<<std::endl;

        //Now lets show the operator*(between two matrices):
        SquareMat mat7(2);
        SquareMat mat8(2);

        mat7[0]=1;  //  (1 , 2 )
        mat7[1]=2;  //  (3 , 4 ) 
        mat7[2]=3;
        mat7[3]=4;

        mat8[0]=5;  //  (5 , 6 )
        mat8[1]=6;  //  (7 , 8 ) 
        mat8[2]=7;
        mat8[3]=8;

        SquareMat mat9=mat7*mat8;

        std::cout<<"mat7: "<<std::endl<<mat7;
        std::cout<<"mat8: "<<std::endl<<mat8;
        std::cout<<"mat9(=mat7*mat8): "<<std::endl<<mat9;

        std::cout<<"\n**********Unary (-matrix)**********\n"<<std::endl;

        SquareMat mat11(2);

        mat11[0]=1;
        mat11[1]=2;
        mat11[2]=-3;
        mat11[3]=4;

        SquareMat unaryMat=-mat11;

        std::cout<<"Our initial matrix is :"<<std::endl<<mat11;
        std::cout<<"Our negated matrix is (-matrix): "<<std::endl<<unaryMat;

        std::cout<<"\n**********(matrix*scalar)//(scalar*matrix)**********\n"<<std::endl;

        SquareMat mat12(2);

        mat12[0]=1;
        mat12[1]=2;
        mat12[2]=3;
        mat12[3]=4;

        SquareMat mat13=mat12*2;
        SquareMat mat14=3*mat12;

        std::cout<<"Our initial matrix is : "<<std::endl<<mat12;
        std::cout<<"\nOur matrix after we multiply with scalar 2(mat12*scalar): "<<std::endl<<mat13;
        std::cout<<"\nOur matrix after we multiply with scalar 3(scalar*mat12): "<<std::endl<<mat14;

        std::cout<<"\n**********(matrix[i]/scalar)**********\n"<<std::endl;
        SquareMat mat15(2);

        mat15[0]=11;
        mat15[1]=12;
        mat15[2]=1;
        mat15[3]=33;

        double scalar=3;
        SquareMat mat16=mat15/scalar;

        std::cout<<"Our initial matrix is :"<<std::endl<<mat15;
        std::cout<<"\nNow after we divide each element with 3, the matrix is: "<<std::endl<<mat16;

        std::cout<<"\n**********(result[i]=mat[i]*other[i])**********\n"<<std::endl;
        SquareMat mat17(2);
        SquareMat mat18(2);

        mat17[0]=1;
        mat17[1]=2;
        mat17[2]=3;
        mat17[3]=4;

        mat18[0]=2;
        mat18[1]=4;
        mat18[2]=6;
        mat18[3]=8;

        SquareMat  mat19=mat17%mat18;

        std::cout<<"Our first matrix is : "<<std::endl<<mat17;
        std::cout<<"\nOur other matrix is: "<<std::endl<<mat18;
        std::cout<<"\nOur matrix after we multiply each element between mat and other mat: "<<std::endl<<mat19;

        std::cout<<"\n**********(result[i]=mat[i] (%) scalar)**********\n"<<std::endl;
        SquareMat mat20(2);

        mat20[0]=10.5;
        mat20[1]=21.3;
        mat20[2]=31.7;
        mat20[3]=41.1;

        int scalar2=7; 

        SquareMat mat21=mat20%scalar2;

        std::cout<<"Our initial matrix is : "<<std::endl<<mat20;
        std::cout<<"Now our matrix after each element we do modulo--->mat21[i]==mat[20]%7: "<<std::endl<<mat21;

        std::cout<<"\n**********Operator power (^)**********\n"<<std::endl;

        SquareMat mat22(2);

        mat22[0]=1;
        mat22[1]=2;
        mat22[2]=3;
        mat22[3]=4;

        int power=2;

        SquareMat mat23=mat22^power;
        std::cout<<"Our initial matrix is : "<<std::endl<<mat22;
        std::cout<<"Now our matrix after we raises the matrix with power 2-->(mat)^2: "<<std::endl<<mat23;

        std::cout<<"\n**********Operator transport (~)**********\n"<<std::endl;

        SquareMat mat24(3);

        mat24[0]=2;
        mat24[1]=4;
        mat24[2]=10;
        mat24[3]=55;
        mat24[4]=100;
        mat24[5]=-12.5;
        mat24[6]=1111;
        mat24[7]=-1;
        mat24[8]=123;

        SquareMat mat25=~mat24; //(mat24)^T

        std::cout<<"Our initial matrix is : "<<std::endl<<mat24;
        std::cout<<"Now our matrix after we transport it ((mat24)^T): "<<std::endl<<mat25;

        std::cout<<"\n**********Prefix(++/--) and Postfix(++/--)**********\n"<<std::endl;


        //Prefix:
        std::cout<<"*****Prefix*****"<<std::endl;
        std::cout<<"\n*****Prefix(++)*****"<<std::endl;
        SquareMat mat26(2);

        mat26[0]=1;
        mat26[1]=2;
        mat26[2]=3;
        mat26[3]=4;

        std::cout<<"Our matrix before :"<<std::endl<<mat26;
        SquareMat prefixplus=++mat26;
        std::cout<<"\nThe matrix with Prefix ++ (++mat26) :"<< std::endl<<prefixplus;
        std::cout<<"\nOur matrix now: "<<std::endl<<mat26;

        SquareMat mat27(2);

        mat27[0]=1;
        mat27[1]=2;
        mat27[2]=3;
        mat27[3]=4;

        std::cout<<"\n*****Prefix(--)*****"<<std::endl;
        std::cout<<"Our matrix before :"<<std::endl<<mat27;
        SquareMat prefixminus=--mat27;
        std::cout<<"\nThe matrix with Prefix -- (--mat27) :"<< std::endl<<prefixminus;
        std::cout<<"\nOur matrix now: "<<std::endl<<mat27;

        //Postfix:
        std::cout<<"\n*****Postfix*****"<<std::endl;
        std::cout<<"\n*****Postfix(++)*****"<<std::endl;

        SquareMat mat28(2);

        mat28[0]=1;
        mat28[1]=2;
        mat28[2]=3;
        mat28[3]=4;

        std::cout<<"Our matrix before :"<<std::endl<<mat28;
        SquareMat postfixplus=mat28++;
        std::cout<<"\nThe matrix with Postfix ++ (mat28++) :"<< std::endl<<postfixplus;
        std::cout<<"\nOur matrix now: "<<std::endl<<mat28;

        SquareMat mat29(2);

        mat29[0]=1;
        mat29[1]=2;
        mat29[2]=3;
        mat29[3]=4;

        std::cout<<"\n*****Postfix(--)*****"<<std::endl;
        std::cout<<"Our matrix before :"<<std::endl<<mat29;
        SquareMat postfixminus=mat29--;
        std::cout<<"\nThe matrix with Postfix -- (mat29--) :"<< std::endl<<postfixminus;
        std::cout<<"\nOur matrix now: "<<std::endl<<mat29;

        std::cout<<"\n*****(==/!=)*****"<<std::endl;
        SquareMat mat30(2);
        //Total sum of 41:
        mat30[0]=2;
        mat30[1]=21;
        mat30[2]=8;
        mat30[3]=10;

        SquareMat mat31(2);
        //Total sum of 41:
        mat31[0]=10;
        mat31[1]=9;
        mat31[2]=2;
        mat31[3]=20;

        SquareMat mat32(2);
        //Total sum of 33:
        mat32[0]=10;
        mat32[1]=11;
        mat32[2]=2;
        mat32[3]=10;

        std::cout<<"\nOur first matrix is: "<<std::endl<<mat30;
        std::cout<<"\nOur second matrix is: "<<std::endl<<mat31;
        std::cout<<"\nOur third matrix is: "<<std::endl<<mat32;

        std::cout<<std::boolalpha;

        std::cout<<"first==second:"<<(mat30==mat31)<<std::endl; //True
        std::cout<<"first==third:"<<(mat30==mat32)<<std::endl; //False
        std::cout<<"first!=third:"<<(mat30!=mat32)<<std::endl; //True

        std::cout<<"\n*****(>,<,>=,<=)*****"<<std::endl;
        std::cout<<"mat32<mat31: "<<(mat32<mat31)<<std::endl; //True.
        std::cout<<"mat32>mat30: "<<(mat32>mat30)<<std::endl; //False.
        std::cout<<"mat30<=mat31: "<<(mat30<=mat31)<<std::endl; //True.
        std::cout<<"mat32>=mat31: "<<(mat32>=mat31)<<std::endl; //False.


        std::cout<<"\n*****Operator Det()*****"<<std::endl;
        SquareMat mat33(3);
        mat33[0]=1;
        mat33[1]=0;
        mat33[2]=2;
        mat33[3]=4;
        mat33[4]=1;
        mat33[5]=8;
        mat33[6]=2;
        mat33[7]=0;
        mat33[8]=3;

        std::cout<<"\nOur Matrix(3X3) is :"<<std::endl<<mat33;
        double det=!mat33; 
        std::cout<<"\nThe determinant of our matrix is : "<<det<<std::endl;

        std::cout<<"\n*****Operator(+=):mat=mat+other*****"<<std::endl;
        SquareMat mat34(2);
        SquareMat mat35(2);

        mat34[0]=1;
        mat34[1]=2;
        mat34[2]=3;
        mat34[3]=4;

        mat35[0]=5;
        mat35[1]=6;
        mat35[2]=7;
        mat35[3]=8;

        std::cout<<"\nOur matrix is : "<<std::endl<<mat34;
        std::cout<<"\nOur other matrix is : "<<std::endl<<mat35;

        mat34+=mat35;

        std::cout<<"\nAfter we using the operator +=, our matrix(the first one,not the other) is: "<<std::endl<<mat34;

        std::cout<<"\n*****Operator(-=):mat=mat-other*****"<<std::endl;
        SquareMat mat36(2);
        SquareMat mat37(2);

        mat36[0]=1;
        mat36[1]=2;
        mat36[2]=3;
        mat36[3]=4;

        mat37[0]=5;
        mat37[1]=6;
        mat37[2]=7;
        mat37[3]=8;

        std::cout<<"\nOur matrix is : "<<std::endl<<mat36;
        std::cout<<"\nOur other matrix is : "<<std::endl<<mat37;

        mat36-=mat37;

        std::cout<<"\nAfter we using the operator -=, our matrix(the first one,not the other) is: "<<std::endl<<mat36;

        std::cout<<"\n*****Operator(/=):mat=mat/scalar*****"<<std::endl;
        SquareMat mat38(2);
        double scalar100=2;

        mat38[0]=1;
        mat38[1]=2;
        mat38[2]=3;
        mat38[3]=4;

        

        std::cout<<"\nOur matrix is : "<<std::endl<<mat38;
        std::cout<<"\nOur  scalar is : "<<std::endl<<scalar100;

        mat38/=scalar100;

        std::cout<<"\nAfter we using the operator /=, our matrix(the first one,not the other) is: "<<std::endl<<mat38;

        std::cout<<"\n*****Operator(*=):mat=mat*other*****"<<std::endl;
        SquareMat mat40(2);
        SquareMat mat41(2);

        mat40[0]=1;
        mat40[1]=2;
        mat40[2]=3;
        mat40[3]=4;

        mat41[0]=5;
        mat41[1]=6;
        mat41[2]=7;
        mat41[3]=8;

        std::cout<<"\nOur matrix is : "<<std::endl<<mat40;
        std::cout<<"\nOur other matrix is : "<<std::endl<<mat41;

        mat40*=mat41;

        std::cout<<"\nAfter we using the operator *=, our matrix(the first one,not the other) is: "<<std::endl<<mat40;

        std::cout<<"\n*****Operator(*=):mat=mat*scalar*****"<<std::endl;
        SquareMat mat42(2);
        double scalarMul=2.5;

        mat42[0]=1;
        mat42[1]=2;
        mat42[2]=3;
        mat42[3]=4;

        std::cout<<"\nOur matrix is : "<<std::endl<<mat42;
        mat42*=scalarMul;
        std::cout<<"\nAfter we using the operator *=,with scalar 2.5---> our matrix is: "<<std::endl<<mat42;


        std::cout<<"\n*****Operator(%=):mat=mat (%) other*****"<<std::endl;
        SquareMat mat43(2);
        SquareMat mat44(2);

        mat43[0]=1;
        mat43[1]=2;
        mat43[2]=3;
        mat43[3]=4;

        mat44[0]=5;
        mat44[1]=6;
        mat44[2]=7;
        mat44[3]=8;

        std::cout<<"\nOur matrix is : "<<std::endl<<mat43;
        std::cout<<"\nOur other matrix is : "<<std::endl<<mat44;

        mat43%=mat44;

        std::cout<<"\nAfter we using the operator %=, our matrix(the first one,not the other) is: "<<std::endl<<mat43;

        std::cout<<"\n*****Operator(%=):mat=mat%scalar*****"<<std::endl;
        SquareMat mat45(2);
        int scalarMod=3;

        mat45[0]=1;
        mat45[1]=2;
        mat45[2]=3;
        mat45[3]=4;

        std::cout<<"\nOur matrix is : "<<std::endl<<mat45;
        mat45%=scalarMod;
        std::cout<<"\nAfter we using the operator %=,with scalar 3---> our matrix is: "<<std::endl<<mat45;

        //Checking for operator << :
        std::cout<<"\n*****Operator(<<):print our matrix*****"<<std::endl;
        SquareMat mat500(2);
        mat500[0]=1;
        mat500[1]=2;
        mat500[2]=3;
        mat500[3]=4;

        std::cout<<"Our matrix is: "<<std::endl<<mat500;

    }
    //Catch errors:
    catch(const std::exception& e){

        std::cerr<<"Error:"<<e.what()<<std::endl;
    }


    return 0;




}
