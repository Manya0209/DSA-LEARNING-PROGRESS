#include<iostream>
using namespace std;

void bubbleSort(int arr[], int n){
    bool swapped= false;
    for(int i =0; i<n; i++){
        for(int j=0; j<n-i; j++){
            if(arr[j+1]<arr[j]){
                swap(arr[j], arr[j+1]);
                swapped= true;
            }
        }
        if(swapped==false){
            break;
        }
    }
}

void printArray(int arr[], int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    int arr[]= {1,7,6,10,9,14};
    bubbleSort(arr, 6);
    printArray(arr, 6);

    return 0;
}