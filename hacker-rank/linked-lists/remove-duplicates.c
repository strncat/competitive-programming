#include <stdio.h>
#include <stdlib.h>

/* Source: HackerRank
   Delete duplicate-value nodes from a sorted linked list */

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

void remove_duplicates(list *head) {
    
    list *prev = head, *cur = head->next;
    
    while (cur) {
        if (prev->key == cur->key) {
            prev->next = cur->next;
            free(cur);
            cur = prev->next;
        } else {
            prev = prev->next;
            cur = prev->next;
        }
    }
}

int main() {
    
    list *x = NULL;
    
    append_to_tail(&x, 3);
    append_to_tail(&x, 3);
    append_to_tail(&x, 3);

    remove_duplicates(x);
    
    print(x);
    
    return 0;
}