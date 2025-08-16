// https://leetcode.com/problems/subsets/

class Solution {
public:
   int n;
    void solve(vector<int>& nums, vector<vector<int>>& result,vector<int> output,int i){

        if(i >= n){
            result.push_back(output);
            return;
        }

        solve(nums,result,output,i+1);
        output.push_back(nums[i]);
        solve(nums,result,output,i+1);
        


    }

    vector<vector<int>> subsets(vector<int>& nums) {

         n = nums.size();
        vector<vector<int>> result;
        vector<int> output;
        int i =0;
        solve(nums,result,output,i);
        return result;
        
    }
};