class Solution {
public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        int n=cost.size();
        vector<long>dp(n+1,INT_MAX);
        dp[0]=0;
        for(int i=0;i<n;i++){
            for(int j=n;j>0;j--){
                dp[j]=min(dp[j],dp[max(j-1-time[i],0)]+cost[i]);
            }
        }
        return dp[n];
    }
};