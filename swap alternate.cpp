#include<iostream>
using namespace std;

void swapAlternate(int arr[], int size){
    for(int i=0; i<size; i=i+2){
        if(i+1<size){
            swap(arr[i], arr[i+1]);
        }
    }
}

void print(int arr[], int size){
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    int arr[8]= {1,2,3,4,5,6,7,8};

    swapAlternate(arr, 8);
    print(arr, 8);

    return 0;
}