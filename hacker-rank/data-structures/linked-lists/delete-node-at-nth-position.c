#include <stdio.h>
#include <stdlib.h>

/* Source: HackerRank
   Delete a node from a linked list */

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

void delete_nth(list **head, int position) { /* ASSUMING POSITION IS ALWAYS VALID */
    
    list *p = *head, *temp;
    int i = 0;
    
    if (position == 0) {
        *head = p->next;
        free(p);
        return;
    }
    
    while (i < position - 1) {
        p = p->next;
        i++;
    }
    
    temp = p->next; /* node to delete */
    p->next = temp->next;
    free(temp);
    
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
    append_to_tail(&x, 4);
    append_to_tail(&x, 5);
    
    print(x);
    printf("\n");

    delete_nth(&x, 0);
    delete_nth(&x, 3);
    
    print(x);
    printf("\n");
    
    return 0;
}