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
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* current = dummy;

        while (current->next != NULL && current->next->next != NULL) {
            ListNode* first = current->next;
            ListNode* second = first->next;

            first->next = second->next;
            second->next = first;
            current->next = second;

            current = first;
        }

        return dummy->next;
    }
};