#include<iostream>
using namespace std;

int main(){
    int arr[5]= {1,2,3,4,5};
    char ch[6]= "abcde";

    int *a= &arr[0];
    cout<< arr <<endl;
    cout<< &arr <<endl;
    cout<< a <<endl;
    cout<<endl;

    char *c= &ch[0];
    cout<< ch <<endl;
    cout<< &ch <<endl;
    cout<< c <<endl;

    return 0;
}