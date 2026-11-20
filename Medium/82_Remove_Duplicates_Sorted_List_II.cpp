
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* current = dummy;

        while (current->next != NULL && current->next->next != NULL) {
            if (current->next->val == current->next->next->val) {
                int value = current->next->val;

                while (current->next != NULL && current->next->val == value) {
                    current->next = current->next->next;
                }
            }
            else {
                current = current->next;
            }
        }

        return dummy->next;
    }
};
