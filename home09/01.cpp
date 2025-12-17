#include <iostream>
using namespace std;

int main(){
    int a[2][3];
    int d=0;
    int bet=1;
    for (int i=0;i<2;i++){
        for (int j=0;j<3;j++){
            int x=rand()%30+1;
            a[i][j]=x;
            d=d+x;
            if (x>=2&&x<=9){
                bet=bet*x;
            }
        }
    }
    for (int k=0;k<2;k++){
        for (int z=0;z<3;z++){
            cout<<a[k][z]<<" ";

        }
        cout<<endl;
    }
    if (d%2==0){
        cout<<"chet";
    } else{
        cout<<"nechet";
    }
    cout<<endl<<bet;













}












