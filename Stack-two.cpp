#include<iostream>
using namespace std;

class stack{
    int *arr;
    int size;
    int top1;
    int top2;

    public:
    stack(int s){
        this->size= s;
        arr= new int[s];
        top1= -1; 
        top2= s;
    }

    void push1(int element){
        if(top2-top1> 1){
            arr[top1]= element;
            top1++;
        }
        else{
            cout<<"stack overflow1"<<endl;
        }
    }

    void push2(int element){
        if(top2-top1> 1){
            arr[top2]= element;
            top2--;
        }
        else{
            cout<<"stack overflow"<<endl;
        }
    }

    int pop1(){
        if(top1 >= 0){
            int ans= arr[top1];
            top1--;
            return ans;
        }
        else{
           return -1;
        }
    }

    int pop2(){
        if(top2 < size){
            int ans= arr[top2];
            top2++;
            return ans;
        }
        else{
            return -1;
        }
    }
};


int main(){
    stack st(5);

    st.push1(2);
    st.push1(3);
    st.push2(5);
    st.push2(24);
    st.push2(7);

    cout<<st.pop1()<<endl;
    cout<<st.pop2()<<endl;
}