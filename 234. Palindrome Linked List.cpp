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
    ListNode* slow;
    ListNode* fast;
    
    bool isPalindrome(ListNode* head) {
        ListNode* tail, *h2, *prev;
        if(!head || !head->next)return true;
        fast = slow = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        h2 = fast ? slow->next : slow;
        tail = NULL;
        while(prev){
            prev = h2->next;
            h2->next = tail;
            tail = h2;
            h2 = prev;
        }
        while(tail){
            if(tail->val != head->val)
                return false;
            tail = tail->next;
            head = head->next;
        }
        return true;
    }
};