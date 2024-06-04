class Solution {
public:
    int countVowelStrings(int n) {
        vector<vector<int>> dp(n+1,vector<int>(6,0));
        dp[1][5]=5;
        for(int i=0;i<5;i++){
            dp[1][i]=1;
        }
        for(int i=2;i<=n;i++){
            int s=0;
            dp[i][0]=dp[i-1][5];
            s+=dp[i][0];
            for(int j=1;j<5;j++){
                dp[i][j]=dp[i][j-1] - dp[i-1][j-1];
                s+=dp[i][j];
            }
            dp[i][5]=s;
        }
        return dp[n][5];
    }
};