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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = NULL, *prev = NULL;
        int carry = 0;
        
        while(l1 || l2){
            int v1 = l1?l1->val:0;
            int v2 = l2?l2->val:0;
            int v3 = v1 + v2 + carry;
            
            int val = v3%10;
            carry = v3/10;
            
            ListNode* cur = new ListNode(val);
            if(!head) head = cur;
            if(prev) prev->next = cur;
            prev = cur;
            
            l1 = l1?l1->next: NULL;
            l2 = l2?l2->next: NULL;            
        }
        if(carry>0){
            ListNode* last = new ListNode(carry);
            prev->next = last;
        }
        return head;
    }
};