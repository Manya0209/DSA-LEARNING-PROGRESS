#include<iostream>
#include<climits>
using namespace std;

class solution{
    public:
    int reverse(int x){
         int ans=0;
        while(x!=0){
            int digit= x%10;
           

            if((ans>INT_MAX/10) || (ans<INT_MIN/10)){
                return 0;
            }

            ans= (ans*10)+ digit;
        }
        return ans;
    }
};

int main(){
    int n;
    cin>>n;
    int reverse(n);
    return 0;
}