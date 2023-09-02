class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cin.tie(NULL);
        vector<int> v;
        ListNode* curr = head;
        while(curr!=NULL){
            while(!v.empty() && curr->val > v[v.size()-1]){
                v.pop_back();
            }
            v.push_back(curr->val);
            curr=curr->next;
        }
        
        curr=head;
        ListNode* q=NULL;
        for(int i=0;i<v.size();i++){
            curr->val=v[i];
            q=curr;
            curr=curr->next;
        }
        q->next=NULL;
        return head;
    }
};