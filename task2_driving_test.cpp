// Registration Number: CT101/G/26680/25

#include <iostream>
#include <string>
using namespace std;

int main() {
    // i. Declare variables
    string studentName;
    int age;
    double examScore;

    // Ask the user to enter the details
    cout << "Enter student name: ";
    getline(cin, studentName);

    cout << "Enter age: ";
    cin >> age;

    cout << "Enter exam score: ";
    cin >> examScore;

    // ii. Nested if statements to decide admission
    cout << "\n----- Admission Decision -----" << endl;
    cout << "Student Name : " << studentName << endl;

    if (age >= 18) {
        // First check passed, now check the score
        if (examScore >= 50) {
            cout << "Decision     : Admitted" << endl;
        } else {
            cout << "Decision     : Not Admitted: Low Score" << endl;
        }
    } else {
        cout << "Decision     : Not Admitted: Underage" << endl;
    }

    return 0;
}
