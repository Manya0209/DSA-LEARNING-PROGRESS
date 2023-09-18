#include<iostream>
using namespace std;

int getSum(int arr[], int n){
    int sum= 0;
    for(int i=0; i<n; i++){
        sum+= arr[i];
    }
    return sum;
}

int main(){
    // char ch= 'a';
    // cout<<sizeof(ch)<<endl;

    // char* c= &ch;
    // cout<<sizeof(c)<<endl;

    int n;
    cin>>n;
    
    int *arr= new int[n]; //dynamic 
    for(int i =0; i<n; i++){
        cin>> arr[i];
    }

    int ans= getSum(arr, n);
    cout<<ans;

    while(true){ // static-->memory allocated-->automatically release
        int i=5;
    }
    
    while (true){ //dynamic-->memory allocated-->manually release-->use delete keyword
        int * ptr= new int;
    }

}
