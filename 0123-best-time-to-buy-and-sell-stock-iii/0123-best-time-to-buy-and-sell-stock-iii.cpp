class Solution {
public:
    int fn(vector<int>& prices, int id, int &size, int cap, int fl, vector<vector<vector<int>>> &dp){
        if(cap==0 || id==size-1){
            if(fl==1){
                return dp[id][fl][cap] = prices[id];
            }
            else{
                return dp[id][fl][cap] = 0;
            }
        }
        if(dp[id][fl][cap]!=-1){
            return dp[id][fl][cap];
        }
        int b = 0;
        int nb = 0;
        if(fl==1){
            b = prices[id] + fn(prices,id+1,size,cap-1,0,dp);
            nb = fn(prices,id+1,size,cap,fl,dp);
        }
        else{
            b = -prices[id] + fn(prices,id+1,size,cap,1,dp);
            nb = fn(prices,id+1,size,cap,fl,dp);
        }
        return dp[id][fl][cap] = max(b,nb);
    }
    int maxProfit(vector<int>& prices) {
        ios_base::sync_with_stdio(false); cin.tie(0), cout.tie(0);
        int size=prices.size();
        vector<vector<vector<int>>> dp(size+1,vector<vector<int>>(2,vector<int>(3,-1)));
        return fn(prices,0,size,2,0,dp);
    }
};