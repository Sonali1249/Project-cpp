//1.  Book management system that handles inventory, sales tracking, and customer information tasks. By executing concepts like classes, objects, and file handling.....


#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Define a structure to represent a book
struct Book {
    string title;
    string author;
    int quantity;
    double price;
};

// Function to add a book to the inventory
void addBook(vector<Book>& inventory) {
    Book newBook;
    cout << "Enter book title: ";
    getline(cin >> ws, newBook.title); // Using getline to handle spaces in book titles
    cout << "Enter author name: ";
    getline(cin >> ws, newBook.author);
    cout << "Enter quantity: ";
    cin >> newBook.quantity;
    cout << "Enter price: ";
    cin >> newBook.price;
    
    inventory.push_back(newBook);
    cout << "Book added successfully!" << endl;
}

// Function to display all books in the inventory
void displayBooks(const vector<Book>& inventory) {
    cout << "Inventory:" << endl;
    for (const auto& book : inventory) {
        cout << "Title: " << book.title << ", Author: " << book.author << ", Quantity: " << book.quantity << ", Price: $" << book.price << endl;
    }
}

// Function to search for a book by title
void searchBook(const vector<Book>& inventory, const string& title) {
    bool found = false;
    for (const auto& book : inventory) {
        if (book.title == title) {
            cout << "Book found:" << endl;
            cout << "Title: " << book.title << ", Author: " << book.author << ", Quantity: " << book.quantity << ", Price: $" << book.price << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Book not found." << endl;
    }
}

int main() {
    vector<Book> inventory;
    int choice;
    string searchTitle;
    
    do {
        cout << "\nBookshop Management System\n";
        cout << "1. Add a book\n";
        cout << "2. Display all books\n";
        cout << "3. Search for a book by title\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch(choice) {
            case 1:
                cin.ignore(); // Ignore the newline character left by cin
                addBook(inventory);
                break;
            case 2:
                displayBooks(inventory);
                break;
            case 3:
                cout << "Enter book title to search: ";
                cin.ignore(); // Ignore the newline character left by cin
                getline(cin >> ws, searchTitle);
                searchBook(inventory, searchTitle);
                break;
            case 4:
                cout << "Exiting...";
                break;
            default:
                cout << "Invalid choice. Please enter a number from 1 to 4." << endl;
        }
    } while (choice != 4);
    
    return 0;
}