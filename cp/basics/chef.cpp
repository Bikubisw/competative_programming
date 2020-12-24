#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<pair<int,int>> input;
        for(int i=0;i<n;i++){
            int first,second;
            cin>>first>>second;
            input.push_back(make_pair(first,second));
        }
        sort(input.begin(),input.end());
        for(int i=0;i<m;i++){
            int curr;
            cin>>curr;
            int pos=lower_bound(input.begin(),input.end(),make_pair(curr,0))-input.begin();
            if(pos==0){
                int ans=input[0].first-curr;
                cout<<ans<<endl;
            }else{
                int ans=-1;
                if(input[pos-1].second>curr){
                    ans=0;
                }else if(pos<input.size()){
                    ans=input[pos].first-curr;
                }
                cout << ans << endl;
            }
        }





    }
    return 0;
}