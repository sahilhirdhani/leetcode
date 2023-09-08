class Solution {
public:
    vector<vector<int>> generate(int n) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        vector<vector<int>> ans;
        
        ans.push_back({1});
        if(n == 1) {
            return ans;
        }
        
        ans.push_back({1,1});
        if( n == 2 ) {
            return ans;
        }

        for(int i = 2; i < n; i++) {
            
            int si=ans.size();
            ans.push_back({1});
            for(int j = 0; j < si-1; j++) {
                ans[si].push_back(ans[si-1][j]+ans[si-1][j+1]);
            }
            ans[si].push_back(1);
        }

        return ans;
    }
};