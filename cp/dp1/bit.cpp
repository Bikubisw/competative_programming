#include <bits/stdc++.h>
using namespace std;
int lcs(int *input, int n)
{
    int *output = new int[n];
    int *output2=new int[n];
    output[0] = 1;
    output2[0]=1;
    for (int i = 1; i < n; i++)
    {
        output[i] = 1;
        for (int j = i - 1; j >= 0; j--)
        {
            if (input[j] > input[i])
            {
                continue;
            }
            int possibleans = output[j] + 1;
            if (possibleans > output[i])
            {
                output[i] = possibleans;
            }
        }
    }
    for (int i = n-2; i>=0; i--)
    {
        output2[i] = 1;
        for (int j = n - 1; j>i; j--)
        {
            if (input[j] >input[i])
            {
                continue;
            }
            int possibleans = output2[j] + 1;
            if (possibleans > output2[i])
            {
                output2[i] = possibleans;
            }
        }
    }
    int best=output[0]+output2[0]-1;
    for (int i = 1; i < n; i++)
    {
        if (output[i]+ output2[i]-1 > best)
        {
            best = output2[i]+output[i]-1;
        }
    }
    delete[] output;
    delete[] output2;
    return best;
}
int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << lcs(arr, n) << endl;
    delete[]arr;
    return 0;
}