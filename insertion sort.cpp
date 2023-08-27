#include<iostream>
using namespace std;

void insertionSort(int arr[], int n){
    for(int i=1; i<n; i++){
        int temp= arr[i];
        int j=i-1;
        for(; j>=0; j--){
            if(arr[j]>temp){
                arr[j+1]= arr[j]; //shift
            }
            else{
                break;
            }
        }
        arr[j+1]= temp;
    }
}

void printArray(int arr[], int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    int arr[]= {1,7,6,10,9,14};
    insertionSort(arr, 6);
    printArray(arr, 6);

    return 0;
}

