//roymeoded2512@gmail.com

#include "SquareMat.hpp"
#include <iostream>
#include <cmath>



namespace mat{

    //Return the size of the matrix:
    int SquareMat::getSize() const{
        return this->size;
    }

    //Constructor(int n)-->creates a square matrix of size n*n:
    SquareMat::SquareMat(int n){

        //Check if the size is valid:
        if(n<=0){
            throw std::invalid_argument("Our matrix size must be positive!");
        }
    
        this->size=n;
        this->data=new double[n*n]; //Allocate array of n*n elements.

        //Initialize all elements to 0:
        for(int i=0;i<n*n;i++){
            this->data[i]=0; 
        }
    }


    //Copy constructor:
    SquareMat::SquareMat(const SquareMat& other){
        size=other.size;
        data=new double[size*size];
        for(int i=0;i<size*size;i++){
            data[i]=other.data[i];
        }
    }

    //Copy assignment:
    SquareMat& SquareMat::operator=(const SquareMat& other){
        //Checking for self-assignment in copy:
        if(this==&other){
            return *this;
        }
        delete[] data; //Free old memory to avoid memory leak.
        size=other.size;
        data=new double[size*size]; //Allocate new memory for the matrix.
        for(int i=0;i<size*size;i++){
            data[i]=other.data[i];
        }
        return *this; //Return reference to the current object.
    }

    //Move assignment:
    SquareMat& SquareMat::operator=(SquareMat&& other)noexcept{

        //Checking for self-assignment in move(a=std::move(a)):
        if(this==&other){
            return *this;
        }
        delete[] data; //Free the old matrix data.

        //Take ownership of other's size and data:
        size=other.size;
        data=other.data;
        other.data=nullptr; //Set other's data to nullptr to avoid double deletion.
        other.size=0;
        return *this;

    }

    //Operator [] -->access to the elements of the matrix using a single index:
    double& SquareMat::operator[](int index){
        //Check if the index is valid:
        if(index<0 || index>=size*size){
            throw std::out_of_range("Index out of bounds in SquareMat::operator[]");
        }    
        return data[index];
    }

    //Const version of operator [] -->enables only reading(const):
    const double& SquareMat::operator[](int index) const{
        //Check if the index is valid:
        if(index<0 || index>=size*size){
            throw std::out_of_range("Index out of bounds in SquareMat::operator[]");
        }
        return data[index];
    }

    //Destructor (~):
    SquareMat::~SquareMat(){
        delete[] data;
    }

    //This is a method for operator+ (mat1+mat2):
    SquareMat SquareMat:: operator+(const SquareMat& other)const{

        //Our two matrices should have the same size:
        if(this->size!=other.size){
            throw std::invalid_argument("We cant add two matrices with different size!");
        }

        SquareMat ans(this->size); // mat1+mat2=ans

        for(int i=0;i<size*size;i++){
            ans[i]=this->data[i]+other[i];
        }
        return ans;
    }

    //This is a method for operator- (mat1-mat2):
    SquareMat SquareMat:: operator-(const SquareMat& other)const{

        //Our two matrices should have the same size:
        if(this->size!=other.size){
            throw std::invalid_argument("We cant subtract two matrices with different size!");
        }

        SquareMat ans(this->size); // mat1-mat2=ans

        for(int i=0;i<size*size;i++){
            ans[i]=this->data[i]-other[i];
        }
        return ans;
    }

    //This is a method for operator* (mat1*mat2):
    SquareMat SquareMat:: operator*(const SquareMat& other)const{

        //Our two matrices should have the same size:
        if(this->size!=other.size){
            throw std::invalid_argument("We cant multiply two matrices with different size!");
        }

        int n=this->size;

        SquareMat ans(n); //ans=mat1*mat2

        for(int i=0;i<n;i++){ //---->Loop over the rows of the current matrix(this matrix).
            for(int j=0;j<n;j++){  //---->Loop over the columns of the other matrix(other matrix).
                double sum=0; //temp variable for the sum of the cell (i,j).
                for(int k=0;k<n;k++){
                    sum=sum+(*this)[i*n+k]*other[k*n+j];
                }
                ans[i*n+j]=sum;
            } 
        }
        return ans;
    }

    //This is a method that returns a new matrix,with each element negated(from negative to positive/from positive to negative):
    SquareMat SquareMat::operator-()const{

        //We create new matrix with the same size:
        SquareMat ans(this->size);

        for(int i=0;i<size*size;i++){
            ans[i]=-this->data[i]; //ans[i]=-ans[i].
        }

        return ans; 
    }

    //Multiply our matrix with scalar-->matrix*scalar:
    SquareMat SquareMat::operator*(double scalar)const{
        //We create new matrix with the same size:
        SquareMat ans(this->size);

        for(int i=0;i<size*size;i++){
            ans[i]=this->data[i]*scalar; //for every element in our matrix, multiply with scalar.
        }
        
        return ans;
    }

   
    //Multiply our matrix with scalar-->scalar*matrix:
        SquareMat  operator*(double scalar,const SquareMat& mat){
            SquareMat result(mat.getSize());
                for (int i = 0; i < mat.getSize() * mat.getSize(); i++) {
                    result[i] = scalar * mat[i]; 
                }
            return result;
        }
    

    //Operator(/)--->divide all the elements of the matrix with scalar:
    SquareMat SquareMat::operator/(double scalar)const{

        //Make sure that we dont divide the elements with zero:
        if(scalar==0){
            throw std::invalid_argument("We cannot divide with zero!");
        }

        SquareMat ans(this->size);

        for(int i=0;i<size*size;i++){
            ans[i]=this->data[i]/scalar; //ans[i]=ans[i]/scalar
        }
        
        return ans;
    }

    //Operator (%)--> for each element between mat1,mat2--->return mat1[i]*mat2[i] :
    SquareMat SquareMat::operator%(const SquareMat& other)const{

        //Our two matrices should have the same size:
        if(this->size!=other.size){
            throw std::invalid_argument("We cant multiply two matrices with different size!");
        }

        SquareMat ans(this->size); //Our result matrix.

        for(int i=0;i<size*size;i++){
            ans[i]=this->data[i]*other[i];
        }

        return ans;
    }

    //Operator  modulo (%)---->return each element modulo with scalar:
    SquareMat SquareMat::operator%(int scalar )const{
        //Without scalar 0--->we dont change nothing:
        if(scalar==0){
            throw std::invalid_argument("Modulo 0 is not allowed!");
        }
        
        SquareMat ans(this->size);

        for(int i=0;i<size*size;i++){
            ans[i]=std::fmod(this->data[i],scalar); //ans[i]=mat[i]%scalar
        }
        return ans;

    }

    //Operator power(^)-->raises the matrix to an integer power,using repeated multipication:
    SquareMat SquareMat::operator^(int power)const{

        //Our power cannot be negative:
        if(power<0){
            throw std::invalid_argument("Our power cannot be negative!!!!");
        }
        
        //We can't power an empty matrix:
        if(this->size==0){
            throw std::logic_error("Our matrix cannot be empty!");
        }

        //We create matrix with the same size-->will be the identity matrix:
        SquareMat ans(this->size);

        //Put 1 in our identity matrix-->to build it:
        for(int i=0;i<size;i++){
            ans[i*size+i]=1;
        }

        SquareMat base=*this; //Copy our original matrix for further multiplication.

        while(power>0){
            //If the power is odd-->we multiply the identity matrix with the base:
            if(power%2==1){
                ans=ans*base;
            }
            base=base*base; //Square the base.
            power=power/2; //Every level we divide our power with 2.
        }

        return ans;
    }

    //Transpose matrix--->mat[i][j]-->mat[j][i]:
    SquareMat SquareMat::operator~()const{

        SquareMat trans(this->size); //This is our transport matrix.

        for(int i=0;i<size;i++){
            for(int j=0;j<size;j++){
                trans[j*size+i]=this->data[i*size+j]; //trans[i][j]=mat[j][i]
            }
        }

        return trans;

    }

    //Prefix (++) -->increase each matrix element by 1:
    SquareMat& SquareMat::operator++(){
        for(int i=0;i<size*size;i++){
            data[i]=data[i]+1;
        }
        return *this;
    }

    //Prefix (--) -->decrease each matrix element by 1:
    SquareMat& SquareMat::operator--(){
        for(int i=0;i<size*size;i++){
            data[i]=data[i]-1;
        }
        return *this;
    }

    //Postfix (++)-->Stores a copy, increaments the current object, returns the old state:
    SquareMat SquareMat::operator++(int){
        SquareMat temp=*this; //Save the current state.
        ++(*this); //Use prefix for increament
        return temp; //Return the old state.
    }

    //Postfix (--)-->Stores a copy, decrease the current object, returns the old state:
    SquareMat SquareMat::operator--(int){
        SquareMat temp=*this; //Save the current state.
        --(*this); //Use prefix for decreament
        return temp; //Return the old state.
    }

    //Operator ==-->mat1==mat2:return true if the sum all of the elements between the two matrices is equal:
    bool SquareMat::operator==(const SquareMat& other)const{
        if(this->size!=other.size){
            throw std::invalid_argument("We cannot check that operator if the sizes are different");
        }
        double sum1=0; //The initial sum of this matrix.
        double sum2=0;//The initial sum of other matrix.
        
        for(int i=0;i<size*size;i++){
            sum1=sum1+this->data[i];
            sum2=sum2+other.data[i]; 
        }

        return sum1==sum2;

    }

    //Operator !=-->mat1!=mat2:return true if the sum all of the elements between the two matrices is not equal:
    bool SquareMat::operator!=(const SquareMat& other)const{
        return !(*this==other);
    }

    //Operator >:mat1>mat2-->checking the sum between the all of the elements of the two matrices:
    bool SquareMat::operator>(const SquareMat& other)const{
        if(this->size!=other.size){
            throw std::invalid_argument("We cannot check that operator if the sizes are different");
        }
        double sum1=0;//The initial sum of this matrix.
        double sum2=0;//The initial sum of other matrix.

        for(int i=0;i<size*size;i++){
            sum1=sum1+this->data[i];
            sum2=sum2+other.data[i]; 
        }
        return sum1>sum2;

    }

    //Operator < : mat1<mat2:
    bool SquareMat::operator<(const SquareMat& other)const{
        if(this->size!=other.size){
            throw std::invalid_argument("We cannot check that operator if the sizes are different");
        }
        return other>*this;
    }

    //Operator <= : this<=other:
    bool SquareMat::operator<=(const SquareMat& other)const{
        if(this->size!=other.size){
            throw std::invalid_argument("We cannot check that operator if the sizes are different");
        }
        return !(other<*this);//Not bigger->so smaller-equal

    }
    //Operator >= : this=>other:
    bool SquareMat::operator>=(const SquareMat& other)const{
        if(this->size!=other.size){
            throw std::invalid_argument("We cannot check that operator if the sizes are different");
        }
        return !(other>*this); //Not smaller--->so bigger-equal
    }

    //Operator Determinant (!)--->return the derminant of the matrix:
    double SquareMat::operator!()const{
        return helperDet(this->data,this->size);
    }

    //Helper method for compute the determinant of the matrix:
    double SquareMat::helperDet(const double* mat,int n)const{

        //Matrix of 1X1-->the det(mat)=mat[0],base case.
        if(n==1){
            return mat[0];
        }
        //Base case for a 2X2 matrix-->using the formula ad-bc:
        if(n==2){
            return mat[0]*mat[3]-mat[1]*mat[2];
        }


        double det=0; //The determinant of the matrix.
        int sign=1;//The sign for cofactor expansion-->starts as + and alternates(+,-,+,-,...).

        //Loop over the columns of the first row:
        for(int col=0;col<n;col++){
            //Create the minor matrix of [0][col]:
            double* minorMat=new double[(n-1)*(n-1)];
            int minorIndex=0; //Helper index to fill the minor index in order.

            //We build the minor matrix(starts from the second row):
            for(int i=1;i<n;i++){
                for(int j=0;j<n;j++){
                    //Skips the cofactor column:
                    if(j==col){
                        continue;
                    }
                    //Stores the corrresponding value from thr original matrix into minorMat:
                    minorMat[minorIndex++]=mat[i*n+j];
                }
            }

            //Compute the cofactor term,using recursive :
            det=det+sign*mat[col]*helperDet(minorMat,n-1);
            delete[]minorMat; 
            sign=-sign; //Change the sign each column

        }
        return det;
    }

    //Operator +=-->mat1=mat1+mat2:
    SquareMat& SquareMat::operator+=(const SquareMat& other){
        //Stop case--->if the sizes of the 2 matrices are not equal:
        if(this->size!=other.size){
            throw std::invalid_argument("The two matrices have needed to be with the same size!");
        }
        for(int i=0;i<size*size;i++){
            this->data[i]=this->data[i]+other.data[i];
        }
        return *this; //mat=mat+other.
        
    }

    //Operator -=-->mat1=mat1-mat2:
    SquareMat& SquareMat::operator-=(const SquareMat& other){
        //Stop case--->if the sizes of the 2 matrices are not equal:
        if(this->size!=other.size){
            throw std::invalid_argument("The two matrices have needed to be with the same size!");
        }
        for(int i=0;i<size*size;i++){
            this->data[i]=this->data[i]-other.data[i];
        }
        return *this; //mat=mat-other.
    }

    //Operator /=-->mat1=mat1/mat2:
    SquareMat& SquareMat::operator/=(double scalar){
        //Stop case--->we cannot divide with scalar 0:
        if(scalar==0){
            throw std::invalid_argument("We cannot divide matrix with scalar 0!");
        }
        for(int i=0;i<size*size;i++){
        data[i]=data[i]/scalar;
        }
        return *this; //mat=mat/scalar.
    }

    //Operator *=-->mat1=mat1*mat2:
    SquareMat& SquareMat::operator*=(const SquareMat& other){
        //Stop case--->if the sizes of the 2 matrices are not equal:
        if(this->size!=other.size){
            throw std::invalid_argument("The two matrices have needed to be with the same size!");
        }
        SquareMat ans(this->size);
        for(int i=0;i<size;i++){
            for(int j=0;j<size;j++){
                double sum=0;
                for(int k=0;k<size;k++){
                    sum=sum+(*this)[i*size+k]*other[k*size+j];
                }
                ans[i*size+j]=sum;
            }
        }
        for(int i=0;i<size*size;i++){
            this->data[i]=ans[i];
        }
        return *this; //mat=mat*other.
    }

    //Operator *=--->mat1=mat1*scalar:
    SquareMat& SquareMat::operator*=(double scalar){
        for(int i=0;i<size*size;i++){
            data[i]=data[i]*scalar;
        }
        return *this;
    }



    //Operator %=-->mat1=mat1%mat2:
    SquareMat& SquareMat::operator%=(const SquareMat& other){
        //Stop case--->if the sizes of the 2 matrices are not equal:
        if(this->size!=other.size){
            throw std::invalid_argument("The two matrices have needed to be with the same size!");
        }
        for(int i=0;i<size*size;i++){
            if(other.data[i]==0){
                throw std::invalid_argument("We cannot do modulo with 0!");
            }
            data[i]=std::fmod(data[i],other.data[i]);
        }
        return *this;
    }

    //Operator %=--->mat1=mat1%scalar:
    SquareMat& SquareMat::operator%=(int scalar){
        for(int i=0;i<size*size;i++){
            if(data[i]==0){
                throw std::invalid_argument("We cannot do modulo with 0!");
            }
            data[i]=std::fmod(data[i],scalar);
        }
        return *this;
    }

    //Operator << --->print our matrix:
    std::ostream& operator<<(std::ostream& os,const  SquareMat& mat){

        int n=mat.getSize(); //Save the size of the matrix


        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                os<<mat[i*n +j]<< " "; //Prints the value in (i,j) index.
            } 
            os<< std::endl; //Going down after row.
        }
        return os; 
    }
    
}


