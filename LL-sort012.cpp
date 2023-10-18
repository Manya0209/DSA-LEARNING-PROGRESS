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

//approach-1

// Node* sortList(Node* head){
//     Node* zeroCount= 0;
//     Node* oneCount= 0;
//     Node* twoCount= 0;

//     Node* temp= head;
//     while(temp!=NULL){
//         if(temp->data==0)
//           zeroCount++;
//         if(temp->data==1)
//           oneCount++;
//         if(temp->data==2)
//           twoCount++;   

//         temp= temp->next;   
//     }

//     temp= head;
//     while(temp!=NULL){
//         if(zeroCount!=0){
//           temp->data=0;
//           zeroCount--;
//         }
//         if(zeroCount!=0){
//           temp->data=1;
//           oneCount--;
//         }
//         if(twoCount!=0){
//           temp->data=2;
//           twoCount--;
//         }

//         temp= temp->next;
//     }
//     return head;
// }

//approach-2
void insertAtTail(Node* &tail, Node* curr){
    tail->next= curr;
    tail= curr;
}

Node* sortList(Node* head){
    Node* zeroHead= new Node(-1);
    Node* zeroTail= zeroHead;
    Node* oneHead= new Node(-1);
    Node* oneTail= oneHead;
    Node* twoHead= new Node(-1);
    Node* twoTail= twoHead;

    //diffrent lists for 0,1,2

    Node* curr= head;
    while(curr!=NULL){
        int value= curr->data;

        if(value==0)
          insertAtTail(zeroTail, curr);
        if(value==1)
          insertAtTail(oneTail, curr);
        if(value==2)
          insertAtTail(twoTail, curr);    
    }
    curr= curr->next;

    //merge list
    if(oneHead->next!=NULL){
        zeroTail->next= oneHead->next;
    }
    else{
        zeroTail->next= twoHead->next;
    }
    oneTail->next= twoHead->next;
    twoTail->next= NULL;

    head= zeroHead->next;

    delete zeroHead;
    delete oneHead;
    delete twoHead;

    return head;
}

int main(){
    
}