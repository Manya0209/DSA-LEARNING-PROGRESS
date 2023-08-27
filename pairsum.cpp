#include<iostream>
#include<array>
using namespace std;

pairSum(int arr[], int s){
    int ans= 0;

    for(int i=0; i<arr.size(); i++){
        for(int j=i+1; j<arr.size(); j++){
            if(arr[i]+arr[j] == s){
                int temp;
                temp.pushback(min(arr[i], arr[j]));
                temp.pushback(max(arr[i], arr[j]));
                ans.pushback(temp);
            }
        }
    }
    sort(ans.begin(), ans.end());
    return ans;
}

int main(){
    int arr[]= {1,2,3,4,5,6,7,8};
    pairSum(arr, 12);
    return 0;
}