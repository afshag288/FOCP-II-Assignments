#include <iostream>
#include <vector>
using namespace std;

const int SIZE = 10000000;

int arr[SIZE + 1];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // count distinct prime factors
    for (int i = 2; i <= SIZE; i++)
    {
        if (arr[i] == 0)
        {
            int j = i;

            while (j <= SIZE)
            {
                arr[j] = arr[j] + 1;
                j = j + i;
            }
        }
    }

    vector<int> power(25);

    power[0] = 1;

    for (int i = 1; i < 25; i++)
    {
        power[i] = power[i - 1] * 2;
    }

    int t;
    cin >> t;

    while (t > 0)
    {
        int n;
        cin >> n;

        int factors = arr[n];

        cout << power[factors] << endl;

        t--;
    }

    return 0;
}