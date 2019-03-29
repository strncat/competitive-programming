#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* 11995 - I Can Guess the Data Structure! */

/* ----------------------- Priority Queue (Min = 0) and (Max = 1) ----------------------- */

#define PQ_SIZE 1001

typedef struct {
    int q[PQ_SIZE+1];
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
    
    int temp;
    
    temp = p->q[one];
    p->q[one] = p->q[two];
    p->q[two] = temp;
    
}

void bubble_up(priority_queue *p, int child_index) {
    
    int parent_index = pq_parent(child_index);
    
    if (parent_index == -1) /* root! */
        return;
    
    else if (p->q[parent_index] < p->q[child_index]) { /* swap */
        
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
            
            if (p->q[min_index] < p->q[child_index + i])  /* parent > child => switch */
                min_index = child_index + i;
            
        }
    
    if (min_index != parent_index) {
        
        swap(p, min_index, parent_index);
        
        bubble_down(p, min_index);
    }
}

int extract_max(priority_queue *p) {
    
    int number;
    
    if (p->n < 1)
        return -1; /* ERROR */
    
    number = p->q[1];
    
    p->q[1] = p->q[p->n];
    (p->n)--;
    
    bubble_down(p, 1);
    
    return number;
}

void pq_insert(priority_queue *p, int number) { /* O(log n) */
    
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
        printf("%d ", p->q[i]);
    
    printf("\n");
}

/* ------------------------------------ STACK ------------------------------------  */

#define STACK_SIZE 1001

typedef struct {
    int s[STACK_SIZE];
    int n;
} stack;

void stack_init(stack *s) {
    s->n = 1;
}

void stack_push(stack *s, int number) {
    
    if (s->n >= STACK_SIZE)
        return; /* error */
    
    s->s[s->n] = number;
    (s->n)++;
}

int stack_pop(stack *s) {
    
    int number;
    
    if (s->n == 0)
        return -1; /* error */
    
    (s->n)--;
    number = s->s[s->n];
    
    return number;
}

/* ------------------------------------ Queue ------------------------------------  */

#define QUEUE_SIZE 1001

typedef struct queue {
    int q[QUEUE_SIZE];
    int tail;
    int head;
    int count;
} queue;

void queue_init(queue *q) {
    q->tail = 0;
    q->head = 1;
    q->count = 0;
}

void enqueue(queue *q, int number) {
    
    if (q->count >= QUEUE_SIZE)
        return; /* ERROR */
    
    q->tail = (q->tail + 1) % QUEUE_SIZE;
    q->q[q->tail] = number;
    q->count++;
    
}

int dequeue(queue *q) {
    
    int number;
    
    if (q->count <= 0)
        return -1; /* ERROR */
    
    number = q->q[q->head];
    q->head = (q->head + 1) % QUEUE_SIZE;
    q->count--;
    
    return number;
    
}

/* ------------------------------------ Main ------------------------------------  */

int main() {
    
    bool p_flag, s_flag, q_flag;
    int number, type, i, n;
    int p_result, s_result, q_result;
    
    priority_queue *p = malloc(sizeof(priority_queue));
    stack *s = malloc(sizeof(stack));
    queue *q = malloc(sizeof(queue));
    
    pq_init(p);
    stack_init(s);
    queue_init(q);
    
    while ((scanf("%d", &n) == 1)) {
        
        pq_init(p);
        stack_init(s);
        queue_init(q);
        
        p_flag = true;
        s_flag = true;
        q_flag = true;
        
        for (i = 0; i < n; i++) {
     
            scanf("%d %d", &type, &number);
            
            if (type == 1) {
                pq_insert(p, number);
                stack_push(s, number);
                enqueue(q, number);
            }
            else {
                p_result = extract_max(p);
                s_result = stack_pop(s);
                q_result = dequeue(q);
                
                s_flag &= (number == s_result) && (s_result != -1);
                p_flag &= (number == p_result) && (p_result != -1);
                q_flag &= (number == q_result) && (q_result != -1);
                
            }
        }
        
        if (p_flag + s_flag + q_flag > 1)
            printf("not sure\n");
        
        else if (s_flag)
            printf("stack\n");
        
        else if (q_flag)
            printf("queue\n");
        
        else if (p_flag)
            printf("priority queue\n");
        
        else
            printf("impossible\n");
  
    }
    return 0;
}

