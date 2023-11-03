class Solution {
public:
    vector<string> buildArray(vector<int>& t, int n) {
        
        int si=t.size();
        vector<string> ans;
        for(int i=1;i<t[0];i++){
            ans.push_back("Push");
            ans.push_back("Pop");
        }
        ans.push_back("Push");
        for(int i=1;i<si;i++){
            
            for(int j=t[i-1];j<t[i]-1;j++){
                ans.push_back("Push");
                ans.push_back("Pop");
            }
            ans.push_back("Push");
            
        }
        return ans;
    }
};