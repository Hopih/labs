
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
    Student arr[3];

    // Input
    for (int i = 0; i < 3; i++) {
        cout << "Enter data for student " << i+1 << ":" << endl;
        cout << "Surname, initials and group number: ";
        cin >> arr[i].surname >> arr[i].initials >> arr[i].group;

        cout << "Enter 4 grades: ";
        for (int j = 0; j < 4; j++) {
            cin >> arr[i].marks[j];
        }
    }

    cout << "\nBest grades of students:\n";

    // Find and print best grade
    for (int i = 0; i < 3; i++) {
        int best = arr[i].marks[0];
        for (int j = 1; j < 4; j++) {
            if (arr[i].marks[j] > best)
                best = arr[i].marks[j];
        }

        cout << arr[i].surname << " " << arr[i].initials
             << " — best grade: " << best << endl;
    }

    return 0;
}

