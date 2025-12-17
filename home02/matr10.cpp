#include <iostream>
#include <windows.h>
#include <string>
using namespace std;
int main(){
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    int a[3][4];
    int b[3][4];
    int c[3][4];
    int mas[3][4][2];
    for (int i=0;i<3;i++){
        for (int j=0;j<4;j++){
            int nalog;
            cout <<"Введите данные для "<<j+1<<" работника в "<<i+1<<" месяце";
            cin >>a[i][j]>>b[i][j];
            c[i][j]=a[i][j]*b[i][j];
            nalog = c[i][j]*0.13;
            mas[i][j][0]=nalog;
            mas[i][j][1]=c[i][j];
        }
    }
    cout <<mas[1][0][1]-mas[1][0][0]<<endl;
    int d=0;
    int num;
    int zarp=0;
    for (int k=0;k<3;k++){
        d=d+mas[k][2][0];
    }
    cout <<d<<endl;
    for (int r=0;r<4;r++){
        if (mas[2][r][1]>zarp){
            zarp=mas[2][r][1];
            num=r+1;
        }
    }
    cout <<num<<endl;
    int sum=0;
    for (int m=0;m<3;m++){
        for (int n=0;n<4;n++){
            sum=sum+mas[m][n][1];
        }
    }
    cout <<sum;
}








