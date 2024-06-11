class Solution {
public:
    int maxRepeating(string sequence, string word) {
        string s = word;
        while (sequence.find(s) != string::npos) s+= word;
        return (s.size()/word.size()) - 1;
    }
};