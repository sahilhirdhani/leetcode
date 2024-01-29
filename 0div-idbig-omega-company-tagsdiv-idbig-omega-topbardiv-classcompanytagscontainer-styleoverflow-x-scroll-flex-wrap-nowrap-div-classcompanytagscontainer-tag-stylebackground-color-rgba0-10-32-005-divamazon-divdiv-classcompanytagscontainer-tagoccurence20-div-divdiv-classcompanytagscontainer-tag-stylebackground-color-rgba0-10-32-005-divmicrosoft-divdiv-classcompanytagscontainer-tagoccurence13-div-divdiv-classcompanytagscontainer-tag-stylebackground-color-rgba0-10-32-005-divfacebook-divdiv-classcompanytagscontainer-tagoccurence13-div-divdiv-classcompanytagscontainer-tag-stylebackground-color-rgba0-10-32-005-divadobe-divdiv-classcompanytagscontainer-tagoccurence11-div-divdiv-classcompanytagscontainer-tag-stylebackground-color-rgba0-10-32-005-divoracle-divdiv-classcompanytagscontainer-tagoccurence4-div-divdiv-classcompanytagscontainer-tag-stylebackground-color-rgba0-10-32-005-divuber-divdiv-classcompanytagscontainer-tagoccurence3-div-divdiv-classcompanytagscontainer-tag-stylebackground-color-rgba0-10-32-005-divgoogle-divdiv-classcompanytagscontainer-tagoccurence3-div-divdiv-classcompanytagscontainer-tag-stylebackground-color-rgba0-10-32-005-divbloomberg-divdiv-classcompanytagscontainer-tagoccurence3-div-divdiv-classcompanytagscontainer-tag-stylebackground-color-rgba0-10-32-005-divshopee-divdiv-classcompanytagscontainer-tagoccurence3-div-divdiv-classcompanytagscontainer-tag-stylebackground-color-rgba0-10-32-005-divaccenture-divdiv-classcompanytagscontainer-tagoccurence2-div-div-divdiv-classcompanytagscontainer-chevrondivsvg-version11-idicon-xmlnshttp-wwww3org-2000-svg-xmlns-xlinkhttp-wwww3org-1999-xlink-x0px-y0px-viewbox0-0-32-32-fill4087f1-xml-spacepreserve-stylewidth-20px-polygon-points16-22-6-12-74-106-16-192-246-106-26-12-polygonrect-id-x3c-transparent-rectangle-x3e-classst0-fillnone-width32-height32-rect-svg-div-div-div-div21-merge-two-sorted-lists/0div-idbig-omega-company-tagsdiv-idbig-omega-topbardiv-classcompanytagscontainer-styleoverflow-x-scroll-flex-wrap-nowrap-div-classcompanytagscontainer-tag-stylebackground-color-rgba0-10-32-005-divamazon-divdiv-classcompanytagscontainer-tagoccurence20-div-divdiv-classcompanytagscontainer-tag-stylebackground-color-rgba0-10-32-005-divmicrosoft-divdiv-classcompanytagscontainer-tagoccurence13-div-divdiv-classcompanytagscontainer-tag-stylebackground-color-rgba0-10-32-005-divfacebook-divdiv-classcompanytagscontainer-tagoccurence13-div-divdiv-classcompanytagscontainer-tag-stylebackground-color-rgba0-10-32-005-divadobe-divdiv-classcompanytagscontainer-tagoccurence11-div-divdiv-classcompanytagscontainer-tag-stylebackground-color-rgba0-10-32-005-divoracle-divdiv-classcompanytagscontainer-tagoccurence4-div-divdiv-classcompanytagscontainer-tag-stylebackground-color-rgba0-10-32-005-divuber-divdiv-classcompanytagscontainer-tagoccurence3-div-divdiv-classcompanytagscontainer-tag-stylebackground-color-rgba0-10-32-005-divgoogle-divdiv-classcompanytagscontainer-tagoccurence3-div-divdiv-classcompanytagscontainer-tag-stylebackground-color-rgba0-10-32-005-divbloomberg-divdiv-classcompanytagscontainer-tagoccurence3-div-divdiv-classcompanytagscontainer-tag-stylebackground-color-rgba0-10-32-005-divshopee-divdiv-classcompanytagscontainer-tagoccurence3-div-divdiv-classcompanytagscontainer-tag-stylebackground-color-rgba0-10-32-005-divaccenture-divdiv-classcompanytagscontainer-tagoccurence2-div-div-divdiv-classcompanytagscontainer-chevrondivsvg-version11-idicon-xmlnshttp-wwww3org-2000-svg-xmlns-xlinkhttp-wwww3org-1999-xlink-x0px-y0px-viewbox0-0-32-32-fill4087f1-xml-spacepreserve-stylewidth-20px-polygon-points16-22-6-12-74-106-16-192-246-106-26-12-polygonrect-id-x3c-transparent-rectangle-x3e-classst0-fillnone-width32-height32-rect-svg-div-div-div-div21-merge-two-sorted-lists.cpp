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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        ListNode* head=new ListNode();
        ListNode* curr=head;
        
        ListNode* curr1=list1;
        ListNode* curr2=list2;

        while(curr1!=NULL && curr2!=NULL){
            
            ListNode* n=new ListNode();
            
            if(curr1->val > curr2->val){
                n->val = curr2->val;
                curr2 = curr2->next;
            }
            else{
                n->val = curr1->val;
                curr1 = curr1->next;
            }
            
            curr->next=n;
            curr=curr->next;

        }
        if(curr1==NULL && curr2!=NULL){
            curr->next=curr2;
        }
        else if(curr2==NULL && curr1!=NULL){
            curr->next=curr1;
        }
        return head->next;
    }
};