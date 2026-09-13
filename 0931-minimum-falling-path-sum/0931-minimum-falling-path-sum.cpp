class Solution {
public:
    vector<vector<int>> dp;
    int n;
    int function(vector<vector<int>>& matrix, int row, int col){
        
        if(dp[row][col]!=INT_MAX){
            return dp[row][col];
        }

        if(row==n-1){
            return dp[row][col] = matrix[row][col];
        }

        int left = INT_MAX;
        if(col-1>=0){
            left = matrix[row][col] + function(matrix,row+1,col-1);
        }
        
        int below = matrix[row][col] + function(matrix,row+1,col);
        
        int right=INT_MAX;
        if(col+1<matrix[0].size()){
            right = matrix[row][col] + function(matrix,row+1,col+1);
        }
        
        return dp[row][col] = min(left,min(right,below));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        n=matrix[0].size();
        dp.assign(n,vector<int>(n,INT_MAX));
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            ans=min(ans,function(matrix,0,i));
        }
        return ans;
    }
};