//roymeoded2512@gmail.com

#ifndef SQUARE_MAT_H
#define SQUARE_MAT_H

#include <iostream>

using namespace std;

namespace mat{

    class SquareMat{

        private:

            //How our matrix is build:
            int size; //Our matrix size (nxn), its the number of the rows/columns.
            double* data; //Pointer of our matrix(=2D array).

            void copyMatrix(const SquareMat& other); //Helper function for copy matrix from other matrix.
            void freeMatrix(); //Helper function for free the data.

        public:

            //Constructors:
            SquareMat(); //Default constructor
            SquareMat(int n);
            SquareMat(const SquareMat& other); //Copy constructor
            SquareMat(SquareMat&& other) noexcept ; //Move constructor
            ~SquareMat(); //Destructor

            //Regular assignment and move assignment operators:
            SquareMat& operator=(const SquareMat& other);
            SquareMat& operator=(SquareMat&& other) noexcept;

            // (+) (-) (*):
            SquareMat operator+(const SquareMat& other)const;
            SquareMat operator-(const SquareMat& other)const;
            SquareMat operator*(const SquareMat& other)const;

            // (* with scalar):
            SquareMat operator*(double scalar)const;
            friend SquareMat operator*(double scalar,const SquareMat& mat); //To define the matrix from the left


            //Returns a matrix, where each element is the result of: (element % scalar):
            SquareMat operator%(int scalar)const;

            //Return a new matrix, which each element is a result of the product of corresponding elements:
            SquareMat operator%(const SquareMat& other)const;

            //Power operator(^)-->raises our matrix with power by himself:(mat^2)=mat*mat
            SquareMat operator^(int power)const;


            //(element++,element--):
            SquareMat& operator++(); //Prefix
            SquareMat operator++(int); //Postfix
            SquareMat& operator--(); //Prefix
            SquareMat operator--(int); //Postfix

            //Access to row/column or element by index:
            SquareMat operator()(int index) const;
            double& operator[](int index);
            const double& operator[](int index) const;

            //Compares matrices for equality(and inequality):
            bool operator==(const SquareMat& other) const;
            bool operator!=(const SquareMat& other) const;

            SquareMat operator~()const; //SquareMat^T

            //Print the matrix in readable format:
            friend std::ostream& operator<<(std::ostream& os,const SquareMat& mat);

            int getSize()const;

            //Declares an unary operator(-)-->from negative to positive/from positive to negative:
            SquareMat operator-() const;

            //Operator divide (/) all the elements with scalar:
            SquareMat operator/(double scalar) const;

            //Operator (>,<,=>,<=):
            bool operator<(const SquareMat& other)const;
            bool operator>(const SquareMat& other)const;
            bool operator>=(const SquareMat& other)const;
            bool operator<=(const SquareMat& other)const;

            //Operator Determinant (!)--->return the derminant of the matrix:
            double operator!()const;
            double helperDet(const double* mat,int n)const; //Our helper method.

            //Operators +=,-=,*=,/=.%=:
            SquareMat& operator+=(const SquareMat& other);
            SquareMat& operator-=(const SquareMat& other);
            SquareMat& operator/=(double scalar);
            SquareMat& operator*=(const SquareMat& other);
            SquareMat& operator*=(double scalar);
            SquareMat& operator%=(const SquareMat& other);
            SquareMat& operator%=(int scalar);

            //Print our matrix:
            friend std::ostream& operator<<(std::ostream& os, const SquareMat& mat);


    };

}
#endif




