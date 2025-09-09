#include <iostream>
#include <vector>
using namespace std;

class Student {
private:
    struct Subject {
        string name;
        double marks;
        int credits;
        double gradePoint;
    };

    vector<Subject> subjects;

    // Function to convert marks into grade point (10-point scale)
    double calculateGradePoint(double marks) {
        if (marks >= 90) return 10;
        else if (marks >= 80) return 9;
        else if (marks >= 70) return 8;
        else if (marks >= 60) return 7;
        else if (marks >= 50) return 6;
        else if (marks >= 40) return 5;
        else return 0;
    }

public:
    void addSubject(string name, double marks, int credits) {
        Subject sub;
        sub.name = name;
        sub.marks = marks;
        sub.credits = credits;
        sub.gradePoint = calculateGradePoint(marks);
        subjects.push_back(sub);
    }

    double calculateCGPA() {
        double totalPoints = 0;
        int totalCredits = 0;

        for (auto &sub : subjects) {
            totalPoints += sub.gradePoint * sub.credits;
            totalCredits += sub.credits;
        }

        if (totalCredits == 0) return 0;
        return totalPoints / totalCredits;
    }

    void displayResult() {
        cout << "\nSubject-wise details:\n";
        for (auto &sub : subjects) {
            cout << sub.name << " | Marks: " << sub.marks 
                 << " | Credits: " << sub.credits 
                 << " | Grade Point: " << sub.gradePoint << endl;
        }
        cout << "\nFinal CGPA: " << calculateCGPA() << endl;
    }
};

int main() {
    Student s;
    int n;
    cout << "Enter number of subjects: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        string name;
        double marks;
        int credits;

        cout << "\nEnter subject " << i + 1 << " name: ";
        cin >> name;
        cout << "Enter marks (0-100): ";
        cin >> marks;
        cout << "Enter credits: ";
        cin >> credits;

        s.addSubject(name, marks, credits);
    }

    s.displayResult();
    return 0;
}