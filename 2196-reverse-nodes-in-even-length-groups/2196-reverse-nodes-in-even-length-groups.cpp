class Solution {
public:
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cin.tie(nullptr);
        cout.tie(NULL);
        
        int si=0;
        ListNode* curr=head;
        
        while(curr!=NULL){
            si++;
            curr=curr->next;
        }

        int i=1;
        vector<int> grp;
        
        while(si>0){
            if(si>i)
                grp.push_back(i);
            else
                grp.push_back(si);
            si-=i;
            i++;
        }

        
        curr=head->next;
        ListNode* prev=head;

        for(int i=1;i<grp.size();i++){
            if(grp[i]&1){
                for(int j=0;j<grp[i];j++){
                    prev=curr;
                    curr=curr->next;
                }
            }
            else{
                ListNode* pre;
                ListNode* nh=curr;
                for(int j=0;j<grp[i];j++){
                    ListNode* nxt=curr->next;
                    curr->next=pre;
                    pre=curr;
                    curr=nxt;
                }
                prev->next=pre;
                nh->next=curr;
                prev=nh;
            }
        }
        return head;
    }
};