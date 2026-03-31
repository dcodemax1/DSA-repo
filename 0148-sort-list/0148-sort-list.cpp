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