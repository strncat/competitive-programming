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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        //if (l1 == NULL && l2 == NULL) { return NULL; }
        ListNode *head = new ListNode(0);
        ListNode *cur = head;
        int sum = 0;
        while (l1 || l2) {
            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }
            cur->next = new ListNode(sum%10);
            sum /= 10;
            cur = cur->next;
        }
        if (sum) {
            cur->next = new ListNode(sum);
        }
        return head->next;
    }
};