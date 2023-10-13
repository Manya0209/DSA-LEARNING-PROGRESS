#include<iostream>
#include <vector>
using namespace std;

void solve(int index, vector<int> num,  vector<vector<int>>& ans){
    if(index >= num.size())
    ans.push_back(num);

    for(int j=index; j<=num.size(); j++){
        swap(num[index], num[j]);
        solve(index+1, num, ans);
        //backtrack
        swap(num[index], num[j]);
    }
}

 vector<vector<int>> permute(vector<int> num){
     vector<vector<int>> ans;
    int index= 0;
    solve(index, num, ans);
    return ans;
}

int main(){
    vector<int> num= {1,2,3};
    vector<vector<int>> ans= permute(num);

    // for(int& a: ans){
    //     cout<<""<<a;
    // }

    return 0;
}