#include <stdio.h>
#include <stdlib.h>

/* Source: HackerRank
   Insert a node at a specific position in a linked list  */

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

void insert_nth(list **head, int item, int position) { /* ASSUMING POSITION IS ALWAYS VALID */
    
    list *new_node = malloc(sizeof(list));
    list *p = *head;
    int i = 0;
    
    new_node->key = item;
    
    if (position == 0) {
        new_node->next = *head;
        *head = new_node;
        return;
    }
    
    while (i < position - 1) {
        p = p->next;
        i++;
    }
    
    new_node->next = p->next;
    p->next = new_node;
    
}

void print(list *root) {
    
    if (root) {
        printf("%d ", root->key);
        print(root->next);
    }
}

int main() {
    
    list *x = NULL;
    
    append_to_tail(&x, 1);
    append_to_tail(&x, 2);
    append_to_tail(&x, 3);
    
    print(x);
    printf("\n");
    
    insert_nth(&x, 4, 0); /* insert 4 at position 0 */
    insert_nth(&x, 5, 1); /* insert 5 at position 1 */
    
    print(x);
    printf("\n");
    
    return 0;
}

