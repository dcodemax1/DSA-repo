/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// Optimal Approach

class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        if (headA == NULL || headB == NULL)
            return NULL;
        ListNode* t1 = headA;
        ListNode* t2 = headB;

        while (t1 != t2) {

            t1 = t1->next;
            t2 = t2->next;

            if (t1 == t2)
                return t1;

            if (t1 == NULL)
                t1 = headB;
            if (t2 == NULL)
                t2 = headA;
        }
        return t1;
    }
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// Better Approach

/*
class Solution {

   ListNode* findCollision(ListNode* t1, ListNode* t2, int diff) {
       while (diff) {
           diff--;
           t2 = t2->next;
       }

       while (t1 != t2) {
           t1 = t1->next;
           t2 = t2->next;
       }
       return t1;
   }

public:
   ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
       ListNode* t1 = headA;
       ListNode* t2 = headB;
       int n1 = 0, n2 = 0;

       while (t1 != NULL) {
           n1++;
           t1 = t1->next;
       }

       while (t2 != NULL) {
           n2++;
           t2 = t2->next;
       }

       t1 = headA;
       t2 = headB;

       if (n2 > n1) {
           return findCollision(t1, t2, n2 - n1);
       } else {
           return findCollision(t2, t1, n1 - n2);
       }
   }
};

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// Brute Force with using map

/*
class Solution {
public:
   ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
       unordered_map<ListNode*, int> mp;

       ListNode* temp1 = headA;
       ListNode* temp2 = headB;

       while (temp1 != NULL) {
           mp[temp1]++;
           temp1 = temp1->next;
       }

       while (temp2 != NULL) {
           if (mp.find(temp2) != mp.end()) {
               return temp2;
           }
           temp2 = temp2->next;
       }
       return NULL;
   }
};
*/