#include<iostream>
using namespace std;
int clear(int n,int i){
    int m=~((1<<i+1)-1);
    int c=(n&m);
    return c;
}
int main(){
    int n,i;
    cin>>n>>i;
    cout<<clear(n,i)<<endl;
    return 0;
}