#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 10001
int memo[MAX][MAX / 2 + 2] = {0};
int salary(int arr[][MAX], int index, int diff, int total)
{
    if (index == total)
    {
        return 0;
    }
    if (memo[index][diff] != 0)
    {
        return memo[index][diff];
    }
    if (diff == 0)
    {
        int ans = arr[1][index] + salary(arr, index + 1, 1, total);
        memo[index][diff] = ans;
        return ans;
    }
    if (diff == (total - index))
    {
        int ans = 0;
        int x = index;
        while (x < total)
        {
            ans += arr[0][x];
            x++;
        }
        memo[index][diff] = ans;
        return ans;
    }
    else
    {
        int option1 = arr[0][index]+ salary(arr,index + 1, diff - 1, total);
        int option2 = arr[1][index] + salary(arr,index + 1, diff + 1, total);
        int ans = min(option1, option2);
        memo[index][diff] = ans;
        return ans;
    }
}
int main()
{
    int n;
    cin >> n;
    int arr[2][MAX];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[0][i];
        cin>>arr[1][i];
    }
    cout << salary(arr, 0, 0, n) << endl;

    return 0;
}