class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        int si=0;
        ListNode* curr=head;
        while(curr!=NULL){
            si++;
            curr=curr->next;
        }

        int it=si/k;

        curr=head;
        ListNode* ah;

        for(int j=0;j<it;j++){
            ListNode* prev;
            ListNode* h1;
            ListNode* ph=h1;
            for(int i=0;i<k;i++){
                ListNode* nxt=curr->next;
                curr->next=prev;
                prev=curr;
                curr=nxt;
                if(i==0){
                    h1=prev;
                }
            }
            if(j!=0){
                ph->next=prev;
            }
            h1->next=curr;
            if(j==0){
                ah=prev;
            }
        }
        return ah;
    }
};