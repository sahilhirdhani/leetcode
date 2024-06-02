class Solution {
public:
    int func(vector<int>& dp, int n){
        if(n<=2){
            return n;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        return dp[n]=func(dp,n-1)+func(dp,n-2);
    }
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return func(dp,n);
    }
};