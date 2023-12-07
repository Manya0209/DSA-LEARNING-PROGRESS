#include<iostream>
#include<stack>
using namespace std;

bool validParenthesis(string e){
    stack<char> s;
    for(int i= 0; i<e.length(); i++){
        char ch= e[i];

        //if opening bracket, stack push
        //if closing bracket, match top and pop

        if(ch=='(' || ch=='{' || ch=='['){
            s.push(ch);
        }
        else{
            if(!s.empty()){
                char top= s.top();
                if((ch=='(' && top==')') ||
                (ch=='{' && top=='}') ||
                (ch=='[' && top==']')){
                    s.pop();
                }
                else{
                    return false;
                }
            }
            else{
                return false;
            }
        }
    }

    if(s.empty()){
        return true;
    }
    else{
        return false;
    }
}