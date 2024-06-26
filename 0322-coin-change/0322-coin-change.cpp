class Solution {
public:
    int f(vector<int>& coins, int sum, int id, vector<vector<int>>& dp){
        if(id==0){
            if(sum%coins[0]==0){
                return sum/coins[id];
            }
            return INT_MAX;
        }
        if(dp[id][sum]!=-1){
            return dp[id][sum];
        }
        int _1=INT_MAX;
        if(sum-coins[id]>=0){
            int a = f(coins,sum-coins[id],id,dp);
            if(a!=INT_MAX)
                _1 = 1 + a;
        }
        int _2 = f(coins,sum,id-1,dp);
        return dp[id][sum] = min(_1,_2);
    }
    int coinChange(vector<int>& coins, int amount) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        if(amount==0){
            return 0;
        }
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        int a = f(coins,amount,n-1,dp);
        return a == INT_MAX ? -1 : a;
    }
};