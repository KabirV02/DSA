#include<vector>
using namespace std;

// T.C:- O(forget^n) 
// S.C:- O(n) recursion stack depth.
class Solution {
public:
    int MOD = 1000000007;
    int solve(int day,int delay,int forget){

      if(day == 1)return 1;
     int result = 0;

      for(int prev = day - forget + 1;prev <= day - delay;prev++){
           if(prev > 0){
            result = (result + solve(prev,delay,forget)) % MOD;
           }
      }
      return result;

    }

    int peopleAwareOfSecret(int n, int delay, int forget) {
        
      int total = 0;
      for(int day = n - forget + 1;day<=n;day++){
        if(day > 0){
         total = (total + solve(day,delay,forget)) % MOD;
        }

      }
        return total;
    }
};

// T.C:- O(n * forget)
// S.C:- O(n) for dp + O(n)
class Solution {
public:
    int MOD = 1000000007;
    int solve(int day,int delay,int forget,vector<int>& dp){

      if(day == 1)return 1;

      if(dp[day] != -1){
        return dp[day];
      }
     int result = 0;

      for(int prev = day - forget + 1;prev <= day - delay;prev++){
           if(prev > 0){
            result = (result + solve(prev,delay,forget,dp)) % MOD;
           }
      }
      dp[day] = result;
      return result;

    }

    int peopleAwareOfSecret(int n, int delay, int forget) {
        
      int total = 0;
      vector<int> dp(n + 1,-1);
      for(int day = n - forget + 1;day<=n;day++){
        if(day > 0){
         total = (total + solve(day,delay,forget,dp)) % MOD;
        }

      }
        return total;
    }
};


// T.C:- O(n * forget)
// S.C:- O(n) for dp
class Solution {
public:
    int MOD = 1000000007;

    int peopleAwareOfSecret(int n, int delay, int forget) {
        
      int result = 0;
      vector<int> dp(n + 1,1);

    for(int day = 2;day<=n;day++){

        long long count = 0;
        for(int prev = day - forget + 1;prev <= day - delay;prev++){
            if(prev > 0){
                count = (count + dp[prev]) % MOD;
            }
        }

        dp[day] = count;

    }

    for(int day = n - forget + 1;day <= n;day++){
        if(day > 0){
            result =(result + dp[day]) % MOD;
        }
    }
        return result;
    }
};