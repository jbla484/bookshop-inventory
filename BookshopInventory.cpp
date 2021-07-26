#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Books {
//Public member functions
public:
    //Function to add a book to the vector
    void addBook(string book) {
        books.push_back(book);
        ++count;
    }
    //Function to print all books in the vector
    void printBooks() {
        cout << "The books you entered: ";
        for (size_t i = 0; i < books.size() - 1; i++)
        {
            cout << books[i] << ", ";
        }
        cout << books[books.size() - 1] << ".";
    }
//Private data members
private:
    vector<string> books {};
    int count = 0;
};

int main()
{
    string book;
    char response;
    Books currentBook;
    //Intro message
    cout << "Welcome to James' book inventory system!" << endl << endl;
    //Looping until the user enters 'n'
    do
    {
        //Getting input for book, then adding to the vector via function call to addBook()
        cout << "Enter a book into inventory: " << endl;
        getline(cin, book);
        currentBook.addBook(book);  
        //Asking if the user wants to continue to add books
        cout << "\nDo you want to add another one? ( y / n )" << endl;
        cin >> response;
        cin.ignore();

    } while (response != 'n');
    //Function call to print all the books
    currentBook.printBooks();
}
