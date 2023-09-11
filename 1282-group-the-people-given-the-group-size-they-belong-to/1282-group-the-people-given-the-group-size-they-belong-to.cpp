class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& gs) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        
        unordered_map<int,vector<int>> m;
        vector<vector<int>> ans;
        
        for(int i = 0; i < gs.size(); i++) {
            m[gs[i]].push_back(i);
        }
        
        for(const auto& x:m) {
            int s = x.second.size();
            int d = s / x.first;
            
            if(d>1) {
                int j=0;
                for(int i = 0; i < d; i++){
                    vector<int> v;
                    for(int k = 0; k < x.first; k++){
                        v.push_back(x.second[j]);
                        j++;
                    }
                    ans.push_back(v);
                }
            } else {
                    ans.push_back(x.second);
            }
        }
        return ans;
    }
};