#include <iostream>
#include <algorithm>
using namespace std;
void FindTriplet(int arr[], int size, int x)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            for (int k = j + 1; k < size; k++)
            {
                if (arr[i] + arr[j] + arr[k] == x)
                {
                    int minimum = min(arr[i], min(arr[j], arr[k]));
                    if (minimum == arr[i])
                    {
                        if (arr[j] < arr[k])
                        {
                            cout << arr[i] << " " << arr[j] << " " << arr[k] << endl;
                        }
                        else
                        {
                            cout << arr[i] << " " << arr[k] << " " << arr[j] << endl;
                        }
                    }
                    else if (minimum == arr[j])
                    {
                        if (arr[i] < arr[k])
                        {
                            cout << arr[j] << " " << arr[i] << " " << arr[k] << endl;
                        }
                        else
                        {
                            cout << arr[j] << " " << arr[k] << " " << arr[i] << endl;
                        }
                    }
                    else
                    {
                        if (arr[j] < arr[i])
                        {
                            cout << arr[k] << " " << arr[j] << " " << arr[i] << endl;
                        }
                        else
                        {
                            cout << arr[k] << " " << arr[i] << " " << arr[j] << endl;
                        }
                    }
                }
            }
        }
    }
}

int main()
{

    int size;

    int x;
    cin >> size;

    int *input = new int[1 + size];

    for (int i = 0; i < size; i++)
        cin >> input[i];
    cin >> x;

    FindTriplet(input, size, x);

    return 0;
}
