class Solution {
public:
    int f(int id, int sum, vector<int>& coins, vector<vector<int>>& dp){
        if(id==0){
            if(sum==0 || sum==coins[id] || sum%coins[id]==0){
                return 1;
            }
            return 0;
        }
        if(dp[id][sum]!=-1){
            return dp[id][sum];
        }
        int p = 0;
        if(sum>=coins[id]){
            p = f(id,sum-coins[id],coins,dp);
        }
        int np = f(id-1,sum,coins,dp);
        return dp[id][sum]=p+np;
    }
    int change(int amount, vector<int>& coins) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);cout.tie(0); 
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        return f(n-1,amount,coins,dp);
    }
};