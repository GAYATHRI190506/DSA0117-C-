#include <iostream>
using namespace std;

class SeatMap
{
    int rows;
    int cols;
    bool** seats;

public:
    SeatMap(int r, int c)
        : rows(r), cols(c)
    {
        seats = new bool*[rows];

        for (int i = 0; i < rows; ++i)
        {
            seats[i] = new bool[cols];

            for (int j = 0; j < cols; ++j)
            {
                seats[i][j] = false;
            }
        }
    }

    void display() const
    {
        cout << "Rows: " << rows << '\n';
        cout << "Columns: " << cols << '\n';

        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                cout << (seats[i][j] ? "[X] " : "[ ] ");
            }

            cout << '\n';
        }
    }

    ~SeatMap()
    {
        for (int i = 0; i < rows; ++i)
        {
            delete[] seats[i];
        }

        delete[] seats;

        cout << "Memory released successfully.\n";
    }
};

int main()
{
    cout << "ZERO-ROW TEST\n";
    cout << "=============\n";

    SeatMap emptyMap(0, 4);

    emptyMap.display();

    return 0;
}