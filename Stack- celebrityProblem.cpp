#include<iostream>
#include<stack>
using namespace std;

bool knows(int **M, int a, int b){
    if(M[a][b]==1)
      return true;
    else
      return false;  
}

int celebrityProblem(int **M, int n){
    stack<int> s;
    //step1: put all elements in stack
    for(int i=0; i<n; i++){
        s.push(i);
    }

    //step2: pop 2 elements and compare
    while(s.size() != 1 ){
        int a= s.top();
        s.pop();

        int b= s.top();
        s.pop();

        if(knows(M, a, b)){
            s.push(b);
        }
        else{
            s.push(a);
        }
    }

    //step3: 1 element left is potential celeb
    //so verify it
    int ans= s.top();

    int zeroCount= 0;
    for(int i=0; i<n; i++){
        if(M[ans][i]==0)
         zeroCount++;
    }
    if(zeroCount != n)
      return -1;

    int oneCount= 0;
    for(int i=0; i<n; i++){
        if(M[i][ans]==1)
         oneCount++;
    }
    if(oneCount != n-1)
      return -1;    

    return ans;      
}

int main(){
    int ** M= new int*[3];
    for(int i=0; i<3; i++)
      M[i]= new int[3];
      
    M[0][0]=0;
    M[0][1]=1;
    M[0][2]=0;
    M[1][0]=0;
    M[1][1]=0;
    M[1][2]=0;
    M[2][0]=0;
    M[2][1]=1;
    M[2][2]=0;

    int result= celebrityProblem(M, 3);
    cout<<result;
}