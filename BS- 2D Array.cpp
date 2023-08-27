#include<iostream>
#include<array>
using namespace std;

int binarysearch(int arr[][4], int row, int col, int key){

    int start= 0;
    int end= row*col -1;

   // int mid= (start+end)/2;
    int  mid= start+ (end - start)/2; // if start= 2^31-1, end= 2^31-1

    while(start<=end){
        int element= arr[mid/col][mid%col];

        if(element ==key){
            return element;
        }
        if(key> element){
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
    int arr[3][4]= {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};

    int index= binarysearch(arr, 3, 4, 3);
    cout<<"index of 14 is "<<index<<endl;

    return 0;
}
