#include <bits/stdc++.h>
using namespace std;
bool func(int *arr, int n)
{
    for (int i = 1; i < n; i++)
    {
        if (arr[i] == arr[i - 1] - 1)
        {
            int temp = arr[i - 1];
            arr[i - 1] = arr[i];
            arr[i] = temp;
        }
    }
    for (int i = 1; i < n; i++)
    {
        if (arr[i] - arr[i - 1] != 1)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int *arr = new int[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        bool ans = func(arr, n);
        if (ans)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }

    return 0;
}
