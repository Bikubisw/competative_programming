#include<iostream>
using namespace std;
int partition(int *arr,int start,int end){
int count=0;
int pivot=arr[start];
for(int i=start+1;i<=end;i++){
    if(arr[i]<=pivot){
        count++;
    }
}
int pivotindex=start+count;
arr[start]=arr[pivotindex];
arr[pivotindex]=pivot;
int i=start;
int j=end;
while(i<pivotindex&&j>pivotindex){
if(arr[i]<=pivot){
    i++;
}
else if(arr[j]>pivot){
    j--;
}
else{
    int temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
    i++;
    j--;
}
}
return pivotindex;    

}
void quickSorthelper(int *arr, int start, int end) {
    if(start>=end){
        return ;
    }
    int c=partition(arr,start,end);
    quickSorthelper(arr,start,c-1);
    quickSorthelper(arr,c+1,end);
}
void quickSort(int *arr, int n) {
    quickSorthelper(arr,0,n-1);

}

int main(){
    int n;
    cin >> n;
  
    int *input = new int[n];
    
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    
    quickSort(input, n);
    for(int i = 0; i < n; i++) {
        cout << input[i] << " ";
    }
    
    delete [] input;

}


