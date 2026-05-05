#include <bits/stdc++.h>
using namespace std;

int main()
{
    int num;
    cin >> num;

    vector<int> r;
    for (int i = 0; i < num; i++)
    {
        r.push_back(1);
        for (int j = i - 1; j > 0; j--)
        {
            r[j] += r[j - 1];
        }
        for (int x : r)
        {
            cout << x << " ";
        }
        cout << endl;
    }
}