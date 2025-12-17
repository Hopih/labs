#include <iostream>
using namespace std;

int main(){
    int a[3][4];
    int b[3][4];
    int mas[3][4];
    int c[4];
    int str;
    int stolb;
    int z=INT_MAX;
    for (int i=0;i<3;i++){
        int d=0; 
        for (int j=0;j<4;j++){
            int x;
            cin>>x;
            a[i][j]=x;
            b[i][j]=x;
            mas[i][j]=x;
            if (x<z){
                z=x;
                str=i+1;
                stolb=j+1;
            }


        }
    }
    for (int k=0;k<4;k++){
        b[stolb-1][k]=a[2][k];
        b[2][k]=a[stolb-1][k];

    }
    for (int k=0;k<3;k++){
        for (int z=0;z<4;z++){
            cout<<a[k][z]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    for (int k=0;k<3;k++){
        for (int z=0;z<4;z++){
            cout<<b[k][z]<<" ";
        }
        cout<<endl;
}
cout <<endl;
cout <<z<<" "<<str<<" "<<stolb<<endl;
cout<<endl;
for (int i=0;i<4;i++){
    c[i]=a[0][i]+a[1][i]+a[2][i];
}
for (int j=0;j<4;j++){
    cout <<c[j]<<" ";
}
cout<<endl;
for (int i=0;i<3;i++){
    for (int j=0;j<4;j++){
        if (i==0){
            mas[i][j]=z;
        }

    }
}
cout <<endl;
for (int i=0;i<3;i++){
    for (int j=0;j<4;j++){
        cout<<mas[i][j]<<" ";


    }
    cout<<endl;
}





}







