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

 // optimal 
class Solution {
public:
    ListNode* findKthNode(ListNode* head, int k) {
        ListNode* kth = head;
        k--;
        while (kth != NULL && k != 0) {
            kth = kth->next;
            k--;
        }
        return kth;
    }

    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;

        ListNode* newHead = reverseList(head->next);

        ListNode* front = head->next;
        front->next = head;
        head->next = NULL;
        return newHead;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;

        ListNode* prevNode = NULL;
        while (temp != NULL) {
            ListNode* kthNode = findKthNode(temp, k);
            if (kthNode == NULL) {
                if (prevNode)
                    prevNode->next = temp;
                break;
            }

            ListNode* nextNode = kthNode->next;
            kthNode->next = NULL;

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