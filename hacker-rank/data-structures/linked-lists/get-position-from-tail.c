#include <stdio.h>
#include <stdlib.h>

/* Source: HackerRank
   Get the value of the node at a specific position from the tail */

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

int find(list *head, int position_from_tail) { /* MERGE B Into A (accepted by hackerrank judge */
    
    list *cur = head, *forward = head;
    
    int i = 0;
    while (i < position_from_tail) {
        forward = forward->next;
        i++;
    }
    
    while (forward->next) {
        forward = forward->next;
        cur = cur->next;
    }
    
    return cur->key;
}

int main() {
    
    list *x = NULL;
    
    append_to_tail(&x, 5);
    append_to_tail(&x, 7);
    append_to_tail(&x, 1);
    append_to_tail(&x, 2);

    
    printf("%d\n", find(x, 0));
    printf("%d\n", find(x, 2));
    
    return 0;
}