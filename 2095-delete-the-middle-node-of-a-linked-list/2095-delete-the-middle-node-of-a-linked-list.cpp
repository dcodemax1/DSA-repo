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
 // Brute Force
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        int cnt = 0;
        ListNode* temp = head;

        if (head == NULL || head->next == NULL)
            return NULL;

        while (temp != NULL) {
            cnt++;
            temp = temp->next;
        }

        int res = cnt / 2;

        temp = head;

        while (temp != NULL) {
            res--;

            if (res == 0) {
                ListNode* middle = temp->next;
                temp->next = temp->next->next;
                delete middle;
                return head;
            }
            temp = temp->next;
        }
        return head;
    }
};