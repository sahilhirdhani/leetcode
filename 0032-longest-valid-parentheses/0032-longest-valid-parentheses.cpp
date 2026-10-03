class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        int n=s.size();
        vector<int> vis(n,0);
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                st.push(i);
            }
            else{
                if(!st.empty()){
                    vis[i]=1;
                    vis[st.top()]=1;
                    st.pop();
                }
            }
        }
        int ans=0, temp=0;
        for(int i=0;i<n;i++){
            if(vis[i]==1){
                temp++;
            }
            else{
                ans=max(ans,temp);
                temp=0;
            }
        }
        ans=max(ans,temp);
        return ans;
    }
};