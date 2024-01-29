/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_map<ListNode*,int> m;
        while(headA!=NULL && headB!=NULL){
            m[headA]++;
            m[headB]++;
            if(m[headA]==2){
                return headA;
            }
            else if(m[headB]==2){
                return headB;
            }
            headA=headA->next;
            headB=headB->next;
        }
        while(headA==NULL && headB!=NULL){
            m[headB]++;
            if(m[headB]==2){
                return headB;
            }
            headB=headB->next;
        }
        while(headB==NULL && headA!=NULL){
            m[headA]++;
            if(m[headA]==2){
                return headA;
            }
            headA=headA->next;
        }
        return NULL;
    }
};