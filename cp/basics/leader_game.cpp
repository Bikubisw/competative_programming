#include <bits/stdc++.h>
using namespace std;
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   int p1currscore=0;
   int p2currscore=0;
   int maxlead=0;
   int player=1;
   int n;
   cin>>n;
   while(n--){
       int p1score;int p2score;
       cin>>p1score>>p2score;
       p1currscore+=p1score;
       p2currscore+=p2score;
       int currlead=0;
       int currleadplayer=1;
       if(p1currscore>=p2currscore){
           currlead=p1currscore-p2currscore;

       }else{
           currleadplayer=2;
           currlead=p2currscore-p1currscore;
       }
       if(currlead>maxlead){
           maxlead=currlead;
           player=currleadplayer;
       }
   }
   cout<<player<<" "<<maxlead<<endl;

    
   }