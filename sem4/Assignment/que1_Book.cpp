#include <iostream>
#include <string>

using namespace std;

class Book
{
    string title;
    string author;
    string isbn;
    bool isAvailable;

public:
    Book(string title, string author, string isbn, bool isAvailable)
    {
        this->author = author;
        this->isAvailable = isAvailable;
        this->isbn = isbn;
        this->title = title;
    }

    string getIsBn()
    {
        return isbn;
    }
    bool ChangeAva(bool state)
    {
        isAvailable = state;
    }
    bool getAva()
    {
        return isAvailable;
    }
    void allDetails()
    {
        cout << "\t The title of books: " << title << endl;
        cout << "\t The author of books: " << author << endl;
    }
};

class Library
{
    Book *Books[100];
    int top;

public:
    Library()
    {
        top = 0;
    }
    void addBook(string title, string author, string isbn)
    {
        if (top == 99)
        {
            cout << "No more books can be added" << endl;
        }
        else
        {
            Books[top] = new Book(title, author, isbn, true);
            top += 1;
            cout << "Book added" << endl;
        }
    }

    void borroWBook(string ISBN)
    {
        for (int i = 0; i < top; i++)
        {
            if (Books[i]->getIsBn() == ISBN)
            {
                if (Books[i]->getAva())
                {
                    Books[i]->ChangeAva(false);
                    cout << "Available" << endl;
                    break;
                }
                else
                {
                    cout << "Not Available" << endl;
                }
            }
        }
    }
    void returnBook(string ISBN)
    {
        for (int i = 0; i < top; i++)
        {
            if (Books[i]->getIsBn() == ISBN)
            {
                if(!Books[i]->getAva()){
                    Books[i]->ChangeAva(true);
                }
            }
        }
    }
    void displayBooks()
    {
        cout << "Available Books" << endl;
        if (top == 0)
        {
            cout << "NO Books Available" << endl;
            return;
        }
        for (int i = 0; i < top; i++)
        {
            if (Books[i]->getAva())
            {
                cout << "Books :" << endl;
                Books[i]->allDetails();
            }
        }
    }
};

int main()
{
    Library lib;
    bool check = true;
    int choice;
    while (check)
    {
        cout << "Menu:\n";
        cout << "1. Add a book\n";
        cout << "2. Borrow a book\n";
        cout << "3. Return a book\n";
        cout << "4. Display available books\n";
        cout << "5. Exit the program\n";
        cout << "Enter your choice: ";
        cin >> choice;
        if (choice == 1)
        {
            lib.addBook("The Great Gatsby", "F. Scott Fitzgerald", "9780743273565");
            lib.addBook("To Kill a Mockingbird", "Harper Lee", "9780061120084");
            lib.addBook("1984", "George Orwell", "9780451524935");
        }
        else if (choice == 2)
        {
            lib.borroWBook("9780743273565");
        }
        else if (choice == 4)
        {
            lib.displayBooks();
        }
        else if(choice == 3){
            lib.returnBook("9780743273565");
        }
        else
        {
            break;
        }
    }
}