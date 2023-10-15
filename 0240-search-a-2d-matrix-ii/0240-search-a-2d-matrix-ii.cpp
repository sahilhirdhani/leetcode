class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0); 
        int rsize=mat.size();
        int csize=mat[0].size();
        int r=0;
        int c=csize-1;
        while(r<rsize && c<csize && r>=0 && c>=0){
            if(mat[r][c]==target){
                return true;
            }
            else if(mat[r][c]>target){
                c--;
            }
            else{
                r++;
            }
        }
        return false;
    }
};