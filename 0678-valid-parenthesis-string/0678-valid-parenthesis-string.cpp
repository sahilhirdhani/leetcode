class Solution {
private:
    vector<vector<int>> dp;
public:
    bool helper(string s, int id, int cb){
        if(id==0){
            if(cb==1){
                return dp[id][cb] = (s[id]=='(' || s[id]=='*');
            }
            else if(cb==0 && s[id]=='*'){
                return dp[id][cb] = true;
            }
            return dp[id][cb] = false;
        }
        if(dp[id][cb]!=-1){
            return dp[id][cb];
        }
        cout<<id<<endl;
        if(s[id]==')'){
            if(cb>id){
                return dp[id][cb] = false;
            }
            return dp[id][cb] = helper(s,id-1,cb+1);
        }
        else if(s[id]=='*'){
            return dp[id][cb] = (helper(s,id-1,cb+1) ||
            helper(s,id-1,cb) ||
            (cb==0 ? false : helper(s,id-1,cb-1))) ;
        }
        else{
            if(cb==0){
                return dp[id][cb] = false;
            }
            else{
                return dp[id][cb] = helper(s,id-1,cb-1);
            }
        }
    }
    bool checkValidString(string s) {
        int n=s.size();
        dp.assign(n+1,vector<int>(n+1,-1));
        return helper(s, n-1, 0);
    }
};