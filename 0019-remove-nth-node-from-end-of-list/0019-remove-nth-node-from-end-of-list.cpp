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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head;

        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }

        ListNode* slow = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next;
        }

        ListNode* delNode = head;
        if (fast == NULL) {
            delNode = head;
            head = head->next;
            delete delNode;
            return head;
        }

        delNode = slow->next;

        slow->next = slow->next->next;

        delete delNode;
        return head;
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
   ListNode* removeNthFromEnd(ListNode* head, int n) {
       ListNode* temp = head;

       int cnt = 0;

       while(temp != NULL){
           cnt++;
           temp = temp->next;
       }
       if(cnt == n){
           ListNode* delNode = head;
           head = head->next;
           delete delNode;
           return head;
       }
       int res = cnt-n;

       temp = head;

       while(temp != NULL){
         res--;
         if(res==0)break;
         temp= temp->next;
       }

       ListNode* delNode = temp ->next;


       temp->next = temp->next->next;
       delete delNode;

       return head;
   }
};

*/