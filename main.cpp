//roymeoded2512@gmail.com

#include "SquareMat.hpp"
#include <iostream>

using namespace std;
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
        cout<<"The size of the matrix is : "<<matrix.getSize()<<"x"<<matrix.getSize()<<endl;

        //Print the matrix, using operator<<:
        cout<<"Our matrix's elements:"<<endl;
        cout<<matrix<<endl;

        //Access to the operator []--> reading and writing:
        cout<<"\n**********Operator([])**********\n"<<endl;

        cout<<"\nOur matrix's elements:"<<endl;
        cout<<matrix<<endl;
        cout << "Accessing the element matrix[4] before changing: "<<matrix[4]<<endl;
        matrix[4]=20; //We change now the element
        cout << "Accessing the element matrix[4] after changing: "<<matrix[4]<<endl;

        cout<<"Our matrix after we change the element matrix[4]:"<<endl;
        cout<<matrix<<endl;

        cout<<"\n**********Operator(+)**********\n"<<endl;

        //Now lets show the operator+(between two matrices):
        SquareMat mat1(3);
        SquareMat mat2(3);

        for(int i=0;i<9;i++){
            mat1[i]=i+1; //1,2,3,4,5,6,7,8,9
            mat2[i]=i*2; //0,2,4,6,8,10,12,14,16
        }
        SquareMat mat3=mat1+mat2;

        cout<<"Matrix mat1:"<<endl<<mat1;
        cout<<"\nMatrix mat2:"<<endl<<mat2;
        cout<<"\nMatrix mat3(mat3=mat1+mat2):"<<endl<<mat3;

        cout<<"\n**********Operator(-)**********\n"<<endl;

        //Now lets show the operator+(between two matrices):
        SquareMat mat4(3);
        SquareMat mat5(3);

        for(int i=0;i<9;i++){
            mat4[i]=i+2; //2,3,4,5,6,7,8,9,10
            mat5[i]=i; //0,1,2,3,4,5,6,7,8
        }
        SquareMat mat6=mat4-mat5;

        cout<<"Matrix mat4:"<<endl<<mat4;
        cout<<"\nMatrix mat5:"<<endl<<mat5;
        cout<<"\nMatrix mat6(mat6=mat4-mat5):"<<endl<<mat6;

        cout<<"\n**********Operator(*)**********\n"<<endl;

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

        cout<<"mat7: "<<endl<<mat7;
        cout<<"mat8: "<<endl<<mat8;
        cout<<"mat9(=mat7*mat8): "<<endl<<mat9;

        cout<<"\n**********Unary (-matrix)**********\n"<<endl;

        SquareMat mat11(2);

        mat11[0]=1;
        mat11[1]=2;
        mat11[2]=-3;
        mat11[3]=4;

        SquareMat unaryMat=-mat11;

        cout<<"Our initial matrix is :"<<endl<<mat11;
        cout<<"Our negated matrix is (-matrix): "<<endl<<unaryMat;

        cout<<"\n**********(matrix*scalar)//(scalar*matrix)**********\n"<<endl;

        SquareMat mat12(2);

        mat12[0]=1;
        mat12[1]=2;
        mat12[2]=3;
        mat12[3]=4;

        SquareMat mat13=mat12*2;
        SquareMat mat14=3*mat12;

        cout<<"Our initial matrix is : "<<endl<<mat12;
        cout<<"\nOur matrix after we multiply with scalar 2(mat12*scalar): "<<endl<<mat13;
        cout<<"\nOur matrix after we multiply with scalar 3(scalar*mat12): "<<endl<<mat14;

        
        cout<<"\n**********(matrix[i]/scalar)**********\n"<<endl;
        SquareMat mat15(2);

        mat15[0]=11;
        mat15[1]=12;
        mat15[2]=1;
        mat15[3]=33;

        double scalar=3;
        SquareMat mat16=mat15/scalar;

        cout<<"Our initial matrix is :"<<endl<<mat15;
        cout<<"\nNow after we divide each element with 3, the matrix is: "<<endl<<mat16;

         cout<<"\n**********(result[i]=mat[i]*other[i])**********\n"<<endl;
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

        cout<<"Our first matrix is : "<<endl<<mat17;
        cout<<"\nOur other matrix is: "<<endl<<mat18;
        cout<<"\nOur matrix after we multiply each element between mat and other mat: "<<endl<<mat19;

        cout<<"\n**********(result[i]=mat[i] (%) scalar)**********\n"<<endl;
        SquareMat mat20(2);

        mat20[0]=10.5;
        mat20[1]=21.3;
        mat20[2]=31.7;
        mat20[3]=41.1;

        int scalar2=7; 

        SquareMat mat21=mat20%scalar2;

        cout<<"Our initial matrix is : "<<endl<<mat20;
        cout<<"Now our matrix after each element we do modulo--->mat21[i]==mat[20]%7: "<<endl<<mat21;

        cout<<"\n**********Operator power (^)**********\n"<<endl;

        SquareMat mat22(2);

        mat22[0]=1;
        mat22[1]=2;
        mat22[2]=3;
        mat22[3]=4;

        int power=2;

        SquareMat mat23=mat22^power;
        cout<<"Our initial matrix is : "<<endl<<mat22;
        cout<<"Now our matrix after we raises the matrix with power 2-->(mat)^2: "<<endl<<mat23;

        cout<<"\n**********Operator transport (~)**********\n"<<endl;

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

        cout<<"Our initial matrix is : "<<endl<<mat24;
        cout<<"Now our matrix after we transport it ((mat24)^T): "<<endl<<mat25;

        cout<<"\n**********Prefix(++/--) and Postfix(++/--)**********\n"<<endl;
        


        //Prefix:
        cout<<"*****Prefix*****"<<endl;
        cout<<"\n*****Prefix(++)*****"<<endl;
        SquareMat mat26(2);

        mat26[0]=1;
        mat26[1]=2;
        mat26[2]=3;
        mat26[3]=4;

        cout<<"Our matrix before :"<<endl<<mat26;
        SquareMat prefixplus=++mat26;
        cout<<"\nThe matrix with Prefix ++ (++mat26) :"<< endl<<prefixplus;
        cout<<"\nOur matrix now: "<<endl<<mat26;
        
        SquareMat mat27(2);

        mat27[0]=1;
        mat27[1]=2;
        mat27[2]=3;
        mat27[3]=4;

        cout<<"\n*****Prefix(--)*****"<<endl;
        cout<<"Our matrix before :"<<endl<<mat27;
        SquareMat prefixminus=--mat27;
        cout<<"\nThe matrix with Prefix -- (--mat27) :"<< endl<<prefixminus;
        cout<<"\nOur matrix now: "<<endl<<mat27;

        //Postfix:
        cout<<"\n*****Postfix*****"<<endl;
        cout<<"\n*****Postfix(++)*****"<<endl;

        SquareMat mat28(2);

        mat28[0]=1;
        mat28[1]=2;
        mat28[2]=3;
        mat28[3]=4;
        
        cout<<"Our matrix before :"<<endl<<mat28;
        SquareMat postfixplus=mat28++;
        cout<<"\nThe matrix with Postfix ++ (mat28++) :"<< endl<<postfixplus;
        cout<<"\nOur matrix now: "<<endl<<mat28;

        SquareMat mat29(2);

        mat29[0]=1;
        mat29[1]=2;
        mat29[2]=3;
        mat29[3]=4;

        cout<<"\n*****Postfix(--)*****"<<endl;
        cout<<"Our matrix before :"<<endl<<mat29;
        SquareMat postfixminus=mat29--;
        cout<<"\nThe matrix with Postfix -- (mat29--) :"<< endl<<postfixminus;
        cout<<"\nOur matrix now: "<<endl<<mat29;

        cout<<"\n*****(==/!=)*****"<<endl;
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

        cout<<"\nOur first matrix is: "<<endl<<mat30;
        cout<<"\nOur second matrix is: "<<endl<<mat31;
        cout<<"\nOur third matrix is: "<<endl<<mat32;

        cout<<boolalpha;

        cout<<"first==second:"<<(mat30==mat31)<<endl; //True
        cout<<"first==third:"<<(mat30==mat32)<<endl; //False
        cout<<"first!=third:"<<(mat30!=mat32)<<endl; //True

        cout<<"\n*****(>,<,>=,<=)*****"<<endl;
        cout<<"mat32<mat31: "<<(mat32<mat31)<<endl; //True.
        cout<<"mat32>mat30: "<<(mat32>mat30)<<endl; //False.
        cout<<"mat30<=mat31: "<<(mat30<=mat31)<<endl; //True.
        cout<<"mat32>=mat31: "<<(mat32>=mat31)<<endl; //False.


        cout<<"\n*****Operator Det()*****"<<endl;
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

        cout<<"\nOur Matrix(3X3) is :"<<endl<<mat33;
        double det=!mat33; 
        cout<<"\nThe determinant of our matrix is : "<<det<<endl;

        cout<<"\n*****Operator(+=):mat=mat+other*****"<<endl;
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

        cout<<"\nOur matrix is : "<<endl<<mat34;
        cout<<"\nOur other matrix is : "<<endl<<mat35;

        mat34+=mat35;

        cout<<"\nAfter we using the operator +=, our matrix(the first one,not the other) is: "<<endl<<mat34;

        cout<<"\n*****Operator(-=):mat=mat-other*****"<<endl;
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

        cout<<"\nOur matrix is : "<<endl<<mat36;
        cout<<"\nOur other matrix is : "<<endl<<mat37;

        mat36-=mat37;

        cout<<"\nAfter we using the operator -=, our matrix(the first one,not the other) is: "<<endl<<mat36;
        
        cout<<"\n*****Operator(/=):mat=mat/scalar*****"<<endl;
        SquareMat mat38(2);
        double scalar100=2;

        mat38[0]=1;
        mat38[1]=2;
        mat38[2]=3;
        mat38[3]=4;

        

        cout<<"\nOur matrix is : "<<endl<<mat38;
        cout<<"\nOur  scalar is : "<<endl<<scalar100;

        mat38/=scalar100;

        cout<<"\nAfter we using the operator /=, our matrix(the first one,not the other) is: "<<endl<<mat38;
        
        cout<<"\n*****Operator(*=):mat=mat*other*****"<<endl;
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

        cout<<"\nOur matrix is : "<<endl<<mat40;
        cout<<"\nOur other matrix is : "<<endl<<mat41;

        mat40*=mat41;

        cout<<"\nAfter we using the operator *=, our matrix(the first one,not the other) is: "<<endl<<mat40;
        
        cout<<"\n*****Operator(*=):mat=mat*scalar*****"<<endl;
        SquareMat mat42(2);
        double scalarMul=2.5;

        mat42[0]=1;
        mat42[1]=2;
        mat42[2]=3;
        mat42[3]=4;

        cout<<"\nOur matrix is : "<<endl<<mat42;
        mat42*=scalarMul;
        cout<<"\nAfter we using the operator *=,with scalar 2.5---> our matrix is: "<<endl<<mat42;


        cout<<"\n*****Operator(%=):mat=mat (%) other*****"<<endl;
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

        cout<<"\nOur matrix is : "<<endl<<mat43;
        cout<<"\nOur other matrix is : "<<endl<<mat44;

        mat43%=mat44;

        cout<<"\nAfter we using the operator %=, our matrix(the first one,not the other) is: "<<endl<<mat43;
        
        cout<<"\n*****Operator(%=):mat=mat%scalar*****"<<endl;
        SquareMat mat45(2);
        int scalarMod=3;

        mat45[0]=1;
        mat45[1]=2;
        mat45[2]=3;
        mat45[3]=4;

        cout<<"\nOur matrix is : "<<endl<<mat45;
        mat45%=scalarMod;
        cout<<"\nAfter we using the operator %=,with scalar 3---> our matrix is: "<<endl<<mat45;

    

        //Checking for operator << :
        cout<<"\n*****Operator(<<):print our matrix*****"<<endl;
        SquareMat mat500(2);
        mat500[0]=1;
        mat500[1]=2;
        mat500[2]=3;
        mat500[3]=4;

        cout<<"Our matrix is: "<<endl<<mat500;

    }
    //Catch errors:
    catch(const exception& e){

        cerr<<"Error:"<<e.what()<<endl;
    }


    return 0;




}
