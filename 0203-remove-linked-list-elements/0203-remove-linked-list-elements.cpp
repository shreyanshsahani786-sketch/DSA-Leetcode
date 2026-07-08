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
    ListNode* removeElements(ListNode* head, int val) {

        // base case of recursion

        if (head == NULL)
        return NULL;

        // remaining lists

        head->next = removeElements(head->next, val);

        if(head->val == val){

            ListNode* temp = head->next;
            delete head;
            return temp;
        }

        return head;
        
    }
};