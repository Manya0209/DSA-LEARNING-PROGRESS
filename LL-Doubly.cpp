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

void insertAtHead(Node* &tail, Node* &head, int d){
    if(head==NULL){
        Node* temp= new Node(d);
        head= temp;
        tail= temp;
    }
    else{
        Node* temp= new Node(d);
        temp->next= head;
        head->prev= temp;
        head= temp;
    }
}

void insertAtTail(Node* &tail, Node* &head, int d){
    if(tail==NULL){
        Node* temp= new Node(d);
        tail= temp;
        head= temp;
    }
    else{
      Node* temp= new Node(d);
      tail->next= temp;
      temp->prev= tail;
      tail= temp;
    }
}

void insertAtPosition(Node* &tail, Node* &head, int position, int d){
    
    if(position==1){
        insertAtHead(tail, head, d);
        return ;
    }

    Node* temp= head;
    int cnt= 1;

    while(cnt<position-1){
        temp=temp->next;
        cnt++;
    }

    if(temp->next==NULL){
        insertAtTail(tail, head, d);
        return ;
    }

    Node* nodeToInsert= new Node(d);
    nodeToInsert->next= temp->next;
    temp->next->prev= nodeToInsert;
    temp->next= nodeToInsert;
    nodeToInsert->prev= temp;
}

void deleteNode(Node* &head, int position){
    if(position==1){
        Node* temp= head;
        temp->next->prev= NULL;
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
        curr->prev=NULL;
        delete curr;
    }
}

void printList(Node* head){
    Node* temp= head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp= temp->next;
    }
    cout<<endl;
}

int main(){
    Node* node1= new Node(10);
    Node* head= node1;
    Node* tail= node1;

    insertAtHead(tail, head, 14);
    printList(head);

    insertAtTail(tail, head, 12);
    printList(head);

    insertAtPosition(tail, head, 1, 45);
    printList(head);

    deleteNode(head, 1);
    printList(head);
}