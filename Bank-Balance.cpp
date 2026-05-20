#include <iostream>
#include <unordered_map>
#include <sstream>
using namespace std;

class Bank
{
public:
    unordered_map<string, long long> accounts;

    bool CREATE(string id, long long money)
    {
        if (accounts.count(id) == 0)
        {
            accounts[id] = money;
            return true;
        }

        accounts[id] = accounts[id] + money;
        return false;
    }

    bool DEBIT(string id, long long money)
    {
        if (accounts.count(id) == 0)
        {
            return false;
        }

        if (accounts[id] >= money)
        {
            accounts[id] = accounts[id] - money;
            return true;
        }

        return false;
    }

    bool CREDIT(string id, long long money)
    {
        if (accounts.count(id) == 0)
        {
            return false;
        }

        accounts[id] = accounts[id] + money;
        return true;
    }

    long long BALANCE(string id)
    {
        if (accounts.count(id) == 0)
        {
            return -1;
        }

        return accounts[id];
    }
};

int main()
{
    int q;
    cin >> q;
    cin.ignore();

    Bank b;

    while (q--)
    {
        string line;
        getline(cin, line);

        stringstream ss(line);

        string type;
        string id;
        long long money;

        ss >> type;

        if (type == "CREATE")
        {
            ss >> id >> money;

            bool ans = b.CREATE(id, money);

            if (ans)
            {
                cout << "true" << endl;
            }
            else
            {
                cout << "false" << endl;
            }
        }

        else if (type == "DEBIT")
        {
            ss >> id >> money;

            bool ans = b.DEBIT(id, money);

            if (ans)
            {
                cout << "true" << endl;
            }
            else
            {
                cout << "false" << endl;
            }
        }

        else if (type == "CREDIT")
        {
            ss >> id >> money;

            bool ans = b.CREDIT(id, money);

            if (ans)
            {
                cout << "true" << endl;
            }
            else
            {
                cout << "false" << endl;
            }
        }

        else if (type == "BALANCE")
        {
            ss >> id;

            cout << b.BALANCE(id) << endl;
        }
    }

    return 0;
}