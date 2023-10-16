#include<iostream>
using namespace std;

Node* kReverse(Node* head, int k){
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node* curr= head;
    Node* next= NULL;
    Node* prev= NULL;
    int cnt= 0;

    while(curr != NULL && cnt<k){
        next= curr->next;
        curr->next= prev;
        prev= curr;
        curr= next;
    }

    if(next!=NULL){
        head->next= kReverse(next, k)
    }
    
    return prev;
}