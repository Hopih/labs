#include <iostream>
using namespace std;

bool func(int &day, int &month, int &year){
    setlocale(LC_ALL, "");
    wcout<<L"Введите день "<<endl;
    cin>>day;
    wcout<<L"Введите номер месяца "<<endl;
    cin>>month;
    wcout<<L"Введите год"<<endl;
    cin>>year;
    cout<<endl;
    if (day>=1&&day<=31&&month>=1&&month<=12){
        return true;
    } else{
        return false;
    }
}

int main() {
    setlocale(LC_ALL, "");
    
    int currentDay, currentMonth, currentYear;
    int vasyaDay, vasyaMonth, vasyaYear;
    int petyaDay, petyaMonth, petyaYear;
    int kolyaDay, kolyaMonth, kolyaYear;
    
    wcout << L"Введите текущую дату:" << endl;
    func(currentDay, currentMonth, currentYear);
    
    wcout << L"Введите дату рождения Васи:" << endl;
    func(vasyaDay, vasyaMonth, vasyaYear);
    
    wcout << L"Введите дату рождения Пети:" << endl;
    func(petyaDay, petyaMonth, petyaYear);
    
    wcout << L"Введите дату рождения Коли:" << endl;
    func(kolyaDay, kolyaMonth, kolyaYear);
    
    wcout << L"Текущая дата: ";
    cout << currentDay << "." << currentMonth << "." << currentYear << endl;
    
    wcout << L"Дата рождения Васи: ";
    cout << vasyaDay << "." << vasyaMonth << "." << vasyaYear << endl;
    
    wcout << L"Дата рождения Пети: ";
    cout << petyaDay << "." << petyaMonth << "." << petyaYear << endl;
    
    wcout << L"Дата рождения Коли: ";
    cout << kolyaDay << "." << kolyaMonth << "." << kolyaYear << endl;
    
    int vasyaAge = currentYear - vasyaYear;
    if (currentMonth < vasyaMonth || (currentMonth == vasyaMonth && currentDay < vasyaDay)) {
        vasyaAge--;
    }
    
    int petyaAge = currentYear - petyaYear;
    if (currentMonth < petyaMonth || (currentMonth == petyaMonth && currentDay < petyaDay)) {
        petyaAge--;
    }
    
    int kolyaAge = currentYear - kolyaYear;
    if (currentMonth < kolyaMonth || (currentMonth == kolyaMonth && currentDay < kolyaDay)) {
        kolyaAge--;
    }
    
    wcout << L"Возраст Васи: " << vasyaAge << L" лет" << endl;
    wcout << L"Возраст Пети: " << petyaAge << L" лет" << endl;
    wcout << L"Возраст Коли: " << kolyaAge << L" лет" << endl;
    
    if (vasyaAge > petyaAge && vasyaAge > kolyaAge) {
        wcout << L"Вася старше всех" << endl;
    } else if (petyaAge > vasyaAge && petyaAge > kolyaAge) {
        wcout << L"Петя старше всех" << endl;
    } else if (kolyaAge > vasyaAge && kolyaAge > petyaAge) {
        wcout << L"Коля старше всех" << endl;
    } else if (vasyaAge == petyaAge && vasyaAge > kolyaAge) {
        wcout << L"Вася и Петя самые старшие" << endl;
    } else if (vasyaAge == kolyaAge && vasyaAge > petyaAge) {
        wcout << L"Вася и Коля самые старшие" << endl;
    } else if (petyaAge == kolyaAge && petyaAge > vasyaAge) {
        wcout << L"Петя и Коля самые старшие" << endl;
    } else {
        wcout << L"Все одного возраста" << endl;
    }
    
    return 0;
}






