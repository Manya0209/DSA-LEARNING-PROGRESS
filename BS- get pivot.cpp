#include<iostream>
using namespace std;

int pivot(int arr[], int size){
    int start= 0;
    int end= size-1;

    int  mid= start+ (end - start)/2; // if start= 2^31-1, end= 2^31-1

    while(start<=end){
        if(arr[mid]>arr[0]){
            start= mid +1;
        }
        else{
            end= mid;
        }
        mid= start+ (end - start)/2;
    }
    return start;
    //or return end;
}

int main(){
    int arr[]= {3,17,20,1};

    cout<<"pivot is "<< pivot(arr,4);

    return 0;
}