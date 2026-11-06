#include <iostream>
using namespace std;

class Counter
{
    int value;

public:
    Counter(int v = 0) : value(v) {}

    Counter& operator++()
    {
        ++value;
        return *this;
    }

    Counter operator++(int)
    {
        Counter old = *this;
        ++value;
        return old;
    }

    int getValue() const
    {
        return value;
    }
};

int main()
{
    Counter c(5);

    cout << "Initial: " << c.getValue() << '\n';

    Counter a = ++c;
    cout << "After prefix: " << c.getValue() << '\n';
    cout << "Prefix returned: " << a.getValue() << '\n';

    Counter b = c++;
    cout << "After postfix: " << c.getValue() << '\n';
    cout << "Postfix returned: " << b.getValue() << '\n';

    return 0;
}