#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("sitin.txt", "r", stdin);
    freopen("sitout.txt", "w", stdout);
    int r,s;
    cin>>r>>s;
    int num=r*s;
    int tic;
    cin>>tic;
    if (num >= tic)
    {
        cout << num << " " << 0 << endl;
    }
    else{
        cout << num << " " << (tic -num) << endl;
    }
    return 0;
}