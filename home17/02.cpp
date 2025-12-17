#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>

using namespace std;

class Person {
private:
    string surname;
    string name;
    int day, month, year;
    char gender; // 'm', 'f', 'м', 'ж'

    bool isValidGender(char g) {
        g = tolower(g);
        return g == 'm' || g == 'f' || g == 'м' || g == 'ж';
    }

public:
    // Constructors
    Person() : surname(""), name(""), day(1), month(1), year(1900), gender('m') {}
    Person(string s, string n, int d, int m, int y, char g) {
        surname = s;
        name = n;
        day = d;
        month = m;
        year = y;
        setGender(g);
    }

    virtual ~Person() {}

    // Getters
    string getSurname() const { return surname; }
    string getName() const { return name; }
    int getDay() const { return day; }
    int getMonth() const { return month; }
    int getYear() const { return year; }
    char getGender() const { return gender; }

    // Setters
    void setSurname(const string& s) { surname = s; }
    void setName(const string& n) { name = n; }
    void setDay(int d) { day = d; }
    void setMonth(int m) { month = m; }
    void setYear(int y) { year = y; }
    void setGender(char g) {
        if (isValidGender(g)) {
            gender = g;
        } else {
            cout << "Invalid gender input. Defaulting to 'm'." << endl;
            gender = 'm';
        }
    }

    // Input function
    virtual void input() {
        cout << "Surname: "; cin >> surname;
        cout << "Name: "; cin >> name;
        cout << "Birth date (day month year): "; cin >> day >> month >> year;
        cout << "Gender (m/f): "; 
        char g; 
        cin >> g;
        setGender(g);
    }

    // Age calculation
    int age() const {
        time_t t = time(0);
        tm* now = localtime(&t);
        int age = now->tm_year + 1900 - year;
        if (month > now->tm_mon + 1 || (month == now->tm_mon + 1 && day > now->tm_mday)) {
            age--;
        }
        return age;
    }

    // Operator overloads
    bool operator<(const Person& other) const { return age() < other.age(); }
    bool operator>(const Person& other) const { return age() > other.age(); }
    bool operator==(const Person& other) const { return age() == other.age(); }

    friend ostream& operator<<(ostream& out, const Person& p);
    friend istream& operator>>(istream& in, Person& p);
};

ostream& operator<<(ostream& out, const Person& p) {
    out << p.surname << " " << p.name[0] << ". Age: " << p.age() << " Gender: " << p.gender;
    return out;
}

istream& operator>>(istream& in, Person& p) {
    p.input();
    return in;
}

// ---------------- Derived class Employee ----------------
class Employee : public Person {
private:
    double salary;       // base salary
    double bonusPercent; // percentage of bonus

public:
    // Constructors
    Employee() : Person(), salary(0), bonusPercent(0) {}
    Employee(string s, string n, int d, int m, int y, char g, double sal, double bonus)
        : Person(s, n, d, m, y, g), salary(sal), bonusPercent(bonus) {}

    // Getters and Setters
    void setSalary(double sal) { salary = sal; }
    void setBonusPercent(double bonus) { bonusPercent = bonus; }
    double getSalary() const { return salary; }
    double getBonusPercent() const { return bonusPercent; }

    // Input function
    void input() override {
        Person::input();
        cout << "Base salary: "; cin >> salary;
        cout << "Bonus percent: "; cin >> bonusPercent;
    }

    // Calculate total salary with bonus
    double totalSalary() const {
        return salary * (1 + bonusPercent / 100.0);
    }

    // Calculate tax (13%)
    double tax() const {
        return totalSalary() * 0.13;
    }

    // Salary after tax
    double netSalary() const {
        return totalSalary() - tax();
    }

    // Output
    friend ostream& operator<<(ostream& out, const Employee& e);
};

ostream& operator<<(ostream& out, const Employee& e) {
    out << e.getSurname() << " " << e.getName()[0] << ". Age: " << e.age() 
        << " Gender: " << e.getGender() 
        << " Total salary: " << fixed << setprecision(2) << e.totalSalary() 
        << " Tax: " << e.tax() 
        << " Net salary: " << e.netSalary();
    return out;
}

// ---------------- Test program ----------------
int main() {
    int n;
    cout << "Enter number of employees: ";
    cin >> n;

    Employee* employees = new Employee[n];

    for (int i = 0; i < n; i++) {
        cout << "\nEnter data for employee #" << i+1 << ":\n";
        cin >> employees[i];
    }

    cout << "\nEmployee details:\n";
    for (int i = 0; i < n; i++) {
        cout << employees[i] << endl;
    }

    delete[] employees;
    return 0;
}













