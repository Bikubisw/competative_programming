#include<iostream>
using namespace std;
void printsub(string s,string output){
    if(s.length()==0){
        cout<<output<<endl;
        return;
    }
    printsub(s.substr(1), output);
    printsub(s.substr(1), output+s[0]);
}
int main() {
    string s;
    cin>>s;
    printsub(s,"");
    return 0;
}