#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* prev;
    Node* next;

    Node(int data){
        this -> data= data;
        this -> next= NULL;
        this -> prev= NULL;
    }
    ~Node(){
        int value= this->data;
        if(this->next!=NULL){
            delete next;
            this->next=NULL;
        }
        cout<<"memory is free for data "<<value<<endl;
    }
};

Node* solve(Node* first, Node* second){
    //only 1 element in 1st list
    if(first->next==NULL){
        first->next= second;
        return first;
    }

    Node* curr1= first;
    Node* next1= first->next;
    Node* curr2= second;
    Node* next2= second->next;

    while(next1 != NULL && curr2 != NULL){
        if((curr2->data >= curr1->data) && (curr2->data <= curr1->next->data)){
           curr1->next= curr2;
           next2= curr2->next;
           curr2->next= next1;

           //update pointers
           curr1= curr2;
           curr2= next2;
        }
        else{
           curr1= next1;
           next1= next1->next;

           if(next1 == NULL){
            curr1->next= curr2;
            return first;
           }
        }
    }
    return first;
}

Node* mergeList(Node* first, Node* second){
    if(first==NULL)
      return second;
    if(second==NULL)
      return first;  

    if(first->data <= second->data) {
        return solve(first, second);
    }
    else{
        return solve(second, first); 
    } 
}

int main(){}