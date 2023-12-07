#include<iostream>
#include<unordered_map>
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

Node* findMid(Node* &head){
    Node* slow= head;
    Node* fast= head->next->next;

    while(fast!=NULL || fast->next){
        slow= slow->next;
        fast= fast->next->next;
    }
    return slow;
}

Node* merge(Node* left, Node* right){
    if(left==NULL){
        return right;
    }
    if(right==NULL){
        return left;
    }

    Node* ans= new Node(-1);
    Node* temp= ans;

    while(left!=NULL && right!=NULL){
        if(left->data < right->data){
            temp->next= left;
            temp= left;
            left= left->next;
        }
        else{
            temp->next= right;
            temp= right;
            right= right->next;
        }
    }
    return ans;
}

Node* mergeSort(Node * head){
    if(head==NULL || head->next==NULL){
        return head;
    }

    //divide the linked list, after finding mid
    Node* mid= findMid(head);

    Node* left= head;
    Node* right= mid->next;
    mid->next= NULL;

    //recursive calls to left and right part
    left= mergeSort(left);
    right= mergeSort(right);

    //merge both halves
    Node* result= merge(left, right);

    return result;
}