class Solution {
public:
    int fn(vector<int>& prices, int id, int &size, int cap, int fl, vector<vector<vector<int>>> &dp){
        if(cap==0 || id==size){
            return dp[id][fl][cap] = 0;
        }
        if(dp[id][fl][cap]!=-1){
            return dp[id][fl][cap];
        }
        int b = 0;
        int nb = 0;
        if(fl==0){
            b = -prices[id] + fn(prices,id+1,size,cap,1,dp);
            nb = fn(prices,id+1,size,cap,0,dp);
        }
        else{
            b = prices[id] + fn(prices,id+1,size,cap-1,0,dp);
            nb = fn(prices,id+1,size,cap,1,dp);
        }
        return dp[id][fl][cap] = max(b,nb);
    }
    int maxProfit(int k, vector<int>& prices) {
        int size=prices.size();
        vector<vector<vector<int>>> dp(size+1,vector<vector<int>>(2,vector<int>(k+1,-1)));
        return fn(prices,0,size,k,0,dp);
    }
};