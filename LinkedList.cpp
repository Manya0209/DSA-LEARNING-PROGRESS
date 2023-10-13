#include<iostream>
using namespace std;

class Node{
    public: 
    int data;
    Node* next;

    Node(int data){
        this -> data= data;
        this -> next= NULL;
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

void insertAtHead(Node* &head, int d){
    Node* temp= new Node(d);
    temp -> next= head;
    head= temp;
}


void insertAtTail(Node* &tail, int d){
    Node* temp= new Node(d);
    tail -> next= temp;
    tail= temp;
}

void insertAtPosition(Node* &head,Node* &tail, int d, int position){
    Node* temp= head;
    int cnt= 1;

    if(position==1){
        insertAtHead(head, d);
    }

    if(temp->next==NULL){
        insertAtTail(tail, d);
    }

    while(cnt<position-1){
        temp=temp->next;
        cnt++;
    }

    Node* nodeToInsert= new Node(d);
    temp->next= nodeToInsert->next;
    temp->next= nodeToInsert;
}



void printNode(Node* &head){
    Node* temp= head;

    while(temp!=NULL){
    cout<<temp ->data<<" ";
    temp= temp->next;
    }
    cout<<endl;
}
void deleteNode(Node* &head, int position){
    if(position==1){
        Node* temp= head;
        head= head->next;
        temp->next= NULL;
        //memory free 
        delete temp;
    }
    else{
        Node* prev= NULL;
        Node* curr= head;

        int cnt= 1;
        while(cnt<position){
            prev= curr;
            curr= curr->next;
            cnt++;
        }

        prev->next= curr->next;
        curr->next= NULL;
        delete curr;
    }
}
int main(){
    Node* node1= new Node(10);
    cout<<node1 -> data<<endl;
    cout<<node1 -> next<<endl;
    Node* head= node1;
    Node* tail= node1; 

    insertAtHead(head, 12);
    printNode(head);

    insertAtTail(tail, 13);
    printNode(head);

    insertAtPosition(head,tail, 20, 3);
    printNode(head);

    deleteNode(head, 3);
    printNode(head);
}