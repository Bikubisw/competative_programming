#include<bits/stdc++.h>
typedef long long ll;
class knap{
  public:
	int time;
	int cost;
	int speed;
	knap(int time,int cost,int speed){
	this->time=time;
	this->cost=cost;
	this->speed=speed;	
}

};
bool compare(knap a ,knap b){
 if(a.time==b.time){
if(a.speed==b.speed){
 return a.cost<b.cost;
}
 return a.speed>b.speed;
}
  return a.time<b.time;
}
using namespace std;
int main() {
ios_base::sync_with_stdio(false);
cin.tie(0);
int n;
cin>>n;
ll d;
cin>>d;
vector<knap> input;
int T,x,y;
for(int i=0;i<n;i++){
 cin>>T>>x>>y;
input.push_back(knap(T,x,y));

}
sort(input.begin(),input.end(),compare);
ll bestspeed=0,area=0,cost=0,lasttime=input[0].time;
for(int i=0;i<n;i++){
 ll addition=bestspeed*1LL*(input[i].time-lasttime);
 area+=addition;
if(area>=d){
   break;
  }
if(input[i].speed>bestspeed){
 bestspeed=input[i].speed;
cost+=input[i].cost;
}
  lasttime=input[i].time;
}
 cout<<cost<<endl;


 return 0;

}