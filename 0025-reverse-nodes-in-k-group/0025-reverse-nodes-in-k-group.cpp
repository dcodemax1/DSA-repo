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
    ListNode* findKthNode(ListNode* head, int k) {
        ListNode* temp = head;
        k--;
        while (temp != NULL && k != 0) {
            temp = temp->next;
            k--;
        }
        return temp;
    }

    ListNode* reverseList(ListNode* head) {

        if (head == NULL || head->next == NULL)
            return head;

        ListNode* newHead = reverseList(head->next);

        ListNode* front = head->next;
        front->next = head;
        head->next = nullptr;
        return newHead;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevNode = NULL;

        while (temp != NULL) {
            ListNode* kthNode = findKthNode(temp, k);

            if (kthNode == NULL) {
                if (prevNode) {
                    prevNode->next = temp;
                    break;
                }
            }

            ListNode* nextNode = kthNode->next;

            kthNode->next = nullptr;

            ListNode* newHead = reverseList(temp);

            if (temp == head) {
                head = newHead;
            } else {
                prevNode->next = kthNode;
            }

            prevNode = temp;
            temp = nextNode;
        }

        return head;
    }
};