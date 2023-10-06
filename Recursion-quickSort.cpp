#include<iostream>
using namespace std;

int partition(int arr[], int s, int e){
    int pivot= arr[s];

    int cnt= 0;
    for(int i=s+1; i<=e; i++){
        if(arr[i]<pivot){
            cnt++;
        }
    }

    int pivotIndex= s+ cnt;
    swap(arr[pivotIndex], pivot);

    int i=s;
    int j=e;
    while(i<pivotIndex && j>pivotIndex){

        while(i<=pivot){
            i++;
        }

        while(j> pivot){
            j--;
        }

        if(i>pivot && j<pivot){
            swap(arr[i], arr[j]);
        }

    }
    return pivotIndex;
}

void quickSort(int arr[], int s, int e){
    //base case
    if(s>=e){
        return ;
    }

    //partition
    int p= partition(arr, s, e);

    quickSort(arr,s, p-1);
    quickSort(arr, p+1, e);
}

int main(){
    int arr[]= {2,6,2,3,98,22,45};
    int n= 7;

    quickSort(arr, 0, n-1);
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}