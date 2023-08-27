class Solution {
public:
    bool canCross(vector<int>& stones) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        unordered_map<int,set<int>> m;
        int size=stones.size();
        for(int x:stones){
            m[x] = set<int>();
        }

        m[0].insert(0);

        for(auto x:stones){
            for( int val : m[x]){
                if( m.find(x+val-1)!=m.end() && val-1>0 ){
                    m[x+val-1].insert(val-1);
                }
                if( m.find(x+val)!=m.end() && val>0 ){
                    m[x+val].insert(val);
                }
                if( m.find(x+val+1)!=m.end() ){
                    m[x+val+1].insert(val+1);
                }
            }
        }
        if(m[stones[size-1]].size()>0){
            return true;
        }
        return false;
    }
};
