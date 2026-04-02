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
    ListNode* rotateRight(ListNode* head, int k) {

        if (head == NULL || head->next == NULL)
            return head;

        ListNode* tail = head;
        int len = 1;

        while (tail != NULL && tail->next != NULL) {
            len++;
            tail = tail->next;
        }

        if (k % len == 0)
            return head;

        k = k % len;
        
        tail->next = head;

        int cnt = len - k;
        ListNode* temp = head;

        while (temp != NULL && temp->next != NULL) {
            cnt--;
            if (cnt == 0)
                break;
            temp = temp->next;
        }

        ListNode* newHead = temp->next;
        temp->next = NULL;

        return newHead;
    }
};