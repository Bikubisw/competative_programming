#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    int x,y;
    cin>>n>>x>>y;
    string s;
    cin>>s;
    int group=0;
    if(s[0]=='0'){
        group+=1;
    }
    for(int i=1;i<s.length();i++){
        if(s[i]=='1'&&s[i+1]=='0'){
            group+=1;
        }
    }
    long ans=0;
    if(group!=0){
        ans=(group-1)*min(x,y)+y;
    }
    cout<<ans<<endl;

    return 0;
}
