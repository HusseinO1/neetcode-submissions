class Solution {
public:
    bool hasCycle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        // Ensure fast can take two steps safely
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;          // moves 1 step
            fast = fast->next->next;    // moves 2 steps

            if (slow == fast) {         // they collided at the same node
                return true;
            }
        }

        return false; // fast reached nullptr, so no cycle
    }
};