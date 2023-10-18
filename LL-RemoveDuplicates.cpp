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

Node* removeDuplicates(Node* head){
    if(head==NULL)
      return head;

    Node* curr= head;
    while(curr->next!=NULL){
        if(curr->data==curr->next->data){
            Node* next_next= curr->next->next;
            Node* nodeToDelete= curr->next;
            delete(nodeToDelete);
            curr->next= next_next;
        }
        else{
            curr=curr->next;
        }
    }
    return head;  
}