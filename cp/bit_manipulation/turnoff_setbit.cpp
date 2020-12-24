#include <iostream>
using namespace std;
int returnFirstSetBit(int n)
{
    int i;
    for (i = 0; i < 32; i++)
    {
        if ((n & (1 << i)) != 0)
        {
            break;
        }
    }
    int ans=n^(1<<i);
    return ans;
}

int main()
{
    int n;

    cin >> n;

    cout << returnFirstSetBit(n) << endl;

    return 0;
}
