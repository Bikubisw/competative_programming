#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    while((n%2==0)){
        n=n/2;
    }
    if(n==1){
        cout<<"N is power of 2"<<endl;
    }else{
        cout<<"Not power of 2"<<endl;
    }
    return 0;
}