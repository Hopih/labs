#include <iostream>
#include <vector>
#include <random>
#include <chrono>
using namespace std;


int ** creatematrix(const int rows,const int cols){
    int **matrix=new int*[rows];
    
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(1, 10);

    for (int i=0;i<rows;i++){
        matrix[i]=new int[cols];
    }

    for (int k=0;k<rows;k++){
        for(int j=0;j<cols;j++){
            matrix[k][j]=dist(gen);
        }
    }

    return matrix;
}

int ** summatrix(const int rows,const int cols,int ** matrix1,int ** matrix2){
    int **matrix=new int*[rows];

    for (int i=0;i<rows;i++){
        matrix[i]=new int[cols];
    }

    for (int k=0;k<rows;k++){
        for(int j=0;j<cols;j++){
            matrix[k][j]=matrix1[k][j]+matrix2[k][j];
        }
    }

    return matrix;
}

int ** proizvmatrix(const int rows1,const int cols1,const int rows2,const int cols2,int **matrix1,int **matrix2){
    int rows3;
    int cols3;

    rows3=rows1;
    cols3=cols2;
    
    int **matrix=new int*[rows3];

    for (int i=0;i<rows3;i++){
        matrix[i]=new int[cols3];
    }
    
    for (int t=0;t<rows3;t++){
        for (int s=0;s<rows1;s++){
            matrix[s][t]=0;
            for (int d=0;d<cols1;d++){
                matrix[s][t]=matrix[s][t]+matrix1[s][d]*matrix2[d][t];
            }
        }
    }
    return matrix;
}

void deleteMatrix(int** matrix, const int rows) {
    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

void printout(int **a,const int rows,const int cols){
    for (int i=0;i<rows;i++){
        for(int k=0;k<cols;k++){
            cout<<a[i][k]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    int rows,cols;
    int rows1,rows2,cols1,cols2;
    cout<<"for sum"<<endl;
    cin>>rows;
    cin>>cols;
    cout<<endl<<"for proizv"<<endl;
    cin>>rows1>>rows2>>cols1>>cols2;

    int** mat1=creatematrix(rows,cols);
    int** mat2=creatematrix(rows,cols);
    int** mat3=summatrix(rows,cols,mat1,mat2);
    int** mat4=creatematrix(rows1,cols1);
    int** mat5=creatematrix(rows2,cols2);
    int** mat6=proizvmatrix(rows1,cols1,rows2,cols2,mat4,mat5);

    printout(mat1,rows,cols);
    cout<<endl;
    printout(mat2,rows,cols);
    cout<<endl;
    printout(mat3,rows,cols);
    cout<<endl;


    deleteMatrix(mat1,rows1);
    deleteMatrix(mat2,rows);
    deleteMatrix(mat3,rows);


    printout(mat4,rows1,cols1);
    cout<<endl;
    printout(mat5,rows2,cols2);
    cout<<endl;
    printout(mat6,rows1,cols2);

    deleteMatrix(mat4,rows1);
    deleteMatrix(mat5,rows2);
    deleteMatrix(mat6,rows1);

    
    return 0;
}














