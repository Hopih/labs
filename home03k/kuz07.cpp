#include <iostream>
#include <string>
using namespace std;
int main(){
    int day,mouth,year;
    cin >>day>>mouth>>year;
    if (mouth==1){
        cout<<day <<" January "<<year<<endl;  
    }
    if (mouth==2){
        cout<<day <<" Feburary "<<year<<endl;  
    }
    if (mouth==3){
        cout<<day <<" Mart "<<year<<endl;  
    }
    if (mouth==4){
        cout<<day <<" April "<<year<<endl;  
    }
    if (mouth==5){
        cout<<day <<" May "<<year<<endl;  
    }
    if (mouth==6){
        cout<<day <<" June "<<year<<endl;  
    }
    if (mouth==7){
        cout<<day <<" July "<<year<<endl;  
    }
    if (mouth==8){
        cout<<day <<" August "<<year<<endl;  
    }
    if (mouth==9){
        cout<<day <<" September "<<year<<endl;  
    }
    if (mouth==10){
        cout<<day <<" October "<<year<<endl;  
    }
    if (mouth==11){
        cout<<day <<" November "<<year<<endl;  
    }
    if (mouth==12){
        cout<<day <<" December "<<year<<endl;
    }
    if ((mouth==1)||(mouth==2)||(mouth==3)){
        cout <<"Winter";
    }
    if ((mouth==4)||(mouth==5)||(mouth==6)){
        cout <<"Spring";
    }
    if ((mouth==7)||(mouth==8)||(mouth==9)){
        cout <<"Summer";
    }
    if ((mouth==10)||(mouth==11)||(mouth==12)){
        cout <<"Winter";
    }


}












