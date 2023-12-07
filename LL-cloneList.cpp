#include<iostream>
#include<unordered_map>
using namespace std;

class Node{
    public:
    int data;
    Node* prev;
    Node* next;
    Node* random;

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


// //approach1
// Node* cloneList(Node * head){
//     //step1: copying a list
//     Node* cloneHead= NULL;
//     Node* cloneTail= NULL;

//     Node* temp= head;
//     while(temp!=NULL){
//         insertAtTail(cloneTail, cloneHead, temp->data);
//         temp= temp->next;
//     }

//     //step2: map create
//     unordered_map<Node*, Node*> oldToNewNode;

//     Node* originalNode= head;
//     Node* cloneNode= cloneHead;
//     while(originalNode!= NULL && cloneNode!=NULL){
//         oldToNewNode[originalNode]= cloneNode;
//         originalNode= originalNode->next;
//         cloneNode= cloneNode->next;
//     }

//     originalNode= head;
//     cloneNode= cloneHead;
//     while(originalNode!= NULL){
//         cloneNode->random= oldToNewNode[originalNode->random];
//         originalNode= originalNode->next;
//         cloneNode= cloneNode->next;
//     }

//     return cloneHead;
// }



//approach2
Node*cloneList2(Node * head){
     //step1: copying a list
    Node* cloneHead= NULL;
    Node* cloneTail= NULL;

    Node* temp= head;
    while(temp!=NULL){
        insertAtTail(cloneTail, cloneHead, temp->data);
        temp= temp->next;
    }

    //step2: add cloneNodes in b/w
    Node* originalNode= head;
    Node* cloneNode= cloneHead;
    while(originalNode!= NULL && cloneNode!=NULL){
        Node* next= originalNode->next;
        originalNode->next= cloneNode;
        originalNode= next;

        next= cloneNode->next;
        cloneNode->next= originalNode;
        cloneNode= next;
    }

    //step3: copy random pointers
    Node* temp= head;
    while(temp!=NULL){
        if(temp->next!=NULL){
            if(temp->random!=NULL){
                temp->next->random= temp->random->next;
            }
        }
        else{
            temp->next= temp->random;
        }
    }
    //step4: revert changes done in step2
    Node* originalNode= head;
    Node* cloneNode= cloneHead;
    while(originalNode!= NULL && cloneNode!=NULL){
        originalNode->next= cloneNode->next;
        originalNode= originalNode->next;

        if(originalNode!=NULL){
            cloneNode->next= originalNode->next;
        }    
        cloneNode= cloneNode->next;
    }

    //step5: return ans
    return cloneHead;
}