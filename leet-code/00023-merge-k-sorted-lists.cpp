/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// we at max have k elements in the heap so 
// n*log(k) is the total complexity
class Solution {
    struct compare {
        bool operator()(const ListNode* l, const ListNode* r) {
            return l->val > r->val;
        }
    };
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *root = NULL;
        ListNode *cur = NULL;
        std::priority_queue<ListNode *, vector<ListNode *>, compare> q;
        
        // add the first element from each list into q
        for (int i = 0; i < lists.size(); i++) {
            if (lists[i]) {
                q.push(lists[i]);
            }
        }
        
        // at this point the heap contains K elements
        // we extract the min element and add it to our list
        // we then push a new element from the same list that we 
        // extract the min element from
        while (!q.empty()) {
            ListNode *min = q.top(); // log(k)
            q.pop();
            
            // add the node to the list we're maintaining
            if (root == NULL) {
                root = min;
                cur = root;
            } else {
                cur->next = min;
                cur = cur->next;
            }
            
            // time to get a new element in the priority queue
            // if this list is empty it's okay, remember that 
            // we have an element from EACH list so we're fine
            if (min->next) {
                q.push(min->next);
            }
        }
        return root;
    }
};


