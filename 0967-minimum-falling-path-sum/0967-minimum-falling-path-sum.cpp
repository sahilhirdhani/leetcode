class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& g) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int m = g.size();
        int a = INT_MAX;
        vector<vector<int>> dp(m,vector<int>(m,-1));

        if(m==1){
            return g[0][0];
        }

        for(int i=0;i<m;i++){
            dp[0][i] = g[0][i];
        }

        for(int i=1;i<m;i++){
            for(int j=0;j<m;j++){
                int _1 = INT_MAX;
                int _2 = INT_MAX;
                int _3 = INT_MAX;
                if(j>0) _1 = g[i][j] + dp[i-1][j-1];
                _2 = g[i][j] + dp[i-1][j];
                if(j<g[0].size()-1) _3 = g[i][j] + dp[i-1][j+1];
                    
                dp[i][j] = min(_1,min(_2,_3));
            }
        }

        for(int i=0;i<m;i++){
            a=min(a,dp[m-1][i]);
        }
        return a;
    }
};