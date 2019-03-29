#include <stdio.h>
#include <stdlib.h>

/* Source: HackerRank
   Print the elements of a linked list in reverse */

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

void print(list *root) {
    
    if (root) {
        printf("%d ", root->key);
        print(root->next);
    }
}

void print_reverse(list *root) {
    
    if (root) {
        print_reverse(root->next);
        printf("%d ", root->key);
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
    
    print_reverse(x);
    printf("\n");
    
    return 0;
}