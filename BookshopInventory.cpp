#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Book {
public:
    //Constructors
    Book() {
        this->bookName = "";
        this->authorName = "";
        this->publishDate = "";
    }
    Book(string bookName, string authorName, string publishDate) {
        this->bookName = bookName;
        this->authorName = authorName;
        this->publishDate = publishDate;
    }
    //Public member functions
    string GetBookName() {
        return this->bookName;
    }
    void SetBookName(string bookName) {
        this->bookName = bookName;
    }
    string GetAuthorName() {
        return this->authorName;
    }
    void SetAuthorName(string authorName) {
        this->authorName = authorName;
    }
    string GetPublishDate() {
        return publishDate;
    }
    void SetPublishDate(string publishDate) {
        this->publishDate = publishDate;
    }
    void print() {
        cout << bookName << ", " << authorName << ", " << publishDate << "." << endl;
    }
    //Private data members
private:
    string bookName;
    string authorName;
    string publishDate;
};

class Books {
public:
    //Public member functions
    void SetBooks() {

        string name, author, publishDate;

        cin.ignore();
        cout << "Enter the title: ";
        getline(cin, name);
        cout << "Enter the author: ";
        getline(cin, author);
        cout << "Enter the publish date: ";
        getline(cin, publishDate);
        Book example(name, author, publishDate);
        books.push_back(example);
        
        return;
    }
    void DeleteBooks(string bookToDelete) {
        for (size_t i = 0; i < books.size(); i++) {
            if (bookToDelete == books.at(i).GetBookName()) {
                books.erase(books.begin() + i);
            }
        }
    }
    void PrintBooks() {
        for (size_t i = 0; i < books.size(); i++) {
            books.at(i).print();
        }
    }
    //Private data members
private:
    vector<Book> books;

};

void WelcomeMessage() {

    //Intro message
    cout << "Welcome to James' book inventory system!" << endl;
    cout << "Press 'q' to exit the program." << endl << endl;

    cout << "To add a book into inventory, enter 'a'" << endl;
    cout << "To remove a book from inventory, enter 'r'" << endl;
    cout << "To print the inventory, enter 'p'" << endl << endl;

}

int main()
{
    string book;
    char response;
    Books theBooks;

    WelcomeMessage();

    cin >> response;

    //Loop while response is not equal to 'q'
    while (response != 'q') {

        //Add a book
        if (response == 'a') {

            theBooks.SetBooks();

            cout << endl << "Enter another command: ";
            cin >> response;
            
        }
        //Remove a book
        else if (response == 'r') {

            cout << "Enter the book name: ";
            cin >> book;

            theBooks.DeleteBooks(book);

            cout << endl << "Enter another command: ";
            cin >> response;
        }
        //Print a book
        else if (response == 'p') {

            theBooks.PrintBooks();

            cout << endl << "Enter another command: ";
            cin >> response;
        }
    }
}
