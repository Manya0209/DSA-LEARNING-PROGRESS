#include<iostream>
using namespace std;

class stack{
    public:
    int *arr;
    int top;
    int size;

    stack(int size){
        this->size= size;
        arr= new int[size];
        top= -1; 
    }

    void push(int element){
        if(size- top > 1){
            top++;
            arr[top]= element;
        }
        else{
            cout<<"stack overflow"<<endl;
        }
    }

    void pop(){
        if(top>=0){
            top--;
        }
        else{
            cout<<"stack is underflow"<<endl;
        }
    }

    int peek(){
        if(top>=0){
            return arr[top];
        }
        else{
            cout<<"stack is empty"<<endl;
            return -1;
        }
    }
};

int main(){
    stack st(5);

    st.push(2);
    st.push(3);
    st.push(5);
    st.push(24);
    st.push(7);

    cout<<st.peek()<<endl;

    st.pop();
    cout<<st.peek()<<endl;

    st.pop();
    cout<<st.peek()<<endl;
}