#include <iostream>
using namespace std;

class Book
{
    int copies;

public:
    Book(int c) : copies(c)
    {
    }

    void display()
    {
        cout << "Copies: " << copies << '\n';
    }
};

int main()
{
    Book b = 5;   // Implicit conversion
    b.display();

    return 0;
}