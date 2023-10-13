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

void insertNode(Node* &tail, int element, int d){
    //empty list
    if(tail==NULL){
        Node* newNode= new Node(d);
        tail= newNode;
        newNode->next= newNode;
    }

    else{
        Node* curr= tail;

        while(curr->data != element){
            curr= curr->next;
        }
        Node* temp= new Node(d);
        temp->next= curr->next;
        curr->next= temp;
    }
}

void deleteNode(Node* &tail, int value){
    //empty list
    if(tail==NULL){
        cout<<"List is empty, please check again."<<endl;
        return;
    }

    //non empty
    Node* prev= tail;
    Node* curr= prev->next;

    while(curr->data != value){
        prev= curr;
        curr= curr->next;
    }

    prev->next= curr->next;

    //single node LL
    if(curr==prev){
        tail=NULL;
    }
    //>2 nodes
    if(tail==curr){
        tail= prev;
    }
    curr->next= NULL;
    delete curr;
}

void printNode(Node* tail){
    Node* temp= tail;

    if(tail==NULL){
        cout<<"List is empty";
        return;
    }

    do{
        cout<<tail->data<<" ";
        tail= tail->next;
    }while(tail != temp);
    
    cout<<endl;
}

int main(){
    Node* tail= NULL;

    insertNode(tail, 5, 3);
    printNode(tail);

    insertNode(tail, 3, 5);
    printNode(tail);

    insertNode(tail, 5, 7);
    printNode(tail);

    insertNode(tail, 7, 9);
    printNode(tail);

    insertNode(tail, 5, 6);
    printNode(tail);

    deleteNode(tail, 5);
    printNode(tail);

    deleteNode(tail, 9);
    printNode(tail);
}