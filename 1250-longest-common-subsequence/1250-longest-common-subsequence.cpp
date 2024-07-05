class Solution {
public:
    int longestCommonSubsequence(string s1, string s2) {
        ios_base::sync_with_stdio(false);
        cin.tie(0), cout.tie(0);
        int id1=s1.size();
        int id2=s2.size();
        vector<vector<int>> dp(id1+1,vector<int>(id2+1,0));
        for(int i=1;i<=id1;i++){
            for(int j=1;j<=id2;j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
                }
            }
        }
        return dp[id1][id2];
    }
};