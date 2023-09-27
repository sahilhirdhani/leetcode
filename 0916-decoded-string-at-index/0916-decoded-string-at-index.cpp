class Solution {
public:
    string decodeAtIndex(string s, int k) {
        long long size = 0;
        int i = 0;
        while (size < k) {
            char c = s[i];
            if (isdigit(c)) {
                size *= (c - '0');
            } else {
                size++;
            }
            i++;
        }
        i--;
        while (i >= 0) {
            char c = s[i];
            if (isdigit(c)) {
                size /= (c - '0');
                k %= size;
            } else {
                if (k == 0 || k == size) {
                    string result(1, c);
                    return result;
                }
                size--;
            }
            i--;
        }
        return "";
    }
};