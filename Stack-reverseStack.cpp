#include<iostream>
#include<stack>
using namespace std;

void insertAtBottom(stack<int> &s, int element){
    //base case
    if(s.empty()){
        s.push(element);
    }

    int num= s.top();
    s.pop();

    //recursive call
    insertAtBottom(s, element);

    s.push(num);
}

void reverseStack(stack<int> &s){
    //base case
    if(s.empty()){
        return ;
    }

    int num= s.top();
    s.pop();

    //recursive call
    reverseStack(s);

    insertAtBottom(s, num);

    return ;
}

int main(){
    stack<int> s, s1;

    s.push(2);
    s.push(3);
    s.push(4);
    s.push(7);
    s.push(6);
    s.push(5);

    s1= s;

    while (!s1.empty()) {
        cout << s1.top() << " ";
        s1.pop();
    }

    reverseStack(s);
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }

    return 0; 
}