class Solution {
public:
    int fn(vector<int> &prices, int id, int f, vector<vector<int>> &dp){
        int t=1;
        if(f==-1){
            t=0;
        }
        if(id==prices.size()-1){
            if(f!=-1){
                return dp[id][t] = prices[id]-prices[f];
            }
            return dp[id][t] = 0;
        }
        if(dp[id][t]!=-1){
            return dp[id][t];
        }
        int s = 0;
        int b = 0;
        if(f!=-1){
            s = prices[id]-prices[f] + fn(prices,id+1,-1,dp);
            b = prices[id]-prices[f] + fn(prices,id+1,id,dp);
        }
        else{
            s = fn(prices,id+1,f,dp);
            b = fn(prices,id+1,id,dp);
        }
        return dp[id][t] = max(b,s);
    }
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        vector<vector<int>> dp(size+1,vector<int>(2,-1));
        return fn(prices,0,-1,dp);
    }
};