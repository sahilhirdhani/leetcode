class Solution {
private:
    vector<vector<vector<int>>> dp;
public:
    bool dfs(vector<vector<char>>& grid, int x, int y, int ob){
        if(x<0 || y<0){
            return false;
        }
        grid[x][y]=='(' ? ob-- : ob++;
        if(ob<0 || ob>x+y+1){
            return false;
        }
        if(dp[x][y][ob]!=-1){
            return dp[x][y][ob];
        }
        if(x==0 && y==0){
            return dp[x][y][ob] = (ob==0);
        }
        return dp[x][y][ob] = (dfs(grid,x-1,y,ob) || dfs(grid,x,y-1,ob));
    }
    bool hasValidPath(vector<vector<char>>& grid) {
        
        int r=grid.size();
        int c=grid[0].size();
        
        dp.assign(r,vector<vector<int>>(c,vector<int>(r+c,-1)));
        
        if(grid[0][0]!='(' || grid[r-1][c-1]!=')'){
            return false;
        }
        
        return dfs(grid,r-1,c-1,0);
    }
};