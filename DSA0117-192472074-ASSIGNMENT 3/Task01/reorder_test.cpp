#include <iostream>
using namespace std;

class Test
{
    int first;
    int second;

public:
    // Declaration order: first, second
    // Initializer list is intentionally in the wrong order.
    Test() : second(20), first(10)
    {
    }

    void display()
    {
        cout << "first = " << first << '\n';
        cout << "second = " << second << '\n';
    }
};

int main()
{
    Test t;
    t.display();

    return 0;
}