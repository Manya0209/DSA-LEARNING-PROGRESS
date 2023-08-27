#include<iostream>
using namespace std;

int binarysearch(int arr[], int size, int key){
    int start= 0;
    int end= size-1;

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

int main(){
    int arr[]= {2, 12, 14, 34, 67};

    int index= binarysearch(arr, 5, 14);
    cout<<"index of 14 is "<<index<<endl;

    return 0;
}
