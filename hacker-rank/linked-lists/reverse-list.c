#include <stdio.h>
#include <stdlib.h>

/* Source: HackerRank
 Reverse a linked list */

typedef struct list {
    int key;
    struct list *next;
} list;


void appendAtTail(list **root, int item) {
    
    list *node = malloc(sizeof(list));
    list *p = *root;
    
    node->key = item;
    node->next = NULL;
    
    if (*root == NULL) {
        *root = node;
    } else {
        while (p->next) {
            p = p->next;
        }
        p->next = node;
    }
}

void print(list *head) {
    
    if (head) {
        printf("%d ", head->key);
        print(head->next);
    }
}

void reverse(list **head) {
    
    list *prev = NULL, *cur = *head, *temp;
    
    while (cur) {
        temp = cur->next;
        cur->next = prev;
        prev = cur;
        cur = temp;
    }
    *head = prev;
}

int main() {
    
    list *x = NULL;
    
    appendAtTail(&x, 1);
    appendAtTail(&x, 2);
    appendAtTail(&x, 3);
    appendAtTail(&x, 4);
    appendAtTail(&x, 5);
    
    print(x);
    printf("\n");
    
    reverse(&x);
    
    print(x);
    printf("\n");
    
    
    return 0;
}