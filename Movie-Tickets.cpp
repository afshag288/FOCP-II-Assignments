#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class MovieTicket
{
public:
    unordered_map<int, unordered_set<int>> users;
    unordered_map<int, int> seats;

    bool BOOK(int user, int movie)
    {
        if (seats.count(movie) == 0)
        {
            seats[movie] = 100;
        }

        if (users[movie].count(user) != 0)
        {
            return false;
        }

        if (seats[movie] <= 0)
        {
            return false;
        }

        users[movie].insert(user);
        seats[movie] = seats[movie] - 1;

        return true;
    }

    bool CANCEL(int user, int movie)
    {
        if (users[movie].count(user) == 0)
        {
            return false;
        }

        users[movie].erase(user);
        seats[movie] = seats[movie] + 1;

        return true;
    }

    bool IS_BOOKED(int user, int movie)
    {
        if (users[movie].count(user))
        {
            return true;
        }

        return false;
    }

    int AVAILABLE_TICKETS(int movie)
    {
        if (seats.count(movie) == 0)
        {
            return 100;
        }

        return seats[movie];
    }
};

int main()
{
    int q;
    cin >> q;

    MovieTicket m;

    while (q > 0)
    {
        string type;
        cin >> type;

        if (type == "BOOK")
        {
            int user, movie;
            cin >> user >> movie;

            bool ans = m.BOOK(user, movie);

            if (ans)
            {
                cout << "true" << endl;
            }
            else
            {
                cout << "false" << endl;
            }
        }

        else if (type == "CANCEL")
        {
            int user, movie;
            cin >> user >> movie;

            bool ans = m.CANCEL(user, movie);

            if (ans)
            {
                cout << "true" << endl;
            }
            else
            {
                cout << "false" << endl;
            }
        }

        else if (type == "IS_BOOKED")
        {
            int user, movie;
            cin >> user >> movie;

            bool ans = m.IS_BOOKED(user, movie);

            if (ans)
            {
                cout << "true" << endl;
            }
            else
            {
                cout << "false" << endl;
            }
        }

        else if (type == "AVAILABLE_TICKETS")
        {
            int movie;
            cin >> movie;

            cout << m.AVAILABLE_TICKETS(movie) << endl;
        }

        q--;
    }

    return 0;
}