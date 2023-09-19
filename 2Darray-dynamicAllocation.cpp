#include<iostream>
using namespace std;

int main(){
    // int row;
    // cin>>row;
    // int col;
    // cin>>col;
    // int ** arr= new int*[row];

    // for(int i=0; i<row; i++){
    //     arr[i]= new int[col];
    // } // created array

    int n;
    cout<<"input n";
    cin>>n;

    int ** arr= new int*[n];

    for(int i=0; i<n; i++){
        arr[i]= new int[n];
    } // created array

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
        }
    } //taking input

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    } //taking output

    for(int i=0; i<n; i++){
        delete [] arr[i];
    }//releasing memory

    delete [] arr;

    return 0;
}