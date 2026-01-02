#include <iostream>
#include <vector>
using namespace std;

class Bank {
    int userid;
    int amt;
    string name;

public:
    void accept();
    void display() const;
    void withdraw();
    int getUserId() const;
};

void Bank::accept() {
    cout << "Name: ";
    cin >> name;
    cout << "UserId: ";
    cin >> userid;
    cout << "Initial Amount: ";
    cin >> amt;
}

void Bank::display() const {
    cout  <<"\t"<< name << "\t" << userid << "\t" << amt << endl;
}

void Bank::withdraw() {
    int amt_with;
    cout << "Enter amount to withdraw: ";
    cin >> amt_with;

    if (amt_with <= amt) {
        amt -= amt_with;
        cout << "Amount left: " << amt << endl;
    } else {
        cout << "Insufficient Balance!\n";
    }
}

int Bank::getUserId() const {
    return userid;
}

int main() {
    vector<Bank> users;
    int ch;

    do {
        cout << "\n1. Add User\n2. Display All\n3. Withdraw\n4. Search by ID\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> ch;

        switch (ch) {
            case 1: {
                Bank b;
                b.accept();
                users.push_back(b);
                break;
            }
            case 2: {
                if (users.empty())
                    cout << "No records available\n";
                else {
                    cout << "\nUser\tName\tUserId\tAmount\n";
                    for (int i = 0; i < users.size(); ++i)
                   { cout<<i+1;
                        users[i].display();}
                }
                break;
            }
            case 3: {
                int id;
                cout << "Enter your ID: ";
                cin >> id;
                bool found = false;
                for (int i=0;i<users.size();i++) {
                    if (users[i].getUserId() == id) {
                        users[i].withdraw();
                        found = true;
                        break;
                    }
                }
                if (!found)
                    cout << "User not found!\n";
                break;
            }
            case 4: {
                int id;
                cout << "Enter ID to search: ";
                cin >> id;
                bool found = false;
                for (auto &user : users) {
                    if (user.getUserId() == id) {
                        cout << "\nName\tUserId\tAmount\n";
                        user.display();
                        found = true;
                        break;
                    }
                }
                if (!found)
                    cout << "User not found!\n";
                break;
            }
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (ch != 5);

    return 0;
}
