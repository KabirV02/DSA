
// Recursive Approach 
// Time Limit Exceeds

class Solution {

public:

    int solve(vector<int>& cost,int n){

        if(n == 0)return cost[0];
        if(n == 1) return cost[1];

        return cost[n] + min(solve(cost,n-1),solve(cost,n-2));

    }

    int minCostClimbingStairs(vector<int>& cost) {

        int n = cost.size();

        return min(solve(cost,n-1),solve(cost,n-2));

        
    }
};

// Recursive + Memoization Approach
// T.C :- O(n)
// S.C :-O(n) for DP + O(n) recursion stack
class Solution {
public:
    int dp[1001];
    int memoize(vector<int>& cost,int n){

        if(n == 0)return cost[0];
        if(n == 1)return cost[1];

        if(dp[n] != -1)return dp[n];

        return dp[n] = cost[n] + min(memoize(cost,n-1),memoize(cost,n-2));

    } 

    int minCostClimbingStairs(vector<int>& cost) {

        int n = cost.size();
        memset(dp,-1,sizeof(dp));
        return min(memoize(cost,n-1),memoize(cost,n-2));

        
    }
};

// Bottom Up Approach or Tabulation method
// T.C :- O(n)
// S.C :- O(n)
class Solution {
public:
    int dp[1001];
    int bottomUp(vector<int>& cost,int n){

        dp[0] = cost[0];
        dp[1] =  cost[1];

        for(int i=2;i<n;i++){
            dp[i] = cost[i] + min(dp[i-1] , dp[i-2]);
         }
         return min(dp[n-1],dp[n-2]);

    }

    int minCostClimbingStairs(vector<int>& cost) {

        int n = cost.size();
        memset(dp,-1,sizeof(dp));
        return bottomUp(cost,n);

    }
};


// Space Optimized Approach 
// T.C :- O(n)
// S.C :- O(1)
class Solution {
public:
  

    int minCostClimbingStairs(vector<int>& cost) {

      int n = cost.size();

      int prev2 = cost[0];
      int prev1 = cost[1];

      for(int i=2;i<n;i++){

        int curr = cost[i] + min(prev2 , prev1);
        prev2 = prev1;
        prev1 = curr;

      }
        return min(prev1,prev2);
    }
};