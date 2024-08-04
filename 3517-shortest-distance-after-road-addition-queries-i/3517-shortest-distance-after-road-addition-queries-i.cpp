class Solution {
public:
    void distance(int s, vector<vector<int>> adj, vector<int>& dist){
        dist[s]=0;
        queue<int> q;
        q.push(s);
        while(q.size()){
            int a=q.front();
            q.pop();
            for(auto x:adj[a]){
                if(dist[a]+1<dist[x]){
                    dist[x] = 1 + dist[a];
                    q.push(x);
                }
            }
        }
    }
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> adj(n);
        for(int i=1;i<n;i++){
            //adj[i].push_back(i-1);
            adj[i-1].push_back(i);
        }
        vector<int> ans;
        for(int i=0;i<queries.size();i++){
            adj[queries[i][0]].push_back(queries[i][1]);
            //adj[queries[i][1]].push_back(queries[i][0]);
            vector<int> dist(n,1e9);
            distance(0,adj,dist);
            ans.push_back(dist[n-1]);
        }
        return ans;
    }
};