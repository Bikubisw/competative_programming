 
#include <iostream> 
using namespace std; 
int main() 
{ 
    int x = 1000000; 
    int y = 1000000; 
  
    // This causes overflow even 
    // if z is long long int 
    long long int z =(long long)x*y; 
  
    cout << z; 
    return 0; 
} 