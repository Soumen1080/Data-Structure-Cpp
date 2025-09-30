#include<iostream>
using namespace std;

int printSubArray(int arr[] , int n ){ 

for (int start = 0 ; start < n ; start++ ){
for( int end = start ; end < n ; end++){
    for(int i = end ; i < n ; i++){
        cout << arr[i];
    }
cout << ",";
}
cout << endl;
}
return 0;

}
int main(){
int arr[5] = {1,2,3,4,5};
int n = 5 ;
printSubArray(arr , n ) ;

return 0 ; 

}