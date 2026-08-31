/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        //ListNode* temp=new ListNode();
        //temp->next=head;
        vector<int> v;
        ListNode* prev = head;
        if (head->next == NULL || head->next->next == NULL) {
            v.push_back(-1);
            v.push_back(-1);
        }
        else {
            stack<int> st;
            ListNode* curr = head->next;
            ListNode* nxt = curr->next;
            int c = 1;
            while (nxt != NULL) {
                c++;
                if ((curr->val > nxt->val && curr->val > prev->val) || (curr->val < prev->val && curr->val < nxt->val)) 
                {
                    st.push(c);
                }
                prev = curr;
                curr = nxt;
                nxt = nxt->next;
            }
            if (st.size()<=1) {
                v.push_back(-1);
                v.push_back(-1);
            }
            else {
                int temp1 = st.top();
                int mi=1000000;
                int temp;
                while (st.size()>1) {
                    temp=st.top();
                    st.pop();
                    mi = min(mi,temp-st.top());
                }
                int ma = (st.empty())? mi:temp1-st.top();
                v.push_back(mi);
                v.push_back(ma);
            }
        }
        return v;

    }
};