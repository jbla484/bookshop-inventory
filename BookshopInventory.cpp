#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Books {
public:
    void addBook(string book) {
        books.push_back(book);
        ++count;
    }
    void printBooks() {
        cout << "The books you entered: ";
        for (size_t i = 0; i < books.size() - 1; i++)
        {
            cout << books[i] << ", ";
        }
        cout << books[books.size() - 1] << ".";
    }
private:
    vector<string> books {};
    int count = 0;
};

int main()
{
    string book;
    char response;
    Books currentBook;

    cout << "Welcome to James' book inventory system!" << endl << endl;

    do
    {
        cout << "Enter a book into inventory: " << endl;
        getline(cin, book);
        currentBook.addBook(book);  

        cout << "\nDo you want to add another one? ( y / n )" << endl;
        cin >> response;
        cin.ignore();

    } while (response != 'n');

    currentBook.printBooks();
}
