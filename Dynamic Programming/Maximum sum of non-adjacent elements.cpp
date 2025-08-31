
// Simple Recursive Approach

// T.C:- O(2^N)
// S.C:- O(N) Stack sapce 

#include <bits/stdc++.h> 
using namespace std;
int n;

int solve(vector<int>& nums,int sum,int i){

    if(i>=n){
        return sum;
    }
    int skip = solve(nums,sum,i+1);
    int take = solve(nums,nums[i] + sum,i+2);

    return max(skip,take);

}

int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    n = nums.size();
    int sum = 0;
    int i =0;
    return solve(nums,sum,i);
}



// Recursive + Memoize Approach

// T.C:- O(N)
// S.C:- O(N) Vector Space + On(N) Stack sapce 
#include <bits/stdc++.h> 
using namespace std;

int solve(vector<int>& nums,int n,vector<int>& dp){

        if( n < 0)return 0;
        if(n == 0)return nums[0];

        if(dp[n] != -1)return dp[n];

        int take = nums[n] + solve(nums,n-2,dp);
        int skip = 0 + solve(nums,n-1,dp);
        dp[n] =  max(skip,take);
        return dp[n];

}

int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int n = nums.size();
    vector<int> dp(n,-1);
    int sum = 0;
    int i =n-1;
    return solve(nums,n-1,dp);
}

// Bottom Up Approach

// T.C:- O(N)
// S.C:- O(N) Vector Space

#include <bits/stdc++.h> 
using namespace std;


int solveTab(vector<int>& nums){

    int n = nums.size();
    vector<int> dp(n,0);

    dp[0] = nums[0];

    for(int i=1;i<n;i++){

         int inc =  nums[i];
        if(i > 1){

        inc = dp[i-2] + nums[i];
        }
        int exc = dp[i-1] + 0;
        dp[i] = max(inc,exc);

    }
    return dp[n-1];
}

int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    return solveTab(nums);
}

// Two Poniters Approach 
//  T.C:- O(N)
//  S.C:- o(1)

#include <bits/stdc++.h> 
using namespace std;

int solveByVaraibles(vector<int> &nums){
    int n =nums.size();
    int prev1 =  nums[0];
    int prev2 = 0;

    for(int i = 1;i<n;i++){

        int inc = prev2 + nums[i];
        int exc = prev1 + 0;

        int ans = max(inc,exc);
        prev2 = prev1;
        prev1 = ans; 

    }
    return prev1;
}

int maximumNonAdjacentSum(vector<int> &nums){
    
    return solveByVaraibles(nums);
}


