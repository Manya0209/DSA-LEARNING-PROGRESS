#include<iostream>
using namespace std;

//not getting answer

void rotateArray(int arr[], int n, int k){
    int temp[n]= {0};

    for(int i=0; i<n; i++){
        temp[(i+k)%n]= arr[i];
    }

    arr= temp;

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}

// void printArray(int arr[], int n){
//     for(int i=0; i<n; i++){
//         cout<<arr[i]<<" ";
//     }
// }

int main(){
    int arr[]= {11,12,13,14};

    rotateArray(arr, 4, 2);

    // printArray(arr, 4);

    return 0;
}