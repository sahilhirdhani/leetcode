class Solution {
public:
    bool dfs(pair<int,int> s, vector<int>& color, vector<vector<int>>& adj){
        int src = s.first;
        int clr = s.second;
        color[src]=clr;
        for(auto x:adj[src]){
            if(color[x]==clr){
                return false;
            }
            if(color[x]==-1){
                if(dfs({x,!clr},color,adj)==false){
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& adj) {
        int v=adj.size();
        vector<int> color(v,-1);
        int s=0;
        for(int i=0;i<v;i++){
            if(color[i]==-1){
                if(dfs({i,0},color,adj)==false){
                    return false;
                }
            }
        }
        return 1;
    }
};