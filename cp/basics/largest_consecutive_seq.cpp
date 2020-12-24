#include <bits/stdc++.h>
using namespace std;
vector<int> longestConsecutiveIncreasingSequence (int *arr,int n)
{
    unordered_map<int ,bool> mp;
    unordered_map<int,int> index;
    for(int i=0;i<n;i++){
        index[arr[i]]=i;
        if(mp.count(arr[i])==0){
            mp[arr[i]] = true;
        }
    }
    int globalstartindex=0;
    int maxlength=1;
    for(int i=0;i<n;i++){
        int currlength=0;
        int currentindex=i;
        int currentnumber=arr[i];
        int startnumber=currentnumber;
        // for forward
        while(mp.count(currentnumber)==1&&mp[currentnumber]==true){
            mp[currentnumber] = false;
            currlength++;
            currentnumber++;
        }
        currentnumber=startnumber-1;
        while(mp.count(currentnumber)==1&&mp[currentnumber]==true){
            mp[currentnumber]=false;
            currlength++;
            currentindex = index[currentnumber];
            currentnumber--;
        }
        if(currlength>maxlength){
            maxlength=currlength;
            globalstartindex=currentindex;
        }else if(currlength==maxlength){
            if(globalstartindex>currentindex){
                globalstartindex=currentindex;
            }
        }
    }
    vector<int> output;
    int number=arr[globalstartindex];
    for(int i=0;i<maxlength;i++){
        output.push_back(number);
        number++;
    }
    return output;
}
int main()
{
    int size;

    cin >> size;
    int *arr = new int[size];
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    vector<int> ans = longestConsecutiveIncreasingSequence(arr, size);

    for (auto it = ans.cbegin(); it != ans.cend(); it++)
    {
        cout << *it << endl;
    }

    delete arr;
}