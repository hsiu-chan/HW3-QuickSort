#include<iostream>
#include "QuickSort.h"
using namespace std;

int main(){
    const int arrSize=9;
    int arr[arrSize]={10,2,3,6,5,2,1,9,7};
    QuickSort A(arr,arrSize);
    A.sort();
    for (auto i:arr){
        cout<<i<<",";
    }
    //cout<<((arr+1)<(arr+2));

    
}
