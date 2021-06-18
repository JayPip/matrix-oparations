#include <iostream>
#include<cmath>

using namespace std;


struct matrix{

int rows;
int **array;




void add( matrix m2){
    cout<<"matrix after operation"<<endl;
for(int i=0; i<rows; i++)
    {
        
        for(int j=0; j<rows; j++){

            int element = array[i][j]+m2.array[i][j];
            cout<< element <<" ";
        }
            
            cout<<endl;

    }


}

void subtract( matrix m2){
  cout<<"matrix after operation"<<endl;
for(int i=0; i<rows; i++)
    {
        
        for(int j=0; j<rows; j++){

            int element = array[i][j]-m2.array[i][j];
            cout<< element <<" ";
        }
            
            cout<<endl;
 
    }


}


void multiply(matrix m2){



for(int i=0;i<rows;i++)    
{    
    for(int j=0;j<rows;j++){    
       
        for(int k=0;k<rows;k++){    
        cout<<array[i][k]*m2.array[k][j]<<" ";    
        }    
    }    
}    

}


void scalar(int scalar){



for(int i=0;i<rows;i++)    
{    
    for(int j=0;j<rows;j++){    
       
        for(int k=0;k<rows;k++){    
        cout<<array[i][k]*scalar<<" ";    
        }    
    }    
}    

}


void areSame(matrix m2){

int i, j;
    for (i = 0; i < rows; i++)
        for (j = 0; j < rows; j++)
            if (array[i][j] != m2.array[i][j])
                cout<<"Matrices are not the same"<<endl;
    cout<<"Matrices are not the same"<<endl;


}


/*
int determinant(int array[][rows] , int rows ) {
   int det = 0;
   int submatrix[rows][rows];
    int n = rows;
   if (n == 2)
   cout<< ((array[0][0] * array[1][1]) - (array[1][0] * array[0][1]))<<endl;
   
   else {
      for (int x = 0; x < n; x++) {
         int subi = 0;
         for (int i = 1; i < n; i++) {
            int subj = 0;
            for (int j = 0; j < n; j++) {
               if (j == x)
               continue;
               submatrix[subi][subj] = array[i][j];
               subj++;
            }
            subi++;
         }
         det = det + (pow(-1, x) * array[0][x] * determinant( submatrix, n - 1 ));
      }
   }
   cout<< det<<endl;

   
}

*/



void transpose(){
    int i,j;
 for (i = 0; i < rows; i++){
   for (j = 0; j < rows; j++)
             cout<<array[j][i]<<" ";

    cout<<endl;

 }
     

}

void sumDiag(){
int sum = 0;

for(int i= 0; i<rows; i++){
    sum+=array[i][i];

}
cout<<sum<<endl;


}

void UpperTriangular()
{
    for (int i = 1; i < rows; i++)
        for (int j = 0; j < i; j++)
            if (array[i][j] != 0)
                cout<<"Matrix is not upper triangular"<<endl;
    cout<<"Matrix is upper traingular"<<endl;
}

void LowerTriangular(){

for (int i = 0; i < rows; i++)
        for (int j = i + 1; j < rows; j++)
            if (array[i][j] != 0)
               cout<<"Matrix is not lower triangular"<<endl;
    cout<<"Matrix is lower traingular"<<endl;


}




void identity(){

for(int i= 0; i<rows; i++){
    if(array[i][i]!=1){
    cout<<"Thats not identity matrix"<<endl;
    return;
    }

}

cout<<"Thats identity matrix"<<endl;

}


void sparse(){

int ctr =0;
int max = rows*rows;

for (int i = 0; i < rows; i++)
        for (int j = 0; j < rows; j++)
            if (array[i][j] == 0)ctr++;
               

if(ctr>max/2)cout<<"Matrix is sparse"<<endl;
else cout<<"Matrix is not sparse"<<endl;

}



/*

void transposeSym(int tr[][]){
 

 for (int i = 0; i < rows; i++){
   for (int j = 0; j < rows; j++)
             tr[i][j] = array[j][i];

 }
     

}

bool isSymmetric()
{
    int tr[rows][rows];
    transposeSym(tr);
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < rows; j++)
            if (array[i][j] != tr[i][j])
                cout<<"matrix is not symmetric"<<endl;
    cout<<"matrix is symmetric"<<endl;
}
*/

};

int main()
{
bool on = 1;
string operation;
matrix m1{};
matrix m2{};


while(on){


cout<<"-----------Matrices----------"<<endl;
cout<<"N1 -> new matrix1"<<endl;
cout<<"N2 -> new matrix2"<<endl;
cout<<"P1 -> print matrix2"<<endl;
cout<<"P2 -> print matrix2"<<endl;
cout<<"-----------Operations----------"<<endl;
cout<<"1 -> Adding 2 matrices"<<endl;
cout<<"2 -> Subtracting 2 matrices"<<endl;
cout<<"3 -> Multiplying 2 matrices"<<endl;
cout<<"4 -> Multiplying matrix by scalar"<<endl;
cout<<"5 -> Checking if matrices are equal"<<endl;
cout<<"6 -> Determinant of matrix"<<endl;
cout<<"7 -> Transposition of matrix"<<endl;
cout<<"8 -> Sum on main diagonal"<<endl;
cout<<"9 -> Upper triangular"<<endl;
cout<<"10 -> Lower traingular"<<endl;
cout<<"11 -> Identity matrix"<<endl;
cout<<"12 -> Sparse matrix"<<endl;
cout<<"13 -> Symmetric matrix"<<endl;


cout<<"E -> END"<<endl;


cin>>operation;

if(operation == "E") on=0;

if(operation == "P1") {
    int rows = m1.rows;
    for (int i = 0; i<(rows*rows); i++)
    {
    cout<<m1.array[i/rows][i%rows]<<" " ; 
    }

    cout<<endl;

}


if(operation == "P2"){
    int rows = m2.rows;
    for (int i = 0; i<(rows*rows); i++)
    {
    cout<<m2.array[i/rows][i%rows]<<" " ; 
    }
    cout<<endl;

}

if(operation == "N1" || operation == "N2" ){
    int rows;

    int** matrix = new int *[rows];


    cout<<"New matrix:"<<endl;
    cout<<"Enter number of rows and columns:"<<endl;
    cin>>rows;
    cout<<"Enter matrix "<<endl;

     // allocate array of int pointers
    for( int i = 0; i < rows; i++)
    {
        matrix[i] = new int [rows]; // allocate each array of ints
    }
    for (int i = 0; i<(rows*rows); i++)
    {
    cin>>matrix[i/rows][i%rows] ; 
    }

    if(operation == "N1"){
        m1.array = matrix;
        m1.rows = rows;
    }
        

    else if(operation == "N2"){
        m2.array = matrix;
        m2.rows = rows;
    }
        

    }

    if(operation == "1"){
        int op;
        cout<<" 1 -> Add matrix1 to matrix2"<<endl;
        cout<<" 2 -> Add matrix1 to matrix2"<<endl;
        cin>>op;

        if(op == 1)m1.add(m2);
        else m2.add(m1);


    }

    else if(operation == "2"){
        int op;
        cout<<" 1 -> Subtract matrix1 from matrix2"<<endl;
        cout<<" 2 -> Subtract matrix2 from matrix1"<<endl;
        cin>>op;

        if(op == 1)m2.subtract(m1);
        else m1.subtract(m2);


    }

     else if(operation == "3"){
        

        m1.multiply(m2);
        

    }

     else if(operation == "4"){
        int op;
        cout<<" 1 -> Multiply matrix1 by scalar"<<endl;
        cout<<" 2 -> Multiply matrix2 by scalar"<<endl;
        cin>>op;
        cout<<"Enter scalar"<<endl;
        int scalar;
        cin>>scalar;
        if(op==1)
        m1.scalar(scalar);
        else 
        m2.scalar(scalar);


    }
        else if(operation == "5"){
       
       m1.areSame(m2);


    }

    else if(operation == "7"){
       int op;
        cout<<" 1 -> Transpose matrix1"<<endl;
        cout<<" 2 -> Transpose matrix2"<<endl;
        cin>>op;
        if(op==1)
        m1.transpose();
        else 
        m2.transpose();


    }

    else if(operation == "8"){
       int op;
        cout<<" 1 -> Sum on diagonal of matrix1"<<endl;
        cout<<" 2 -> Sum on diagonal of matrix2"<<endl;
        cin>>op;
        if(op==1)
        m1.sumDiag();
        else 
        m2.sumDiag();


    }

        else if(operation == "9"){
       int op;
        cout<<" 1 -> Upper triangular matrix1"<<endl;
        cout<<" 2 -> Upper triangular matrix2"<<endl;
        cin>>op;
        if(op==1)
        m1.UpperTriangular();
        else 
        m2.UpperTriangular();


    }


    else if(operation == "10"){
       int op;
        cout<<" 1 -> Lower triangular matrix1"<<endl;
        cout<<" 2 -> Lower triangular matrix2"<<endl;
        cin>>op;
        if(op==1)
        m1.LowerTriangular();
        else 
        m2.LowerTriangular();


    }

        else if(operation == "11"){
       int op;
        cout<<" 1 -> Identity matrix1"<<endl;
        cout<<" 2 -> Identity matrix2"<<endl;
        cin>>op;
        if(op==1)
        m1.identity();
        else 
        m2.identity();


    }

    else if(operation == "12"){
       int op;
        cout<<" 1 -> Sparse matrix1"<<endl;
        cout<<" 2 -> Sparse matrix2"<<endl;
        cin>>op;
        if(op==1)
        m1.sparse();
        else 
        m2.sparse();


    }

}

return 0;
}
