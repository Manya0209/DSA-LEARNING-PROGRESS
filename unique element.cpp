#include<iostream>
using namespace std;

int uniqueElement(int arr[], int size){
    int ans= 0;

    for(int i=0; i<size; i++){
        ans= ans^arr[i];
    }
    return ans;
};

int main(){
    int arr[]= {1,2,2,4,5,5,4};
    uniqueElement(arr, 7);
    return 0;
}