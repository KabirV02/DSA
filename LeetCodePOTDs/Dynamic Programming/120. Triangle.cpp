#include<vector>
using namespace std;

// Brute Force Recursive Approach
// T.C :- O(2^n)
// S.C :- O(n)

class Solution {
public:
    int n;
    int solve(vector<vector<int>>& triangle,int i,int j){

        if( i == n-1){
            return triangle[i][j];
        }

        int down = solve(triangle,i+1,j);
        int diag = solve(triangle,i+1,j+1);

        return triangle[i][j] + min(down,diag);

    }
    
    int minimumTotal(vector<vector<int>>& triangle) {

        n = triangle.size();
        int i=0,j=0;
        return solve(triangle,i,j);
        
    }
};

// Bottom Up Approach 
// T.C :- O(n^2)
// S.C :- O(n)

class Solution {
public:
 
    int minimumTotal(vector<vector<int>>& triangle) {

        int n = triangle.size();
        vector<int> dp(triangle[n-1]);

        for(int i = n-2;i>=0;i--){
            for(int j = 0;j<=i;j++){
                dp[j] = triangle[i][j] + min(dp[j],dp[j+1]);
            }
        }

        return dp[0];
    }
};
