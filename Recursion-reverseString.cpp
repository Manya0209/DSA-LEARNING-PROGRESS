#include<iostream>
using namespace std;

void reverseString(string& s, int i, int j){
    //base case
    if(i>j)
    return ;

    swap(s[i], s[j]);
    i++;
    j--;

    reverseString(s, i, j);
}

int main(){
    string str= "babbar";
    
    reverseString(str, 0, str.length()-1);

    cout<<str;
}