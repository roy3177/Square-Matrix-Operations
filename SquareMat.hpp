//roymeoded2512@gmail.com

#ifndef SQUARE_MAT_H
#define SQUARE_MAT_H

#include <iostream>


namespace mat{

    class SquareMat{

        private:

            /*
            How our matrix is build:
            1. size - the number of rows/columns in our square matrix.
            2. data - pointer to a dynamically allocated array that holds the elements of the matrix
            (the matrix is represented as a 1D array, where the element at
             index i*n + j corresponds to the element in the i-th row and j-th column of the matrix).
            */

            int size; 
            double* data;

        public:

            /*
            Constructors:
            1.Constructor with size parameter
            2.Copy constructor->creates a new matrix that is a copy of the other matrix(deep copy).
            3.Destructor-->frees the dynamically allocated memory for the matrix.
            */

            SquareMat(int n);
            SquareMat(const SquareMat& other); 
            ~SquareMat(); 

            /*
            Assignment operators:
            1.Copy assignment operator: assigns the contents of one matrix to another.
            2.Move assignment operator: transfers the contents of one matrix to another without copying
            all the data (only moving the ownership).
            Using && to indicate that the other matrix is an rvalue reference:
            Temporary objects can be transferred resources without copying.
            */

            SquareMat& operator=(const SquareMat& other);
            SquareMat& operator=(SquareMat&& other) noexcept;

           /*
           (+) (-) (*):
            First const-does not change the other matrix, second const-does not change the current matrix:
           */

            SquareMat operator+(const SquareMat& other)const;
            SquareMat operator-(const SquareMat& other)const;
            SquareMat operator*(const SquareMat& other)const;

            // Scalar multiplication: multiplies each element of the matrix by a scalar value: mat * scalar
            SquareMat operator*(double scalar)const;

            //Modulo operator(%)-->returns a new matrix, which each element is a result of the modulo operation:
            SquareMat operator%(int scalar)const;

            //Return a new matrix, which each element is a result of the product of corresponding elements:
            SquareMat operator%(const SquareMat& other)const;

            //Power operator(^)-->raises our matrix with power by himself, for example: (mat^2)=mat*mat
            SquareMat operator^(int power)const;


            /*
            Increment and Decrement operators:
            1.Prefix increment operator (++): increases each element of the matrix by 1
            and returns the updated matrix.
            2.Postfix increment operator (++): increases each element of the matrix by 1 and
            returns the original matrix before the increment.
            3.Prefix decrement operator (--): decreases each element of the matrix by 1 and
            returns the updated matrix.
            4.Postfix decrement operator (--): decreases each element of the matrix by 1 and
            returns the original matrix before the decrement.
            */

            SquareMat& operator++(); 
            SquareMat operator++(int); 
            SquareMat& operator--();
            SquareMat operator--(int); 

            /*
            Indexing operator([]):
            1. Non-const version: allows reading and changing of the matrix elements.
            2. Const version: allows read-only access to the matrix elements.
            This operator provides access to the elements of the matrix using a single index,
            calculated as i*n + j, where i is the row index and j is the column index.
            */

            double& operator[](int index);
            const double& operator[](int index) const; 

            //Compares matrices for equality(and inequality):
            bool operator==(const SquareMat& other) const;
            bool operator!=(const SquareMat& other) const;

            //Transpose operator (~)-->returns a new matrix that is the transpose of the current matrix:
            SquareMat operator~()const; 

            //Print the matrix in readable format:
            friend std::ostream& operator<<(std::ostream& os,const SquareMat& mat);

            //Access the size of the matrix:
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

            /*
            Determinant operator (!)-->returns the determinant of the matrix:
            Using recursive method to calculate the determinant of a square matrix.
            */

            double operator!()const;
            double helperDet(const double* mat,int n)const; 

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

    // Scalar multiplication from the left: scalar * mat
    SquareMat operator*(double scalar,const SquareMat& mat); 


}
#endif




