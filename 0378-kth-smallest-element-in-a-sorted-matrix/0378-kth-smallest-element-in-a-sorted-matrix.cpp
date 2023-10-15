class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        priority_queue<int> pq;
        for(auto x:mat){
            for(auto y:x){
                pq.push(y);
                if(pq.size()>k){
                    pq.pop();
                }
            }
        }
        return pq.top();
    }
};