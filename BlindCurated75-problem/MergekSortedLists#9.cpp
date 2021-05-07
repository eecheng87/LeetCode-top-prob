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
class Compare {
public:
    bool operator()(const ListNode* a, const ListNode* b){
        return a->val > b->val;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, Compare> pq;
        int n = lists.size();
        for(int i = 0; i < n; i++){
            if(lists[i])
                pq.push(lists[i]);
        }
        ListNode* dum = new ListNode(0);
        ListNode* cur = dum;
        while(!pq.empty()){
            ListNode* top = pq.top();
            cur->next = top;
            cur = cur->next;
            pq.pop();
            top = top->next;
            if(top)
                pq.push(top);
        }
        return dum->next;
    }
};