#include <iostream>
#include <string>
using namespace std;

struct Student {
    string surname;
    string initials;
    int group;
    int marks[4];
};

int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    Student arr[100]; // фиксированный массив, до 100 студентов

    for (int i = 0; i < n; i++) {
        cout << "Student " << i+1 << " data:" << endl;
        cout << "Surname, initials, group: ";
        cin >> arr[i].surname >> arr[i].initials >> arr[i].group;
        cout << "Enter 4 grades: ";
        for (int j = 0; j < 4; j++) {
            cin >> arr[i].marks[j];
        }
    }

    cout << "\nAverage grades:" << endl;

    for (int i = 0; i < n; i++) {
        int sum = 0;
        bool all5 = true;
        for (int j = 0; j < 4; j++) {
            sum += arr[i].marks[j];
            if (arr[i].marks[j] != 5) all5 = false;
        }
        double avg = sum / 4.0;
        cout << arr[i].surname << " — average grade: " << avg << endl;
        if (all5) {
            cout << arr[i].surname << " — straight-A student" << endl;
        }
    }

    return 0;
}
