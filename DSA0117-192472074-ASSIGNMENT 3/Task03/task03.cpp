#include <iostream>
using namespace std;

class SeatMap
{
private:
    int rows;
    int cols;
    bool** seats;

public:
    // Dynamic constructor
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

    // Book a seat
    void book(int r, int c)
    {
        if (r < 0 || r >= rows || c < 0 || c >= cols)
        {
            cout << "Invalid seat.\n";
            return;
        }

        if (seats[r][c])
        {
            cout << "Seat already booked.\n";
        }
        else
        {
            seats[r][c] = true;
            cout << "Seat (" << r << ", " << c
                 << ") booked.\n";
        }
    }

    // Cancel a seat
    void cancel(int r, int c)
    {
        if (r < 0 || r >= rows || c < 0 || c >= cols)
        {
            cout << "Invalid seat.\n";
            return;
        }

        if (!seats[r][c])
        {
            cout << "Seat is already available.\n";
        }
        else
        {
            seats[r][c] = false;
            cout << "Seat (" << r << ", " << c
                 << ") cancelled.\n";
        }
    }

    // Display seat map
    void display() const
    {
        cout << "\nSeat Map\n";
        cout << "--------\n";

        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                cout << (seats[i][j] ? "[X] " : "[ ] ");
            }

            cout << '\n';
        }
    }

    // Destructor
    ~SeatMap()
    {
        for (int i = 0; i < rows; ++i)
        {
            delete[] seats[i];
        }

        delete[] seats;

        cout << "\nSeatMap memory released.\n";
    }
};

int main()
{
    cout << "DYNAMIC SEAT MAP\n";
    cout << "================\n";

    SeatMap cinema(3, 4);

    cinema.display();

    cinema.book(0, 1);
    cinema.book(1, 2);
    cinema.book(2, 3);

    cinema.display();

    cinema.book(0, 1);

    cinema.cancel(1, 2);

    cinema.display();

    cinema.cancel(1, 2);

    return 0;
}