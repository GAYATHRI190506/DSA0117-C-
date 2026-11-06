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

    Text(const Text& other)
    {
        data = new char[strlen(other.data) + 1];
        strcpy(data, other.data);
    }

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

    bool operator==(const Text& other) const
    {
        return strcmp(data, other.data) == 0;
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
    cout << "EDGE CASE TEST\n";
    cout << "==============\n\n";

    Text empty("");
    Text hello("Hello");

    cout << "Empty text: [" << empty << "]\n";
    cout << "Hello text: [" << hello << "]\n";

    Text combined = empty + hello;

    cout << "Empty + Hello: ["
         << combined << "]\n";

    Text emptyCopy(empty);

    cout << "Empty copy: ["
         << emptyCopy << "]\n";

    cout << "empty == emptyCopy: "
         << (empty == emptyCopy ? "true" : "false")
         << '\n';

    Text longText(
        "This is a long text used to verify "
        "dynamic character array allocation "
        "and operator overloading.");

    cout << "Long text: [" << longText << "]\n";

    return 0;
}