class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cin.tie(nullptr);
        ListNode* curr=head;
        ListNode* prev;
        while(curr!=NULL){
          if(curr->val==val){
            if(prev!=NULL)
              prev->next=curr->next;
            else
              head=curr->next;
          }
          else{
            prev=curr;
          }
          curr=curr->next;
        }
        return head;
    }
};