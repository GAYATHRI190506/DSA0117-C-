#include <iostream>
using namespace std;

int main()
{
    int* values = new int[5];

    for (int i = 0; i < 5; ++i)
    {
        values[i] = i + 1;
    }

    cout << "Array values: ";

    for (int i = 0; i < 5; ++i)
    {
        cout << values[i] << " ";
    }

    cout << "\n";

    // Correct way to release memory allocated with new[]
    delete[] values;

    cout << "Array memory released correctly.\n";

    return 0;
}