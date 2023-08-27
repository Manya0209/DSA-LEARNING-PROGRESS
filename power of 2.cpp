#include<iostream>
#include<math.h>
using namespace std;

class solution{
    public:
    bool isPowerof2(int n){

        for(int i=0; i<=30; i++){
            int ans= pow(2, i);
        
        if(ans == n){
            return true;
        }
        }
        return false;
    } 
};

int main(){
    int x;
    cin>>x;

    bool isPowerof2(x);

}