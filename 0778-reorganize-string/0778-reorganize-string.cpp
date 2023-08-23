class Solution {
public:
    string reorganizeString(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        priority_queue<pair<int, char>> pq;
        unordered_map<char, int> m;
        for (auto x : s) {
            m[x]++;
        }
        for (auto x : m) {
            pq.push({x.second, x.first});
        }
        
        string ans = "";
        while (!pq.empty()) {
            int freq = pq.top().first;
            char ch = pq.top().second;
            pq.pop();
            if (ans.size() == 0 || ans.back() != ch) {
                ans += ch;
                if (--freq > 0) {
                    pq.push({freq, ch});
                }
            } else {
                if (pq.empty()) {
                    return "";
                }
                int next_freq = pq.top().first;
                char next_ch = pq.top().second;
                pq.pop();
                ans += next_ch;
                if (--next_freq > 0) {
                    pq.push({next_freq, next_ch});
                }
                pq.push({freq, ch});
            }
        }
        return ans;
    }
};
