#include <stdio.h>
#include <stdlib.h>

/* Source: HackerRank
   Merge two sorted linked lists */

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

list* merge(list *headA, list *headB) { /* MERGE B Into A (accepted by hackerrank judge */
    
    list *temp, *A = headA, *B = headB;
    
    while (A && B) {
        
        while (A->next && (A->next)->key < B->key)
            A = A->next;
        
        if (A->key < B->key) {
            temp = B->next;
            B->next = A->next;
            A->next = B;
            B = temp;
        }
        else {
            temp = B->next;
            B->next = A;
            A = B;
            B = temp;
        }
    }
    
    if (headA && headB && headA->key < headB->key)
        return headA;
    else
        return headB;
}

list* merge_recursive(list *headA, list *headB) /* The recursive approach also accepted */
{
    list* result = NULL;
    
    /* Base cases */
    if (headA == NULL)
        return(headB);
    
    else if (headB == NULL)
        return(headA);
    
    /* Pick either a or b, and do it recursively */
    if (headA->key < headB->key) {
        result = headA;
        result->next = merge_recursive(headA->next, headB);
    }
    else {
        result = headB;
        result->next = merge_recursive(headA, headB->next);
    }
    
    return(result);
}

int main() {
    
    list *x = NULL, *y = NULL, *result;
    
    append_to_tail(&x, 5);
    append_to_tail(&x, 7);

    append_to_tail(&y, 1);
    append_to_tail(&y, 2);
    
    /* x = merge(x, y); */
    
    result = merge_recursive(x, y);
    
    print(result);

    
    return 0;
}