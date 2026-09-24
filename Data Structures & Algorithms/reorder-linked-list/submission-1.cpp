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
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* curr = slow->next;
        ListNode* prev = nullptr;
        slow->next = nullptr;

        while(curr)
        {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        ListNode* front = head;

        //prev is our back

        while(prev != nullptr)
{
    ListNode* t1 = front->next;
    ListNode* t2 = prev->next;

    front->next = prev;
    prev->next = t1;
    front = t1;
    prev = t2;
}
    }
};
