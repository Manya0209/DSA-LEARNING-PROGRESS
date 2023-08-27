#include<iostream>
using namespace std;

bool search(int arr[], int size, int key){
    for(int i=0; i<size; i++){
        if(i==key){
            return 1;
        }
       
    }
     return 0;
}

int main(){
    int key;
    int arr[5]= {1,2,3,4,5};
    cout<<"enter the element to search for "<<endl;
    cin>>key;

    bool found= search(arr, 5, key);
    if(found){
        cout<<"key is present";
    }
    else{
        cout<<"key is absent";
    }
    return 0;
}