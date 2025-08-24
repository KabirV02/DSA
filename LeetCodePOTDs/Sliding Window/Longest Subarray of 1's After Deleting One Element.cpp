
// Brute Force 
// T.C :- o(n^2)

class Solution {
public:
    int n;
    int findMax(vector<int>&nums,int skip){

        int currLen = 0;
        int maxLen = 0;
        for(int i=0;i<n;i++){
            if( i == skip)continue;

            if(nums[i] == 1){
                currLen++;
                maxLen = max(maxLen,currLen);
            }
            else{
                currLen = 0;
            }
        }
        return maxLen;
    }

    int longestSubarray(vector<int>& nums) {

        n = nums.size();
        int ans = 0;
        int countZeros = 0;
        for(int i=0;i<n;i++){
           if(nums[i] == 0){
            countZeros++;
              ans = max(ans,findMax(nums,i));
           }
        }
        if(countZeros == 0){
            return n-1;
        }
        return ans;
    }
};


// Optimized Sliding Window Approach 
// T.C. :- O(n+n)

class Solution {
public:
    int longestSubarray(vector<int>& nums) {

        int n = nums.size();
        int zeros = 0;
        int ans = 0;
        int start =0;
        for(int end = 0;end<n;end++){

            if(nums[end] == 0)zeros++;
            while(zeros > 1){
               if(nums[start] == 0){
                    zeros--;
               }
               start++;
            }
                ans = max(ans,end - start);

        }
        return ans;
    }
};

// Most Optimized Sliding Window Approach 
// Here we remove the while loop and with help of lastZeroIndex pointer we inc the start value
// T.C. :- O(n)

class Solution {
public:
    int longestSubarray(vector<int>& nums) {

        int n = nums.size();
        int zeros = 0;
        int ans = 0;
        int start =0;
        int lastZeroIndex = -1;
        for(int end = 0;end<n;end++){

            if(nums[end] == 0){
                 start = lastZeroIndex + 1;
                 lastZeroIndex = end;
            }
                ans = max(ans,end - start);

        }
        return ans;
    }
};