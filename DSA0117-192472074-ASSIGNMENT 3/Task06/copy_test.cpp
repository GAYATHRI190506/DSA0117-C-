#include <iostream>
#include <cstring>
using namespace std;

class Text
{
    char* data;

public:
    Text(const char* str = "")
    {
        data = new char[strlen(str) + 1];
        strcpy(data, str);
    }

    // Copy constructor - Deep Copy
    Text(const Text& other)
    {
        data = new char[strlen(other.data) + 1];
        strcpy(data, other.data);
    }

    // Copy assignment - Deep Copy
    Text& operator=(const Text& other)
    {
        if (this != &other)
        {
            char* newData =
                new char[strlen(other.data) + 1];

            strcpy(newData, other.data);

            delete[] data;
            data = newData;
        }

        return *this;
    }

    ~Text()
    {
        delete[] data;
    }

    // Self-assignment test
    void selfAssign()
    {
        *this = *this;
    }

    void set(const char* str)
    {
        delete[] data;

        data = new char[strlen(str) + 1];
        strcpy(data, str);
    }

    friend ostream& operator<<(ostream& out,
                               const Text& text)
    {
        out << text.data;
        return out;
    }
};

int main()
{
    cout << "DEEP COPY TEST\n";
    cout << "==============\n\n";

    Text original("Original Text");

    // Copy constructor
    Text copy(original);

    cout << "Original: " << original << '\n';
    cout << "Copy: " << copy << '\n';

    // Change only the copy
    copy.set("Modified Copy");

    cout << "\nAfter modifying copy:\n";
    cout << "Original: " << original << '\n';
    cout << "Copy: " << copy << '\n';

    // Assignment operator
    Text assigned;
    assigned = original;

    cout << "\nAfter assignment:\n";
    cout << "Original: " << original << '\n';
    cout << "Assigned: " << assigned << '\n';

    // Self-assignment
    original.selfAssign();

    cout << "\nAfter self-assignment:\n";
    cout << "Original: " << original << '\n';

    return 0;
}