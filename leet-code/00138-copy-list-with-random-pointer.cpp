/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL) { return NULL; }
        // make a hash table to help with:
        // given an old reference, give me the new node
        std::unordered_map<Node*, Node*> map;
        
        // make the new head
        Node *new_head = new Node(head->val);
        map[head] = new_head;
        
        // make the rest of the new nodes and fill the map 
        Node *cur = head->next;
        Node *prev_new = new_head;
        while (cur) {
            Node *newNode = new Node(cur->val);
            // connect the new nodes together
            prev_new->next = newNode;
            // add it to the map
            map[cur] = newNode;
            // move on
            prev_new = newNode;
            cur = cur->next;
        }
        
        // connect random pointers
        cur = head;
        while (cur) {
            Node *newNode = map[cur];
            if (cur->random) {
                Node *old_random = cur->random;
                newNode->random = map[old_random];
            }
            cur = cur->next;
        }
        return new_head;
    }
};