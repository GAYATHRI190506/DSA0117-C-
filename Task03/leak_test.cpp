#include <iostream>
using namespace std;

class Test
{
    int* data;

public:
    Test()
    {
        data = new int[5];

        for (int i = 0; i < 5; ++i)
        {
            data[i] = i + 1;
        }

        cout << "Memory allocated.\n";
    }

    ~Test()
    {
        delete[] data;
        cout << "Memory released.\n";
    }
};

int main()
{
    Test t;

    cout << "Program running.\n";

    return 0;
}