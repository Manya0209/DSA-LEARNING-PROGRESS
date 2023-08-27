#include<iostream>
using namespace std;

bool isPossible(int arr[], int n, int m, ){
    int pagesum=0;
    int studentcount= 1;

    for(int i=0; i<n; i++){
        if(pagesum+ arr[i]<= mid){
            pagesum+= arr[i];
        }
        else{
            studentcount++;
            if(studentcount>m || arr[i]>mid){
                return false;
            }
            pagesum= arr[i];
        }
        return true;
    }
}