class Solution {
public:
    string sortVowels(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        priority_queue<char> pq;
        priority_queue<int> pq1;
        for(int i=0;i<s.size();i++){
            auto x=s[i];
            if(x=='A' || x=='E' || x=='I' || x=='O' || x=='U' || x=='a' || x=='e' || x=='i' || x=='o' || x=='u'){
                pq.push(x);
                pq1.push(i);
            }
        }
        while(pq.size()){
            s[pq1.top()]=pq.top();
            pq.pop();
            pq1.pop();
        }
        return s;
    }
};