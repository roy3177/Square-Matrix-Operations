# Square Matrix Operations

## Project Overview

This project implements a **SquareMat** class  in C++ for square matrices,supporting a wide range of arithmetic,comparison,indexing,
unary operatos, and more.

## Supported Operators

**(-),(+):** Add or subtract two matrices element-wise.

**(+=),(-=):** Compound addition and subtruction.

**(*):** Multiply two matrices (=matrix multiplication).

**(*=):** Compound multiplication (2 ways: matrix1 = matrix1 * matrix2 , matrix1 = matrix1 * scalar ).

**(/):** Element-wise division between matrix and scalar(division by zero protection).

**(/=):** Compound division.

**(%):** (First) Element-wise modulo between matrix and scalar(division by zero protection).

**(%=):** Compound modulo (2 ways: matrix1 = matrix1 % matrix2 , matrix1 = matrix1 % scalar ).

**(%):** (Second) Multiplies each element in one matrix by the corresponding element in the second matrix.

**(==),(!=):** Checking if 2 matrices are equael or not, base by the sum of the elements.

**(>),(<),(<=),(>=):** Compares the total sum of all matrix's elements.

**(!):** Calculates the matrix's determinant.

**(++),(--):** Increament/Decreaments every element in the matrix (in postfix and profix way).

**-removeEdge:** Remove connection between two vertices.

**(~):** Transposes the matrix.

**([]):** Indexing support for accessing and modifying individual elements .


This project includes input validation,exception handling,and extensive unit tests.

## Installation and Usage

**Compilation:** To compile-using the provided MakeFile :
```bash 
make
```
**Running the Main Program:** To execute demos and examples:
``` bash
make Main
```
**Running Tets:** To run tests, using **doctest**:
```bash
make test
```
**Memory Check(Valgrind):** To check for memory leaks:
```bash
make valgrind
```
**Cleaning Files:** To remove compile files:
```bash
make clean
```


## Project Structure

```plaintext
SQUAREMAT
├── SquareMat.cpp
├── SquareMat.hpp
├── tests.cpp  
├── doctest.h
├── main.cpp
├── makefile
└── README.md
```

## Usage Examples

In the file **main.cpp** you can find usage examples demonstrating the behavior of the different operators.  
Each example clearly shows the matrix values before and after execution, highlighting the effect of the operation.

## Testing 

Comprehensive unit tests, using **doctest.h**, ensure full coverage and corretness.

## Author

**Roy Meoded** (roymeoded2512@gmail.com)

