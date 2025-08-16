// https://leetcode.com/problems/permutations/

class Solution {
public:
    int n;

    void solve(vector<int>& nums,vector<vector<int>>& result,int i){

        if(i >= n){ 
            result.push_back(nums);
            return;
        }

        for(int j=i;j<n;j++){
            swap(nums[i],nums[j]);
            solve(nums,result,i+1);
            swap(nums[i],nums[j]);
        }

    }

    vector<vector<int>> permute(vector<int>& nums) {
        n = nums.size();
        vector<vector<int>> result;
        vector<int> output;
        int i = 0;
            solve(nums,result,i);
        return result;
    }
};