#include <stdio.h>
#include <stdlib.h>

/* UVa 10954 - Add All */

#define PQ_SIZE 100001

typedef struct {
    long int q[PQ_SIZE+1];
    int n;             /* number of queue elements */
} priority_queue;

void pq_init(priority_queue *pq) {
    pq->n = 0;
}

int left_child(int parent_index) {
    
    return (2 * parent_index);
}

int pq_parent(int child_index) {
    
    if (child_index == 1) /* root */
        return -1;
    
    return ((int) child_index/2); /* floor is implicit */
}

void swap(priority_queue *p, int one, int two) {
    
    long int temp;
    
    temp = p->q[one];
    p->q[one] = p->q[two];
    p->q[two] = temp;
    
}

void bubble_up(priority_queue *p, int child_index) {
    
    int parent_index = pq_parent(child_index);
    
    if (parent_index == -1) /* root! */
        return;
    
    else if (p->q[parent_index] > p->q[child_index]) { /* swap */
        
        swap(p, child_index, parent_index);
        
        bubble_up(p, parent_index);
    }
}

void bubble_down(priority_queue *p, int parent_index) {
    
    int child_index, i, min_index;
    
    child_index = left_child(parent_index);
    
    min_index = parent_index; /* so far */
    
    for (i = 0; i <= 1; i++) /* test whether the left child or the right child is smaller than the parent */
        if ((child_index + i) <= p->n) { /* child exist */
            
            if (p->q[min_index] > p->q[child_index + i])  /* parent > child => switch */
                min_index = child_index + i;
            
        }
    
    if (min_index != parent_index) {
        
        swap(p, min_index, parent_index);
        
        bubble_down(p, min_index);
    }
}

long int extract_min(priority_queue *p) {
    
    long int minimum;
    
    if (p->n < 1)
        return -1; /* ERROR */
    
    minimum = p->q[1];
    
    p->q[1] = p->q[p->n];
    (p->n)--;
    
    bubble_down(p, 1);
    
    return minimum;
}

void pq_insert(priority_queue *p, long int number) { /* O(log n) */
    
    if (p->n >= PQ_SIZE) {
        printf("Error");
        return;
    }
    
    (p->n)++;
    p->q[p->n] = number;
    bubble_up(p, p->n);
}

void pq_print(priority_queue *p) {
    
    int i;
    
    for (i = 1; i <= p->n; i++)
        printf("%ld ", p->q[i]);
    
    printf("\n");
}

int main() {
    
    long int number, current_sum, min1, min2, total_sum;
    int i, n;
    
    priority_queue *p = malloc(sizeof(priority_queue));
    
    pq_init(p);
    
    while ((scanf("%d", &n) == 1) && n) {
        
        for (i = 0; i < n; i++) {
            scanf("%ld", &number);
            pq_insert(p, number);
        }
    
        total_sum = 0;
        
        while (1) {
            min1 = extract_min(p);
            min2 = extract_min(p);
            
            if (min1 == -1 || min2 == -1)
                break;
            
            current_sum = min1 + min2;
            pq_insert(p, current_sum);
        
            total_sum += current_sum;
        }
        printf("%ld\n", total_sum);
    }
    return 0;
}