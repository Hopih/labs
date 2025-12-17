#include <iostream>
using namespace std;
#include <cmath>
int main()
{
    auto a{1.5};
    auto b{M_PI};
    auto pa{&a};
    auto pb{&b};
    cout <<a<<"  "<<b<<endl;
    cout<<&a<<"  "<<&b<<endl;
    cout<<pa-pb<<endl;
    cout<<sizeof(a)<<" "<<sizeof(b);
    return 0;
}









