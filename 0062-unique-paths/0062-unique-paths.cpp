class Solution {
public:
    int boobies(int r, int d, int m, int n, vector<vector<int>>& memo) {
        if (r == m && d == n) {
            return 1;
        }
        if (r > m || d > n) {
            return 0;
        }
        if (memo[r][d] != -1) {
            return memo[r][d];
        }
        int ans = boobies(r + 1, d, m, n, memo) + boobies(r, d + 1, m, n, memo);
        memo[r][d] = ans;
        return ans;
    }
    
    int uniquePaths(int m, int n) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        vector<vector<int>> memo(m, vector<int>(n, -1));
        return boobies(0, 0, m - 1, n - 1, memo);
    }
};