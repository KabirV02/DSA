/******************Recursive Approach + Memoization************************/
// Time: O(n * m)   where m ≈ floor(n^(1/x))
// Space: O(n * m) + O(m) recursion stack
class Solution {
public:
    int MOD = 1e9+7;
    int t[301][301];

    int solve(int n, int x, int num) {
        if (n < 0) return 0;
        if (n == 0) return 1;

        int currPower = pow(num, x);
        if (currPower > n) return 0;

        if (t[n][num] != -1) {
            return t[n][num];
        }

        int take = solve(n - currPower, x, num + 1);
        int skip = solve(n, x, num + 1);

        return t[n][num] = (take + skip) % MOD;
    }

    int numberOfWays(int n, int x) {
        memset(t, -1, sizeof(t));
        return solve(n, x, 1);
    }
};
