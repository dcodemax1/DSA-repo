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

// Optimal Approach

class Solution {
public:
    ListNode* reverseHead(ListNode* head) {

        if (head == NULL || head->next == NULL) {
            return head;
        }

        ListNode* newHead = reverseHead(head->next);
        ListNode* front = head->next;
        front->next = head;
        head->next = NULL;

        return newHead;
    }

    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* newHead = reverseHead(slow->next);
        ListNode* first = head;
        ListNode* second = newHead;

        while (second != NULL) {
            if (first->val != second->val) {
                reverseHead(newHead);
                return false;
            }
            first = first->next;
            second = second->next;
        }
        reverseHead(newHead);
        return true;
    }
};

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
/*
class Solution {
public:
   bool isPalindrome(ListNode* head) {
       stack<int> st;

       ListNode* temp = head;

       while(temp != NULL){
           st.push(temp->val);
           temp = temp ->next;
       }

       temp = head;
       while(temp != NULL){
           if(temp->val != st.top()){
               return false;
           }
           st.pop();
           temp = temp->next;
       }
       return true;
   }
};
*/