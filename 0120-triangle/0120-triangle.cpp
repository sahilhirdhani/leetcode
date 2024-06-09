class Solution {
public:
    int f(vector<vector<int>>& t, int m, int i, vector<vector<int>>& dp){
        if(i>=t[m].size() && m>=t.size()){
            return 0;
        }
        if(m>=t.size()-1){
            return t[m][i];
        }
        if(dp[m][i]!=-1){
            return dp[m][i];
        }
        int _0 = INT_MAX;
        int _1 = INT_MAX;
        _0 = t[m][i] + f(t,m+1,i,dp);
        _1 = t[m][i] + f(t,m+1,i+1,dp);
        return dp[m][i] = min(_0,_1);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        vector<vector<int>> dp;
        for(auto x:triangle){
            vector<int> temp;
            for(auto y:x){
                temp.push_back(-1);
            }
            dp.push_back(temp);
        }

        return f(triangle,0,0,dp);
    }
};