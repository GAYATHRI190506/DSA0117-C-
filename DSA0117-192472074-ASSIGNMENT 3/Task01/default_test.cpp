#include <iostream>
#include <string>
using namespace std;

class Book
{
    string title;
    int copies;

public:
    Book(const string& t, int c)
        : title(t), copies(c)
    {
    }
};

int main()
{
    Book books[3];

    return 0;
}