#include<bits/stdc++.h>
using namespace std;
class student{
    public:
    string name;
    int roll;
    int totalmarks;
};
bool compare(student *s1, student *s2)
{
    if(s1->totalmarks!=s2->totalmarks){
        return s1->totalmarks>s2->totalmarks;
    }
    return s1->roll<s2->roll;
}
int main(){
    int n;
    cin>>n;
    student** students=new student*[n];
    for(int i=0;i<n;i++){
        students[i]=new student();
    }
    for(int i=0;i<n;i++){
        cin>>students[i]->name;
        students[i]->roll=i+1;
        int m1,m2,m3;
        cin>>m1>>m2>>m3;
        int total=(m1+m2+m3);
        students[i]->totalmarks=total;
    }
    sort(students, students + n, compare);
    for(int i=0;i<n;i++){
        cout<<(i+1)<<" "<<students[i]->name<<endl;
    }

    return 0;
}