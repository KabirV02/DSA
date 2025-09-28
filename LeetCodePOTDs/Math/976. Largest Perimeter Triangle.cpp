#include<algorithm>
#include<vector>

using namespace std;

class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        
        int n = nums.size();
        int maxSum = 0;
        sort(nums.begin(),nums.end());
        for(int i = 0;i < n - 2;i++){
            if(nums[i] + nums[i+1] > nums[i+2]){
                maxSum = max(maxSum,nums[i] + nums[i+1] + nums[i+2]);
            }
        }

        return maxSum;

    }
};