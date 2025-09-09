#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

class User {
private:
    string firstName;
    string lastName;
    string phone;
    string email;
    string password;

public:
    void signup() {
        cout << "\n--- Sign Up ---\n";
        cout << "Enter First Name: ";
        getline(cin, firstName);

        cout << "Enter Last Name: ";
        getline(cin, lastName);

        cout << "Enter Phone Number: ";
        getline(cin, phone);

        cout << "Enter Email ID: ";
        getline(cin, email);

        cout << "Create Password: ";
        getline(cin, password);

        // Save to file
        ofstream outFile("users.txt", ios::app);
        if (outFile.is_open()) {
            outFile << firstName << "," << lastName << "," << phone << "," << email << "," << password << "\n";
            outFile.close();
            cout << "Signup successful! Data saved.\n";
        } else {
            cout << "Error saving data.\n";
        }
    }

    bool login(const string& inputEmail, const string& inputPassword) {
        ifstream inFile("users.txt");
        string line;
        while (getline(inFile, line)) {
            stringstream ss(line);
            string fName, lName, ph, em, pw;
            getline(ss, fName, ',');
            getline(ss, lName, ',');
            getline(ss, ph, ',');
            getline(ss, em, ',');
            getline(ss, pw, ',');

            if (em == inputEmail && pw == inputPassword) {
                cout << "Login successful! Welcome, " << fName << " " << lName << ".\n";
                return true;
            }
        }
        cout << "Invalid email or password.\n";
        return false;
    }
};

int main() {
    User user;
    int choice;

    while (true) {
        cout << "\n--- Menu ---\n";
        cout << "1. Sign Up\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Clear input buffer

        switch (choice) {
            case 1:
                user.signup();
                break;
            case 2: {
                string email, password;
                cout << "\n--- Login ---\n";
                cout << "Enter Email ID: ";
                getline(cin, email);
                cout << "Enter Password: ";
                getline(cin, password);
                user.login(email, password);
                break;
            }
            case 3:
                cout << "Exiting... Have a great day!\n";
                return 0;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    }
}
