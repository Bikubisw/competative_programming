#include<bits/stdc++.h>
using namespace std;
void print(char** input){
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            cout<<input[i][j];
        }
        cout<<endl;
    }
}
bool isvalidVertical(char **arr,int row,int col,vector<string>output,int index){
    string word=output[index];
    int count=0;
    int j=0;
    for(int i=0;i<word.length();i++){
        if(i+row==10){
            return false;
        }
        else if(arr[i+row][col]=='+'){
            return false;
        }
        else if(arr[i+row][col]=='-'||arr[i+row][col]==word[j]){
            count++;
        }
        j++;
    }
    if(count==word.length()){
        return true;
    }else{
        return false;
    }
}
bool isvalidHorizontal(char **arr,int row,int col,vector<string>output,int index){
    string word=output[index];
    int count=0;
    int j=0;
    for (int i=0;i<word.length();i++) {
        if(i+col==10){
            return false;
        }
        if(arr[row][i+col]=='+'){
            return false;
        }
        if (arr[row][i+col]=='-'||arr[row][i+col]==word[j]) {
            count++;
        }
        j++;
    }
    if (count==word.length()) {
        return true;
    }
    else {
        return false;
    }

}
void setvertical(char** arr,int row,int col,vector<string> output,int index,bool helper[]){
    string word=output[index];
    int j=0;
    for(int i=0;i<word.length();i++){
        if(arr[i+row][col]=='-'){
            arr[i+row][col]=word[j];
            j++;
            helper[i]=true;
        }
        else{
            helper[i]=false;
            j++;
        }
    }
}
void sethorizontal(char**arr,int row,int col,vector<string> output,int index,bool helper[]){
        string word=output[index];
        int j=0;
        for(int i=0;i<word.length();i++){
            if(arr[row][i+col]=='-'){
                    arr[row][i+col]=word[j];
                    j++;
                    helper[i]=true;
                }else{
                    helper[i]=false;
                    j++;
                }
            }
}
void resetvertical(char** arr,int row,int col,vector<string> output,int index,bool *helper){
    string word=output[index];
    for(int i=0;i<word.length();i++){
        if(helper[i]==true){
            arr[i+row][col]='-';
        }
    }
}
void resethorizontal(char **arr, int row, int col, vector<string> output, int index, bool *helper)
{
    string word=output[index];
    for(int i=0;i<word.length();i++){
        if(helper[i]==true){
            arr[row][i+col]='-';
        }
    }
}
void crossword(char **arr, vector<string> output, int index)
    {
        if (index == output.size())
        {
            print(arr);
            return;
        }
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                if (arr[i][j] == '-' || arr[i][j] == output[index][0])
                {
                    if (isvalidVertical(arr, i, j, output, index))
                    {
                        bool*helper=new bool [output[index].length()];
                        setvertical(arr, i, j, output, index, helper);
                        crossword(arr, output, index + 1);
                        resetvertical(arr, i, j, output, index, helper);
                    }
                    if(isvalidHorizontal(arr,i,j,output,index)){
                        bool *helper = new bool[output[index].length()];
                        sethorizontal(arr, i, j, output, index, helper);
                        crossword(arr,output,index+1);
                        resethorizontal(arr,i,j,output,index,helper);
                    }
                }
            }
        }
    }
    int main()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        char **input = new char *[10];
        for (int i = 0; i < 10; i++)
        {
            input[i] = new char[10];
            for (int j = 0; j < 10; j++)
            {
                cin >> input[i][j];
            }
        }
        string s;
        cin >> s;
        vector<string> output;
        string word = "";
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == ';')
            {
                output.push_back(word);
                word = "";
                continue;
            }
            word += s[i];
        }
        output.push_back(word);
        crossword(input, output, 0);
        return 0;
    }