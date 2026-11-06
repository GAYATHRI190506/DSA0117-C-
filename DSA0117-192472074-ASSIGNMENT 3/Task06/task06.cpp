#include <iostream>
#include <cstring>
using namespace std;

class Text
{
private:
    char* data;

public:
    // Default / parameterized constructor
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

    // Copy assignment operator - Deep Copy
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

    // Destructor
    ~Text()
    {
        delete[] data;
    }

    // + operator
    Text operator+(const Text& other) const
    {
        size_t length =
            strlen(data) + strlen(other.data);

        char* combined = new char[length + 1];

        strcpy(combined, data);
        strcat(combined, other.data);

        Text result(combined);

        delete[] combined;

        return result;
    }

    // == operator
    bool operator==(const Text& other) const
    {
        return strcmp(data, other.data) == 0;
    }

    // != operator
    bool operator!=(const Text& other) const
    {
        return !(*this == other);
    }

    // << operator
    friend ostream& operator<<(ostream& out,
                               const Text& text)
    {
        out << text.data;
        return out;
    }

    // Accessor for testing
    const char* c_str() const
    {
        return data;
    }
};

int main()
{
    cout << "TEXT OPERATOR OVERLOADING\n";
    cout << "=========================\n\n";

    Text t1("Hello ");
    Text t2("World");

    cout << "Text 1: " << t1 << '\n';
    cout << "Text 2: " << t2 << '\n';

    Text t3 = t1 + t2;

    cout << "Concatenated: " << t3 << '\n';

    cout << "t1 == t2 : "
         << (t1 == t2 ? "true" : "false") << '\n';

    cout << "t1 != t2 : "
         << (t1 != t2 ? "true" : "false") << '\n';

    return 0;
}