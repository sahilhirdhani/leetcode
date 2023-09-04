class Solution {
 public:
  bool hasCycle(ListNode* head) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.tie(NULL);  
    ListNode* slow = head;
    ListNode* fast = head;

    while (fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
      if (slow == fast)
        return true;
    }

    return false;
  }
};