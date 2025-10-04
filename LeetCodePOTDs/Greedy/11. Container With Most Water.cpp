#include<vector>
using namespace std;

// T.C :- O(n)
// S.C :- O(1)

class Solution {
public:
    int maxArea(vector<int>& height) {

        int n = height.size();

        int left = 0;
        int right = n-1;

        int maxArea = INT_MIN;
        int area = 1;
        while(left < right){

            int mini = min(height[left],height[right]);
            area  = mini * (right - left);
            if(height[left] < height[right]){
                left++;
            }else{
                right--;
            }

            if(area > maxArea){
                maxArea = area;
            }

        }

        return maxArea;
        
    }
};