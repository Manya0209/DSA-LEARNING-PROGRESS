#include<iostream>
using namespace std;

bool binarySearch(int arr[], int s, int e, int k){
    //base case
    if(s>e)
    return false;

    int mid = s+ (e-s)/2;

    if (arr[mid] == k)
    return true;

    if(arr[mid]>k){
        binarySearch(arr, s, mid-1, k);
    }
    else{
        binarySearch(arr, mid+1, e, k);
    }
}

int main(){
    int arr[]={2,4,6,10,29,39};
    int n= 6;

    bool ans= binarySearch(arr, 2, 39,12);
    if(ans){
        cout<<"found";
    } 
    else{
        cout<<"not found";
    }

    return 0;
}