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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cin.tie(nullptr);

        int size = 0;
        ListNode* current = head;
        vector<ListNode*> result;

        while (current) {
            size++;
            current = current->next;
        }

        int quotient = size / k; // Minimum number of nodes in each part
        int remainder = size % k; // Number of parts that get one extra node

        current = head;
        ListNode* previous = nullptr;

        for (int i = 0; i < k; i++) {
            result.push_back(current);

            int partSize = quotient + (i < remainder ? 1 : 0);

            for (int j = 0; j < partSize; j++) {
                previous = current;
                current = current->next;
            }

            if (previous) {
                previous->next = nullptr;
            }
        }

        return result;
    }
};
