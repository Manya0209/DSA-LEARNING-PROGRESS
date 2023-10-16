#include<iostrem>
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

bool detectLoop(Node* head){
    if(head==NULL)
     return false;

    map <Node*, bool> visited;
    Node* temp= head;

    while(temp!=NULL){
        if(visited[temp]=true){
            cout<<"present on element"<<temp->data<<endl;
            return true;
        }
        visited[true]= true;
        temp=temp->next;
    }
    return false;
}

//Approach 2- Floyd Detection Cycle
Node* floydDetectLoop(Node* head){
    if(head==NULL)
     return NULL;

    Node* slow= head; 
    Node* fast= head;
    while(slow!=NULL && fast!=NULL){
        fast= fast->next;
        if(fast!=NULL){
            fast= fast->next;
        }

        slow= slow->next;
        if(slow== fast){
            cout<<"Cycle present at"<< slow->data<<endl;
            return slow;
        }
    } 
    return NULL;
}

Node* getStartingLoop(Node* head){
    if(head==NULL)
      return NULL;

    Node* intersection= floydDetectLoop(head);
    Node* slow= head;

    while(slow!=intersection){
        slow= slow->next;
        intersection= intersection->next;
    }  

    return slow;
}

void removeLoop(Node* head){
    if(head==NULL)
      return; 
    
    Node* startOfLoop= getStartingLoop(head);
    Node* temp= startOfLoop;

    while(temp->next != startOfLoop){
        temp= temp->next;
    }
    temp->next= NULL;
}