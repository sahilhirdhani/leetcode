class Solution {
public:
    bool isValid(string s) {
        int si=s.size();
        if(si%2 != 0) return false;
        stack<char> st;
        for(int i=0;i<si;i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='['){
                st.push(s[i]);
            }
            else if(s[i]==')'){
                if(st.size()!=0 && st.top()=='('){
                    st.pop();
                }
                else return false;
            }
            else if(s[i]=='}'){
                if(st.size()!=0 && st.top()=='{'){
                    st.pop();
                }
                else return false;
            }
            else if(s[i]==']'){
                if(st.size()!=0 && st.top()=='['){
                    st.pop();
                }
                else {return false;}
            }        
        }
        if(!st.empty()) return false;
        return true;
    }
};