
#include <iostream>
#include <vector>
using namespace std;

void addBook(vector<string>& titles, vector<string>& authors, vector<int>& years) {
    string title, author;
    int year;
    cin >> title >> author >> year; 

    cout << "Provide the title: " << "'" << title << "'" << endl;
    cout << "Provide the author name: " << "'" << author << "'" << endl;
    cout << "Provide the publication date: " << "'" << year << "'" << endl;

    titles.push_back(title);
    authors.push_back(author);
    years.push_back(year);

    cout << "Book added successfully!\n" << endl;
}

void displayBooks(const vector<string>& titles, const vector<string>& authors, const vector<int>& years) {
    if (titles.empty()) {
        cout << "No books in the library.\n";
        return;
    }

    cout << "Books in the library:\n";
    for (size_t i = 0; i < titles.size(); i++) {
        cout << "Title: " << titles[i] << ", Author: " << authors[i] << ", Year: " << years[i] << "\n" << endl;
    }
}

void searchBook(const vector<string>& titles, const vector<string>& authors, const vector<int>& years) {
    string title;
    cin >> title;

    cout << "Enter title of the book: " << "'" << title << "'" << endl;

    for (size_t i = 0; i < titles.size(); i++) {
        if (titles[i] == title) {
            cout << "Book found!" << endl; 
            cout << "Title: " << titles[i] << ", Author: " << authors[i] << ", Year: " << years[i] << "\n" << endl;
            return;
        }
    }
    cout << "Book not found.\n" << endl;
}

void deleteBook(vector<string>& titles, vector<string>& authors, vector<int>& years) {
    string title, author;
    int year; 
    cin >> title >> author >> year; 
    
    cout << "Enter title of book to delete: " << "'" << title << "'" << endl;
    cout << "Enter author of book to delete: " << "'" << author << "'" << endl;
    cout << "Enter book's year of publication: " << "'" << year << "'" << endl;

    for (size_t i = 0; i < titles.size(); i++) {
        if (titles[i] == title && authors[i] == author && years[i] == year) {
            titles.erase(titles.begin() + i);
            authors.erase(authors.begin() + i);
            years.erase(years.begin() + i);
            cout << "Book deleted successfully!\n" << endl;
            return; 
        }
    }
    
    cout << "Book not found.\n" << endl;
}

int main() {
    vector<string> titles;
    vector<string> authors;
    vector<int> years;

    int choice;
    while (true) {
        cout << "----Library Management System----\n";
        cout << "1. Add Book\n";
        cout << "2. Display All Books\n";
        cout << "3. Search for a Book\n";
        cout << "4. Delete a Book\n";
        cout << "5. Exit\n";
        cin >> choice;
        cout << "Enter your choice: " << choice << "\n";

        switch (choice) {
            case 1:
                addBook(titles, authors, years);
                break;
            case 2:
                displayBooks(titles, authors, years);
                break;
            case 3:
                searchBook(titles, authors, years);
                break;
            case 4:
                deleteBook(titles, authors, years);
                break;
            case 5:
                cout << "Exiting the program. Come back again!\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
}
