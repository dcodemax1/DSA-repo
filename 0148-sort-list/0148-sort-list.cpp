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
    ListNode* findMiddle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* merge(ListNode* List1, ListNode* List2) {
        ListNode* dummyNode = new ListNode(-1);
        ListNode* temp = dummyNode;

        while (List1 != NULL && List2 != NULL) {
            if (List1->val <= List2->val) {
                temp->next = List1;
                temp = List1;
                List1 = List1->next;

            } else {
                temp->next = List2;
                temp = List2;
                List2 = List2->next;
            }
        }

        if (List1 != NULL) {
            temp->next = List1;

        } else {
            temp->next = List2;
        }

        return dummyNode->next;
    }

    ListNode* sortList(ListNode* head) {

        if (head == NULL || head->next == NULL)
            return head;

        ListNode* middle = findMiddle(head);
        ListNode* secondHead = middle->next;

        ListNode* firstHead = head;
        middle->next = NULL;

        firstHead = sortList(firstHead);
        secondHead = sortList(secondHead);

        return merge(firstHead, secondHead);
        ;
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
   ListNode* sortList(ListNode* head) {
       ListNode* temp = head;

       vector<int> arr;

       while(temp != NULL){

           arr.push_back(temp->val);
           temp = temp->next;
       }

       sort(arr.begin(), arr.end());

       temp = head;
       int index = 0;
       while(temp != NULL){
       temp->val= arr[index];
       index++;
       temp= temp->next;

       }
       return head;

   }
};

*/