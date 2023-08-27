#include<iostream>
using namespace std;

long long int squareroot(int n){
    int s= 0;
    int e= n;
   long long int mid= s+ (e-s)/2;

   int ans= -1;
   while(s<e){
    long long int square= mid*mid;
    if(square==n){
        return n;
    }
    else if(square<n){
        ans= mid;
        s=mid+1;
    }
    else{
        e= mid-1;
    }
    mid =s+ (e-s)/2;
   }
   return ans;
}

int main(){
    int n;
    cout<<"insert no. ";
    cin>>n;

    cout<<"square root is "<<squareroot(n);

    return 0;
}

