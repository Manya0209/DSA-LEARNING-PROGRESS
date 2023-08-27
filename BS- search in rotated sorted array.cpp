#include<iostream>
using namespace std;

int getpivot(int arr[], int size){
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

int binarysearch(int arr[], int start, int end, int key){
   

   // int mid= (start+end)/2;
    int  mid= start+ (end - start)/2; // if start= 2^31-1, end= 2^31-1

    while(start<=end){
        if(arr[mid]==key){
            return mid;
        }
        if(key> arr[mid]){
            start= mid+1;
        }
        else{
            end= mid-1;
        }
        //mid= (start+end)/2;
        mid= start+ (end - start)/2;
    }
    return -1;
}

int findPosition(int arr[], int size, int key){
    int pivot= getpivot(arr, size);
    if(key>=pivot && key<=size){
        return binarysearch(arr, pivot, size, key);
    }
    else{
        return binarysearch(arr, 0, pivot-1, key);
    }
}

int main(){
    int arr[]= {7,9,1,2,3};

    int t= findPosition(arr, 5, 2);

    cout<<"target is at "<<t;

    return 0;
}