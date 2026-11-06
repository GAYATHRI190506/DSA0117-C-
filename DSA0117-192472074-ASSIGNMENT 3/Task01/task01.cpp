#include <iostream>
#include <string>
using namespace std;

class Book
{
private:
    string title;
    string author;
    int copies;

    void validateCopies(int c)
    {
        if (c < 0)
        {
            cout << "Invalid number of copies. Setting copies to 0.\n";
            copies = 0;
        }
    }

public:

    // Default constructor
    Book() : Book("", "", 0)
    {
    }

    // Parameterized constructor
    Book(const string& t, const string& a, int c)
        : title(t), author(a), copies(c >= 0 ? c : 0)
    {
        if (c < 0)
        {
            cout << "Invalid number of copies. Setting copies to 0.\n";
        }
    }

    // Constructor for donated book with only title
    Book(const string& t) : Book(t, "Unknown", 1)
    {
    }

    // Constructor for title and author
    Book(const string& t, const string& a)
        : Book(t, a, 0)
    {
    }

    void display() const
    {
        cout << "Title: " << title << '\n';
        cout << "Author: " << author << '\n';
        cout << "Copies: " << copies << '\n';
        cout << "-------------------------\n";
    }
};

int main()
{
    cout << "BOOK RECORDS\n";
    cout << "============\n\n";

    // Default constructor
    Book b1;
    cout << "1. Default Constructor\n";
    b1.display();

    // Parameterized constructor
    Book b2("C++ Programming", "Bjarne Stroustrup", 5);
    cout << "2. Parameterized Constructor\n";
    b2.display();

    // Overloaded constructor - title only
    Book b3("Data Structures");
    cout << "3. Title-only Constructor\n";
    b3.display();

    // Overloaded constructor - title and author
    Book b4("Computer Networks", "Andrew S. Tanenbaum");
    cout << "4. Title and Author Constructor\n";
    b4.display();

    // Negative copies test
    Book b5("Invalid Book", "Test Author", -10);
    cout << "5. Negative Copies Test\n";
    b5.display();

    return 0;
}