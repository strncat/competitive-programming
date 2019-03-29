#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* UVa 1203 - Argus */

#define PQ_SIZE 10000

typedef struct {
    long int q_num;
    long int period;
    
} record;

typedef struct {
    record q[PQ_SIZE+1];
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
    
    long int temp, temp2;
    
    temp = p->q[one].period;
    p->q[one].period = p->q[two].period;
    p->q[two].period = temp;
    
    temp2 = p->q[one].q_num;
    p->q[one].q_num = p->q[two].q_num;
    p->q[two].q_num = temp2;
    
}

void bubble_up(priority_queue *p, int child_index) {
    
    int parent_index = pq_parent(child_index);
    
    if (parent_index == -1) /* root! */
        return;
    
    else if (p->q[parent_index].period > p->q[child_index].period) { /* swap */
        
        swap(p, child_index, parent_index);
        
        bubble_up(p, parent_index);
    }
    
    else if ((p->q[parent_index].period == p->q[child_index].period) && (p->q[parent_index].q_num > p->q[child_index].q_num)) {
        
        swap(p, child_index, parent_index);
        
        bubble_up(p, parent_index);
    }
}

void bubble_down(priority_queue *p, int parent_index) {
    
    int child_index, i, min_index;
        child_index = left_child(parent_index);
        min_index = parent_index; /* so far */        for (i = 0; i <= 1; i++) /* test whether the left child or the right child is smaller than the parent */        if ((child_index + i) <= p->n) { /* child exist */
            
            if (p->q[min_index].period > p->q[child_index + i].period)  /* parent > child => switch */
                min_index = child_index + i;
            
            else if (p->q[min_index].period == p->q[child_index + i].period) {

                if (p->q[min_index].q_num > p->q[child_index + i].q_num)
                    min_index = child_index + i;
            }
        }        if (min_index != parent_index) {        
        swap(p, min_index, parent_index);
                bubble_down(p, min_index);
    }
}

record extract_min(priority_queue *p) {
    
    record minimum;
    
    minimum.period = -1;
    minimum.q_num = -1;
    
    if (p->n < 1)
        return minimum; /* ERROR */
    
    minimum.period = p->q[1].period;
    minimum.q_num = p->q[1].q_num;
    
    p->q[1] = p->q[p->n];
    (p->n)--;
    
    bubble_down(p, 1);
    
    return minimum;
}

void pq_insert(priority_queue *p, long int period, long int q_num) { /* O(log n) */
    
    if (p->n >= PQ_SIZE) {
        printf("Error");
        return;
    }
    
    (p->n)++;
    p->q[p->n].period = period;
    p->q[p->n].q_num = q_num;
    bubble_up(p, p->n);
}

void pq_print(priority_queue *p) {
    
    int i;
    
    for (i = 1; i <= p->n; i++)
        printf("[%ld %ld] ", p->q[i].q_num, p->q[i].period);
    
    printf("\n");
}

int main() {
    
    long int period, k=0, q_num, periods[3001];
    char garbage[10];
    record min;
    
    priority_queue *p = malloc(sizeof(priority_queue));
    
    pq_init(p);
    
    while (scanf("%s", garbage) == 1) {
        
        if (strcmp(garbage, "#") == 0) {
            scanf("%ld", &k);
            break;
        }
        scanf("%ld", &q_num);
        scanf("%ld", &period);
        
        periods[q_num] = period;
        
        pq_insert(p, period, q_num);
    }
    
    while (k--) {
        
        min = extract_min(p);
        
        printf("%ld\n", min.q_num);
        
        pq_insert(p, min.period + periods[min.q_num], min.q_num);
        
    }
    return 0;
}