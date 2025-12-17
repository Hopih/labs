#include <iostream>
 
int main()
{
    char c {'N'};
    char *pc {&c};            // указатель на символ
    int *pd {(int *)pc};      // указатель на int
    void *pv {(void*)pc};     // указатель на void
    std::cout << "pv=" << pv << std::endl;
    std::cout << "pd=" << pd << std::endl;
}







