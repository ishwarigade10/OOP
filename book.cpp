#include<iostream>
#include<vector>
using namespace std;

class Book {
    string auth, title, publish;
    int stock;
    float price;
public:
    // Constructor
    Book(string t = "", string a = "", string p = "", float pr = 0, int s = 0) {
        title = t;
        auth = a;
        publish = p;
        price = pr;
        stock = s;
    }

    // Destructor
    ~Book() {
        cout << "Destructor called for " << title << endl;
    }

    void accept();
    void display();
    bool matches(string t, string a);
    void purchase(int copies);
};

void Book::accept() {
    cout << "Title: ";
    cin >> title;
    cout << "Author: ";
    cin >> auth;
    cout << "Publisher: ";
    cin >> publish;
    cout << "Price: ";
    cin >> price;
    cout << "Stock: ";
    cin >> stock;
}

void Book::display() {
    cout << "\nTitle\tAuthor\tPublisher\tPrice\tStock\n";
    cout << title << "\t" << auth << "\t" << publish << "\t\t" << price << "\t" << stock << endl;
}

bool Book::matches(string t, string a) {
    return (title == t && auth == a);
}

void Book::purchase(int copies) {
    if (copies <= stock) {
        float total = copies * price;
        float discount = 0;

        if (copies >= 10) discount = 0.2 * total;
        else if (copies >= 5) discount = 0.1 * total;

        float finalCost = total - discount;

        cout << "Total cost = " << total << endl;
        if (discount > 0)
            cout << "Discount applied = " << discount << endl;
        cout << "Final cost = " << finalCost << endl;

        stock -= copies;
        cout << "Purchase successful! Remaining stock = " << stock << endl;
    } else {
        cout << "Required copies not in stock.\n";
    }
}

int main() {
    vector<Book*> user;  // store pointers

    while (1) {
        int choice;
        cout << "\n1. Add a book\n2. Search and Purchase\n3. Display\n4. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            Book* b = new Book();   // allocate dynamically
            b->accept();
            user.push_back(b);
            break;
        }
        case 2: {
            bool found = false;
            cout << "Enter the Title and Author to search a book: ";
            string t, a;
            cin >> t >> a;
            for (int i = 0; i < user.size(); i++) {
                if (user[i]->matches(t, a)) {
                    cout << "\nBook found:\n";
                    user[i]->display();
                    int copies;
                    cout << "\nEnter number of copies required: ";
                    cin >> copies;
                    user[i]->purchase(copies);
                    found = true;
                    break;
                }
            }
            if (!found) cout << "Book not available.\n";
            break;
        }
        case 3: {
            if (user.empty()) {
                cout << "\nNo Books available.\n";
            } else {
                cout << "\n----- All Book Details -----\n";
                for (int i = 0; i < user.size(); ++i) {
                    cout << "\nBook " << i + 1 << ":\n";
                    user[i]->display();
                }
            }
            break;
        }
        case 4: {
            cout << "Exiting program...\n";

            // free memory
            for (int i = 0; i < user.size(); i++) {
                delete user[i];  // destructor called here
            }
            user.clear();

            return 0;
        }
        default: {
            cout << "Wrong choice!\n";
            break;
        }
        }
    }

    return 0;
}