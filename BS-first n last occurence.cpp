#include<iostream>
using namespace std;

int firstOcc(int arr[], int size, int key){
    int start= 0;
    int end= size-1;
    int ans= -1;

    int  mid= start+ (end - start)/2; // if start= 2^31-1, end= 2^31-1

    while(start<=end){
        if(arr[mid]==key){
            ans= mid;
            end= mid -1;
        }
        if(key> arr[mid]){
            start= mid+1;
        }
        else{
            end= mid-1;
        }
        mid= start+ (end - start)/2;
    }
    return ans;
}

int lastOcc(int arr[], int size, int key){
    int start= 0;
    int end= size-1;
    int ans= -1;

    int  mid= start+ (end - start)/2; // if start= 2^31-1, end= 2^31-1

    while(start<=end){
        if(arr[mid]==key){
            ans= mid;
            start= mid+1;
        }
        if(key> arr[mid]){
            start= mid+1;
        }
        else{
            end= mid-1;
        }
        mid= start+ (end - start)/2;
    }
    return ans;
}

int main(){
    int arr[]= {1,2,3,3,3,3,5};

    cout<<"first occurence of 3 is at index "<<firstOcc(arr, 7, 3)<<endl;
    cout<<"last occurence of 3 is at index "<<lastOcc(arr, 7, 3)<<endl;

    return 0;
}
