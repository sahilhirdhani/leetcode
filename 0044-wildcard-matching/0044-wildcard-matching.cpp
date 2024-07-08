class Solution {
public:
    bool isAllStars(string &S1, int i) {
        for (int j = 0; j <= i; j++) {
            if (S1[j] != '*')
                return false;
        }
        return true;
    }
    bool f(string &s, int i, string &p, int j,vector<vector<int>> &dp){
        if(i<0 && j<0){
            return 1;
        }
        if(j<0 && i>=0){
            return 0;
        }
        if(i<0 && j>=0){
            return isAllStars(p,j);
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(p[j]=='?' || s[i]==p[j]){
            return dp[i][j] = f(s,i-1,p,j-1,dp);
        }
        if(p[j]=='*'){
            return dp[i][j] = f(s,i,p,j-1,dp) || f(s,i-1,p,j,dp);
        }
        return 0;
    }
    bool isMatch(string s, string p) {
        int n=s.size();
        int m=p.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return f(s,n-1,p,m-1,dp);
    }
};