#include<iostream>
#include<stack>
using namespace std;

void solve(stack<int> &s, int count, int size){
    if(count==size/2){
        s.pop();
        return ;
    }

    int num= s.top();
    s.pop();

    //recursive call
    solve(s, count+1, size);

    s.push(num);
}

void deleteMiddle(stack<int> s, int n){
    int count= 0;
    solve(s, count, n);
}

int main(){
    stack<int> s;

    s.push(2);
    s.push(3);
    s.push(4);
    s.push(7);
    s.push(6);
    s.push(5);

    deleteMiddle(s, 6);

    return 0; 
}