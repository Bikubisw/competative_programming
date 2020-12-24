#include<iostream>
using namespace std;
int subs(string input,string output[]){
    if(input.length()==0){
        output[0]="";
        return 1;
    }
    int smallans=subs(input.substr(1),output);
    for(int i=0;i<smallans;i++){
        output[i+smallans]=input[0]+output[i];
    }
    return 2*smallans;
}
int main(){
    string input;
    getline(cin,input);
    string ouput[1000];
    int ans=subs(input, ouput);
    for (int i=0;i<ans;i++) {
        cout<<ouput[i]<<endl;
    }
    return 0;
}