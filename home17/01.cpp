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
    Person() : surname(""), name(""), day(1), month(1), year(1900), gender('m') {}
    Person(string s, string n, int d, int m, int y, char g) {
        surname = s;
        name = n;
        day = d;
        month = m;
        year = y;
        setGender(g);
    }

    // Destructor
    ~Person() {}

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
    void input() {
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

// Overload << and >>
ostream& operator<<(ostream& out, const Person& p) {
    out << p.surname << " " << p.name[0] << ". Age: " << p.age() << " Gender: " << p.gender;
    return out;
}

istream& operator>>(istream& in, Person& p) {
    p.input();
    return in;
}

// Bubble sort
void sortPersons(Person* arr, int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                Person temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    int n;
    cout << "Enter number of people: ";
    cin >> n;

    Person* people = new Person[n];

    for (int i = 0; i < n; i++) {
        cout << "Enter data for person #" << i+1 << ":\n";
        cin >> people[i];
    }

    // Sort by age
    sortPersons(people, n);

    cout << "\nSorted list by age:\n";
    for (int i = 0; i < n; i++) {
        cout << people[i] << endl;
    }

    delete[] people;
    return 0;
}














