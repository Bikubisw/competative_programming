#include<iostream>
using namespace std;
string getstring(int num){
    if(num==2){
        return "abc";
    }
    if (num==3) {
        return "def";
    }
    if (num==4) {
        return "ghi";
    }
    if (num==5) {
        return "jkl";
    }
    if (num==6) {
        return "mno";
    }
    if (num==7) {
        return "pqrs";
    }
    if (num==8) {
        return "tuv";
    }
    if (num==9) {
        return "wxyz";
    }
    return "";

}
int keypad(int num,string output[]){
    if(num==0)
    {
        output[0]="";
        return 1;
    }
    int smallnumber=num/10;
    int smallnumsize=keypad(smallnumber, output);
    string options=getstring(num%10);
    for (int i=0;i<options.length()-1;i++) {
        for (int j=0;j<smallnumsize;j++){
            output[j+(i+1)*smallnumsize]=output[j];
        }
    }
    int k=0;
    for(int i=0;i<options.length();i++){
        for(int j=0;j<smallnumsize;j++){
            output[k]=output[k]+options[i];
            k++;
        }
    }
    return smallnumsize*options.length();
}
int main(){
    int num;
    cin >> num;

    string output[10000];
    int count = keypad(num, output);
    for (int i = 0; i < count && i < 10000; i++) {
        cout << output[i] << endl;
    }
    return 0;
}