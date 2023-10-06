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
    ListNode* mergeNodes(ListNode* head) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cin.tie(nullptr);
        cout.tie(NULL);
        
        ListNode* curr=head->next;
        ListNode* prev=head;
        int bn=0;
        while(curr!=NULL){
            if(curr->next->val==0){
                bn+=curr->val;
                prev->next=curr;
                prev=curr;
                curr->val=bn;
                curr=curr->next->next;
                bn=0;
            }
            else{
                bn+=curr->val;
                curr=curr->next;
            }
        }
        head=head->next;
        prev->next=NULL;
        return head;
    }
};