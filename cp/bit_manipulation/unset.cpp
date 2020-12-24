#include <iostream>
using namespace std;
int turnOffIthBit(int n, int i)
{
    int ans;
    int c = n & (1 << i);
    if (c == 0)
    {
        ans = n;
    }
    else
    {
        ans = n ^ (1 << i);
    }
    return ans;
}

int main()
{
    int n, i;

    cin >> n >> i;

    cout << turnOffIthBit(n, i) << endl;

    return 0;
}
