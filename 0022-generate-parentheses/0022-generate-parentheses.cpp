class Solution {
public:
    void helper(int n, int ob, int cb, string s, vector<string>& ans){
        if(ob==n){
            while(cb!=n){
                s+=')';
                cb++;
            }
            ans.push_back(s);
            return;
        }
        helper(n,ob+1,cb,s+'(',ans);
        if(cb<ob){
            helper(n,ob,cb+1,s+')',ans);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        helper(n,0,0, "", ans);
        return ans;
    }
};