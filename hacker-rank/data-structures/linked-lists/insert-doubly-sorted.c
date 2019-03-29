#include <stdio.h>
#include <stdlib.h>

/* Insert a node into a sorted doubly linked list */

typedef struct list {
    int key;
    struct list *next;
    struct list *prev;
} list;

void print(list *head) {
    
    if (head) {
        printf("%d ", head->key);
        print(head->next);
    }
}

void insert_sorted(list **head, int key) {
    
    list *p = *head;
    list *new_node = malloc(sizeof(list));
    
    new_node->key = key;
    new_node->next = NULL;
    new_node->prev = NULL;
    
    if (*head == NULL)
        *head = new_node;
    
    else if (key < (*head)->key) {
        new_node->next = *head;
        (*head)->prev = new_node;
        *head = new_node;
    }
    else {
        while (p->next && (p->next)->key < key)
            p = p->next;
        
        if (p->next) { /* if not the last node */
            (p->next)->prev = new_node;
            new_node->next = p->next;
        }
        
        new_node->prev = p;
        p->next = new_node;
    }
}

int main() {
    
    list *x = NULL;
    
    print(x);
    printf("\n");
    
    insert_sorted(&x, 2);
    print(x);
    printf("\n");
    
    insert_sorted(&x, 1);
    print(x);
    printf("\n");
    
    insert_sorted(&x, 4);
    print(x);
    printf("\n");
    
   
    
    return 0;
}