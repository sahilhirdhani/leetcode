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
    struct Compare{
        bool operator()(ListNode* a,ListNode* b){
            return a->val > b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cin.tie(nullptr);
        if(lists.size()==0){
            return NULL;
        }
        priority_queue<ListNode*, vector<ListNode*>, Compare> pq;
        for(auto x:lists){
            while(x){
                pq.push(x);
                x=x->next;
            }
        }
        if(pq.size()==0){
            return NULL;
        }
        ListNode* head=pq.top();
        ListNode* curr=head;
        pq.pop();
        while(pq.size()){
            curr->next=pq.top();
            curr=curr->next;
            pq.pop();
        }
        curr->next=NULL;
        return head;
    }
};