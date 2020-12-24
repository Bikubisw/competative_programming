#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("bendin.txt", "r", stdin);
    freopen("bendout.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int x1,y1,x2,y2;
    int x3,y3,x4,y4;
    cin>>x1>>y1>>x2>>y2;
    cin>>x3>>y3>>x4>>y4;
    int A1=(x2-x1)*(y2-y1);
    int A2=(x4-x3)*(y4-y3);
    int left=max(x1,x3);
    int right=min(x2,x4);
    int top=min(y2,y4);
    int bottom=max(y1,y3);
    int inter=0;
    if((bottom<top)&&(left<right)){
         inter=(top-bottom)*(right-left);
    }
    int ans=A1+A2-inter;
    cout<<ans<<endl;
}