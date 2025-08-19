
//https://leetcode.com/problems/number-of-zero-filled-subarrays/?envType=daily-question&envId=2025-08-19

class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {

        int n = nums.size();
         long long result = 0;
         int i=0;
        while(i<n){

         long long countZeros = 0;
           if(nums[i] == 0){
            while(i < n && nums[i] == 0){
                countZeros++;
                i++;
            }
           }else{
            i++;
           }

           result += (countZeros * (countZeros + 1))/2;
            
        }
        return result;
    }
};

// Optimized Approach

class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {

        int n = nums.size();
         long long count = 0;
         long long result = 0;
        for(int i=0;i<n;i++){

            if(nums[i] == 0){
                count+=1;
            }else{
                count = 0;
            }
            result+=count;
            
        }
        return result;
    }
};