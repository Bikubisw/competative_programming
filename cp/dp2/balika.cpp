#include <bits/stdc++.h>
using namespace std;
int balika(string s1,string s2,int k){
  
    if(s1.length()==0||s2.length()==0){
        if(k>0){
            return INT_MIN;
        }
        else{
            return 0;
        }
     
    }
    if(k==0){
        return 0;
    }
    if(s1[0]!=s2[0]){
        int option1=balika(s1,s2.substr(1),k);
        int option2=balika(s1.substr(1),s2,k);
        return max(option1,option2);
    }else{
        int option1=balika(s1.substr(1),s2.substr(1),k-1)+s1[0];
        int option2=balika(s1,s2.substr(1),k);
        int option3=balika(s1.substr(1),s2,k);
        return max(option1,max(option2,option3));
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        string s1,s2;
        cin>>s1>>s2;
        int k;
        cin>>k;
        cout.flush();
        cout<<balika(s1,s2,k)<<endl;
    }
}
