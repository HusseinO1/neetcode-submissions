class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;

        // 1. Find the middle node
        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Split the list into two halves
        ListNode* second = slow->next;
        slow->next = nullptr;

        // 2. Reverse the second half
        ListNode* prev = nullptr;
        ListNode* curr = second;
        while (curr) {
            ListNode* nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        second = prev; // 'second' now points to the reversed second half

        // 3. Merge/interleave the two halves
        ListNode* first = head;
        while (second) {
            ListNode* tmp1 = first->next;
            ListNode* tmp2 = second->next;

            first->next = second;
            second->next = tmp1;

            first = tmp1;
            second = tmp2;
        }
    }
};