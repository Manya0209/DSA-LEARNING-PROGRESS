#include<iostream>
using namespace std;

void movezeroes(int arr[], int n){
    int nonZero= 0;
     for(int j=0; j<n; j++){
        if(arr[j] != 0){
            swap(arr[j], arr[nonZero]);
            nonZero++;
        }
     }
}


void printArray(int arr[], int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}


int main(){
    int arr[]= {0,1,0,3,12,0};
    
    movezeroes(arr, 6);

    printArray(arr, 6);

    return 0;
}