
// Recursive Brute Force
// T.C:- O(2^n)
// S.C:- O(n)

#include<iostream>
#include<vector>
using namespace std;
#define MOD 1000000007
long long int solve(int n){

    if(n == 1)return 0;

    if(n == 2)return 1;

    return ((n-1)%MOD * ((solve(n-1)%MOD) + (solve(n-2)%MOD)));

}
long long int countDerangements(int n) {
    return solve(n);
}

// Recursive + Memoize Approach or  Top Down Approach
// T.C:- O(n)
// S.c :- O(n)For DP Array + O(n) Recursive Call Stack 
long long int solveMemo(int n,vector<long long int>& dp){

    if(n == 1)return 0;

    if(n == 2)return 1;

    if(dp[n] != -1)return dp[n];
    long long int ans = ((n-1)%MOD * ((solveMemo(n-1,dp)%MOD) + (solveMemo(n-2,dp)%MOD)));
    return dp[n] = ans % MOD;

}
long long int countDerangements(int n) {
    vector<long long int> dp(n+1,-1);
        return solveMemo(n,dp);
}


// Tabulation or Bottom Up Approach 
// T.C:- O(n)
// S.c :-O(n) Recursive Call Stack 

long long int solveTab(int n){

    vector<long long int> dp(n+1,0);
    
    dp[1] = 0;
    dp[2] = 1;

    for(int i=3;i<=n;i++){

        long long int first = dp[i-1] % MOD;
        long long int second = dp[i-2] % MOD;
        long long int ans =  ((i-1)%MOD) * ((dp[i-1] + dp[i-2])% MOD);

            dp[i] = ans%MOD;
    }
        return dp[n];
}
long long int countDerangements(int n) {
        return solveTab(n);
}

// Space Optimized Approach 
// T.C :- O(n)
// S.C :- O(1)

long long int solveByVariables(int n){

    int prev1 = 1;
    int prev2 = 0;

    for(int i=3;i<=n;i++){

        long long int first = prev1 % MOD;
        long long int second = prev2 % MOD;
        long long int ans = (((i-1)%MOD) * ((first + second)%MOD)%MOD);
        prev2 = prev1;
        prev1 = ans;

    }
    return prev1;
}
long long int countDerangements(int n) {
        return solveByVariables(n);
}