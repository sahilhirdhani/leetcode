class Solution {
public:
    bool canFinish(int v, vector<vector<int>>& pre) {
        vector<vector<int>> adj(v);
        vector<int> idegree(v,0);
        queue<int> q;
        int c=0;
        for(auto x:pre){
            adj[x[1]].push_back(x[0]);
        }
        for(auto x:adj){
            for(auto y:x){
                idegree[y]++;
            }
        }
        for(int i=0;i<v;i++){
            if(idegree[i]==0){
                q.push(i);
            }
        }
        while(q.size()){
            int n=q.front();
            q.pop();
            for(auto x:adj[n]){
                idegree[x]--;
                if(idegree[x]==0){
                    q.push(x);
                }
            }
            c++;
        }
        return c==v;
    }
};