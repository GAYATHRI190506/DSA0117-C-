#include <iostream>
#include <string>
using namespace std;

class Time
{
    int hours;
    int minutes;

    void normalize()
    {
        hours += minutes / 60;
        minutes %= 60;

        if (minutes < 0)
        {
            minutes += 60;
            hours--;
        }
    }

public:
    Time(int h = 0, int m = 0)
        : hours(h), minutes(m)
    {
        normalize();
    }

    // Prefix ++
    Time& operator++()
    {
        ++minutes;
        normalize();
        return *this;
    }

    // Postfix ++
    Time operator++(int)
    {
        Time old = *this;
        ++(*this);
        return old;
    }

    bool operator==(const Time& other) const
    {
        return hours == other.hours &&
               minutes == other.minutes;
    }

    bool operator<(const Time& other) const
    {
        if (hours != other.hours)
            return hours < other.hours;

        return minutes < other.minutes;
    }

    friend ostream& operator<<(ostream& out, const Time& t)
    {
        out << t.hours << "h " << t.minutes << "m";
        return out;
    }
};

class Playlist
{
    string songs[5];

public:
    Playlist()
    {
        songs[0] = "Song A";
        songs[1] = "Song B";
        songs[2] = "Song C";
        songs[3] = "Song D";
        songs[4] = "Song E";
    }

    string& operator[](int index)
    {
        if (index < 0 || index >= 5)
            throw out_of_range("Invalid playlist index");

        return songs[index];
    }

    const string& operator[](int index) const
    {
        if (index < 0 || index >= 5)
            throw out_of_range("Invalid playlist index");

        return songs[index];
    }
};

int main()
{
    cout << "TIME OPERATOR TEST\n";
    cout << "==================\n\n";

    Time t1(1, 59);

    cout << "Initial time: " << t1 << '\n';

    ++t1;
    cout << "After prefix ++: " << t1 << '\n';

    Time t2 = t1++;
    cout << "Returned by postfix ++: " << t2 << '\n';
    cout << "After postfix ++: " << t1 << '\n';

    Time t3(2, 0);

    cout << "t1 == t3 : "
         << (t1 == t3 ? "true" : "false") << '\n';

    cout << "t1 < t3 : "
         << (t1 < t3 ? "true" : "false") << '\n';

    cout << "\nPLAYLIST SUBSCRIPT TEST\n";
    cout << "=======================\n\n";

    Playlist playlist;

    cout << "Song 0: " << playlist[0] << '\n';
    cout << "Song 2: " << playlist[2] << '\n';

    playlist[2] = "Updated Song C";

    cout << "After modification: "
         << playlist[2] << '\n';

    try
    {
        cout << playlist[10] << '\n';
    }
    catch (const out_of_range& e)
    {
        cout << "Exception: " << e.what() << '\n';
    }

    return 0;
}