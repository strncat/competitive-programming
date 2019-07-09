#include <stdio.h>
#include <stdlib.h>

/* Source: HackerRank
   Detect whether a linked list contains a cycle */

typedef struct list {
    int key;
    struct list *next;
} list;

void append_to_tail(list **root, int item) {
    
    list *new_node = malloc(sizeof(list));
    list *p = *root;
    
    new_node->key = item;
    new_node->next = NULL;
    
    if (*root == NULL)
        *root = new_node;
    else {
        while (p->next)
            p = p->next;
        p->next = new_node;
    }
}

void print(list *head) {
    
    if (head) {
        printf("%d ", head->key);
        print(head->next);
    }
}

int cycle(list *head) {
    
    list *slow = head, *fast = head;
    
    while (slow && fast) {
        slow = slow->next;
        fast = (fast->next)->next;
        
        if (slow == fast)
            return 1;
    }
    return 0;
}

int main() {
    
    list *x = NULL;
    
    append_to_tail(&x, 5);
    append_to_tail(&x, 7);
    append_to_tail(&x, 1);
    append_to_tail(&x, 2);

    printf("%d\n", cycle(x));
    
    return 0;
}