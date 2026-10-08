//REG NO : CT101/G/26680/25

#include <iostream>
#include <string>
using namespace std;

int main() {
    // i. Declare variables
    string studentName;
    double theoryMarks;
    double practicalMarks;
    double averageScore;

    // Ask the user to enter the details
    cout << "Enter student name: ";
    getline(cin, studentName);

    cout << "Enter theory test marks: ";
    cin >> theoryMarks;

    cout << "Enter practical test marks: ";
    cin >> practicalMarks;

    // ii. Calculate the average score
    averageScore = (theoryMarks + practicalMarks) / 2;

    // iii. Display the results
    cout << "\n----- Driving Test Result -----" << endl;
    cout << "Student Name    : " << studentName << endl;
    cout << "Theory Marks    : " << theoryMarks << endl;
    cout << "Practical Marks : " << practicalMarks << endl;
    cout << "Average Score   : " << averageScore << endl;

    // A student passes if the average score is 50 and above
    if (averageScore >= 50) {
        cout << "Result          : PASSED" << endl;
    } else {
        cout << "Result          : FAILED" << endl;
    }

    return 0;
}
