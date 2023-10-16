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

bool isCircular(Node* head){
    if(head==NULL){
        return true;
    }

    Node* temp= head->next;
    while(temp!=head || temp!=NULL){
        temp=temp->next;
    }
    if(temp==head){
        return true;
    }
    
    return false;
}

int main(){
    Node* head= NULL;
    if(isCircular(head)){
        cout<<"Linked list is circular"<<endl;
    }
    else{
        cout<<"Linked list is not circular"<<endl;
    }
}