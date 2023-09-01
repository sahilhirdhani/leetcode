class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cin.tie(NULL);
        stack<int> st;
        ListNode* low=head;
        ListNode* high=head;
        while(high!=NULL && high->next!=NULL){
            st.push(low->val);
            low=low->next;
            high=high->next->next;
        }
        if(high==NULL){
            while(!st.empty() && low!=NULL){
                if(st.top()==low->val){
                    st.pop();
                }
                else{
                    return false;
                }
                low=low->next;
            }
            if(!st.empty() || low!=NULL)
                return false;
        }
        else{
            while(!st.empty() && low->next!=NULL){
                if(st.top()==low->next->val){
                    st.pop();
                }
                else{
                    return false;
                }
                low=low->next;
            }
            if(!st.empty() || low->next!=NULL)
                return false;
        }
        return true;
    }
};