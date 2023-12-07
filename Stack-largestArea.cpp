#include<iostream>
#include<stack>
using namespace std;

class Solution{
    public:
    int largestRectangleArea(vector<int> &heights){
        int n = heights.size();

         vector<int> next(n);
         next= nextSmallerElement(heights, n);

         vector<int> prev(n);
         prev= prevSmallerElement(heights, n);

         int area= INT_MIN;
         for(int i=0; i<n; i++){
            int l= heights[i];
            if(next[i]==-1){
                next[i]= n;
            }
            int b= next[i]- prev[i] -1;

            int newArea= l*b;
            area= max(newArea, area);
         }

         return area;
    }
}