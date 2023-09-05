class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL){
            return NULL;
        }
        Node* curr=head;
        int i=0;
        Node* h1=new Node(0);
        Node* curr1=h1;
        Node* prev=new Node(0);
        prev->next=curr1;
        vector<Node*> m;
        while(curr!=NULL){
            curr1->val = curr->val;
            m.push_back(curr1);
            curr->val = i;
            curr = curr->next;
            Node* n = new Node(0);
            curr1->next = n;
            curr1 = curr1->next;
            prev=prev->next;
            i++;
        }
        
        prev->next=NULL;
        curr=head;
        curr1=h1;

        for(int j=0;j<i;j++){
            if(curr->random == NULL){
                curr1->random = NULL;
            }
            else{
                curr1->random = m[curr->random->val];
            }
            curr=curr->next;
            curr1=curr1->next;
        }
        return h1;
    }
};