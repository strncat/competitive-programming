/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    // recursive
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL) { return l2; }
        if (l2 == NULL) { return l1; }
        
        if (l1->val < l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        } else if (l2) {
            l2->next = mergeTwoLists(l2->next, l1);
            return l2;
        }
        return NULL;
    }
    
    // iterative
    /*
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *dummyHead = new ListNode(0);
        ListNode *cur = dummyHead;
        
        while (l1 && l2) {
            if (l1->val < l2->val) {
                cur->next = l1;
                l1 = l1->next;
            } else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        
        if (l1) {
            cur->next = l1;
        } else if (l2) {
            cur->next = l2;
        }
        
        return dummyHead->next;
    }
    */
};