#include <bits/stdc++.h> 
using namespace std;
int n;
int solve(vector<int>&num,int x,vector<int>& dp){

    dp[0] = 0;
    for(int i=1;i<=x;i++){
        for(int j=0;j<n;j++){
            if(i - num[j] >= 0 && dp[i - num[j]] != INT_MAX){
                dp[i] = min(dp[i],dp[i - num[j]] + 1);
            }
        }
    }
    return dp[x];

}

int minimumElements(vector<int> &num, int x)
{
    // Write your code here.
    if(x == 0)return 0;
    n = num.size();
    vector<int> dp(x+1,INT_MAX);
    int ans = solve(num,x,dp);
    if(ans == INT_MAX)return -1;
    return ans;
}