class Solution {
public:
    int f(vector<vector<int>>& g, int m, int n, vector<vector<int>>& dp){
        if(m==0 && n==0){
            return g[m][n];
        }
        int _1=INT_MAX;
        int _2=INT_MAX;
        if(m<0){
            m=0;
            if(dp[m][n]!=-1){
                return dp[m][n];
            }
            _1 = g[0][n] + f(g,0,n-1,dp);
        }
        else if(n<0){
            n=0;
            if(dp[m][n]!=-1){
                return dp[m][n];
            }
            _2 = g[m][0] + f(g,m-1,0,dp);
        }
        else{
            if(dp[m][n]!=-1){
                return dp[m][n];
            }
            _1 = g[m][n] + f(g,m,n-1,dp);
            _2 = g[m][n] + f(g,m-1,n,dp);
        }
        return dp[m][n]=min(_2,_1);
    }
    int minPathSum(vector<vector<int>>& grid) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return f(grid,m-1,n-1,dp);
    }
};