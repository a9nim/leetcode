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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* back_ptr = head; 
        ListNode* front_ptr = head;  
        for (int i = 0; i < n; ++i) {
            front_ptr = front_ptr->next;
        }
        if (front_ptr == nullptr) {
            ListNode* ans = head->next;
            delete head;
            return ans;
        }
        while (front_ptr->next != nullptr) {
            front_ptr = front_ptr->next; 
            back_ptr = back_ptr->next;
        }
        ListNode* to_delete = back_ptr->next;
        back_ptr->next = to_delete->next;
        delete to_delete;
        return head;
    }
};
