class Solution {
public:
    int bestClosingTime(string cust) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        
        int n = cust.size();
        vector<int> countBefore(n, 0);
        vector<int> countAfter(n, 0);  
        for (int i = 0; i < n; i++) {
            if (i > 0) {
                countBefore[i] = countBefore[i - 1];
            }
            if (cust[i] == 'N') {
                countBefore[i]++;
            }
            
            int j = n - i - 1;
            if (j < n - 1) {
                countAfter[j] = countAfter[j + 1];
            }
            if (cust[j] == 'Y') {
                countAfter[j]++;
            }
        }
        
        int mi1 = INT_MAX, mi2 = -1;
        
        for (int i = 0; i < n; i++) { 
            int c = countBefore[i] + countAfter[i];
            if (c < mi1) {
                mi1 = c;
                mi2 = i;
            }
        }
        
        if (mi2 < n && cust[mi2] == 'Y') {
            mi2++;
        }
        
        return mi2;
    }
};
