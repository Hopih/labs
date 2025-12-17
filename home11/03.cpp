#include <iostream>
using namespace std;

double fact(int x){
    if (x==0){
        return 1;
    } else{
        return x*fact(x-1);
    }

}

int step(int x, int n){
    int d=1;
    for (int k=0;k<n;k++){
        d=d*x;
    }
    return d;
}

int main(){
    int M;
    int N;
    int x;
    int n;
    cout<<"N "<<"M = "<<endl;
    cin>>N>>M;
    cout <<(fact(N)*fact(M))/(fact(N+M))<<endl;
    cout<<"x,n = "<<endl;
    cin>>x>>n;
    cout<<step(x,n);
    
    return 0;
    
}



















