#include <bits/stdc++.h>
using namespace std;

int main()
{
    int num;
    cin >> num;
    int a[num] = {1};

    for (int i = 0; i < num; i++)
    {
        for (int j = i; j > 0; j--)
        {
            a[j] += a[j - 1];
        }
        for (int j = 0; j <= i; j++)
        {
            cout << a[j] << " ";
        }
        cout << endl;
    }
}