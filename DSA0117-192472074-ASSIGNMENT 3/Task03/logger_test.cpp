#include <iostream>
#include <string>
using namespace std;

class Logger
{
    string name;

public:
    Logger(const string& n) : name(n)
    {
        cout << "Construct " << name << '\n';
    }

    ~Logger()
    {
        cout << "Destruct " << name << '\n';
    }
};

int main()
{
    Logger a("A");

    {
        Logger b("B");
        Logger c("C");
    }

    Logger d("D");

    return 0;
}