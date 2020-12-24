#include<bits/stdc++.h>
using namespace std;
bool compare(pair<string ,double>a ,pair<string,double> b){
    return a.second>b.second;
}
int main(){
    int n;
    vector<vector<string>> over;
    cin>>n;
    while(n+1>0){
        string s;
        getline(cin,s);
        vector<string> current;
        string word="";
        for(int i=0;i<s.length();i++){
            if(s[i]==' '){
                current.push_back(word);
                word="";
            }else{
                word=word+s[i];

            }
        }
        current.push_back(word);
        over.push_back(current);
        n--;
    }
    vector<pair<string,double>> output;
    for(int i=0;i<over.size();i++){
        double totalnumber = 0;
        for(int j=1;j<over[i].size();j++){
            string num=over[i][j];
            //cout<<num<<endl;
            int k=num.length()-1;
            double number=0;
            for(int i=0;i<num.length();i++){
                number=number+((num[i]-'0')*pow(10,k));
                k--;
            }
            totalnumber+=number;
        }
        double number1=totalnumber/3;
        if(number1!=0){
        pair<string, double> pai = {over[i][0], number1};
        output.push_back(pai);  }   
}
// for(int i=0;i<output.size();i++){
//     cout<<output[i].first<<":"<<output[i].second<<endl;
// }
sort(output.begin(),output.end(),compare);
for(int i=0;i<output.size();i++){
    cout<<i+1<<" "<<output[i].first<<endl;
}
}