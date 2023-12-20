#include<iostream>
#include<stack>
using namespace std;

class Nstack{
    private:
    int *arr;
    int *top;
    int *next;

    int freespot;
    int n, s;

    public:
    Nstack(int N, int S){
        n= N;
        s= S;

        arr= new int[s];
        top= new int[n];
        next= new int[s];

        //top initialise
        for(int i=0; i<n; i++){
            top[i]= -1;
        }

        //next initialise
        for(int i=0; i<s; i++){
            next[i]= i+1;
        }

        next[s-1]= -1;

        //freespot
        freespot= 0;
    }

    bool push(int x, int m){
        if(freespot==-1)
          return false;

        //find index  
        int index= freespot;

        //update freespot
        freespot= next[index];

        //insert in array
        arr[index]= x;

        //update next
        next[index]= top[m-1];
  
        //update top
        top[m-1]= index;

        return true;
    }

    void printArray(){
        for(int i=0; i<s; i++){
            cout<<arr[i]<<" ";
        }
    }
};

int main(){
    Nstack A(3, 6);
    A.push(2,1);
    A.printArray();
}