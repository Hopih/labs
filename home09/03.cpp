#include <iostream>
using namespace std;

int main(){
    for (int i=0;i<8;i++){
        for (int j=0;j<8;j++){
            if (i%2==0){
                if (j%2==0){
                    cout<<"1 ";
                } else{
                    cout <<"0 ";
                }
            } else{
                if (j%2==0){
                    cout<<"0 ";
                } else{
                    cout<<"1 ";
                }
            }
        }
        cout<<endl;
    }
cout<<endl;

int d=0;
int a[5][5];
for (int i=0;i<5;i++){
    for (int j=0;j<5;j++){
        if (j==d&&i==d){
            a[i][j]=1;
            d=d+1;
        }
        else{
            a[i][j]=0;
        }
    }
}

for(int i=0;i<5;i++){
    for (int j=0;j<5;j++){
        cout<<a[i][j]<<" ";

    }
    cout<<endl;
}
cout<<endl;

int b[6][6];
for (int i=0;i<6;i++){
    for (int j=0;j<6;j++){
        b[i][j]=6;
    }
}
for (int i = 0; i < 6; i++) {
    for (int j = 0; j < 6; j++) {
        if (j < i) {
            b[i][j] = 0;
        } else {
            b[i][j] = 6 - (j - i); 
        }
    }
}

for (int i = 0; i < 6; i++) {
    for (int j = 0; j < 6; j++) {
        cout << b[i][j] << " ";
    }
    cout << endl;
}
cout<<endl;

int c[5][5];

for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
        if (i + j < 5 - 1) {
            c[i][j] = 0;
        } else {
            c[i][j] = (i + j) - (5 - 2); 
        }
    }
}


for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
        cout << c[i][j] << " ";
    }
    cout << endl;
}

int n = 10;
int e[10][10];

cout<<endl;
int center = 10 / 2;

for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
        
        int dist_i = abs(i - center);
        int dist_j = abs(j - center);
        int ring_level = max(dist_i, dist_j);
        
        e[i][j] = ring_level;
    }
}


for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
        cout << e[i][j] << " ";
    }
    cout << endl;
}






}







