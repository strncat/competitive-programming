#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* 11034 - Ferry Loading IV
 Sample input
 5
 20 4
 380 left
 720 left
 1340 right
 1040 left
 15 4
 380 left
 720 left
 1340 right
 1040 left
 15 4
 380 left
 720 left
 1340 left
 1040 left
 15 4
 380 right
 720 right
 1340 right
 1040 right
 1 4
 100 right
 100 right
 100 right
 100 left
 Output for sample input
 3
 3
 5
 6
 6
 */

#define QUEUE_SIZE 10000

typedef struct {
    int q[QUEUE_SIZE+1];
    int first;
    int last;
    int count;
} queue;

void init_queue(queue *q)
{
    q->first = 0;
    q->last = QUEUE_SIZE-1;
    q->count = 0;
}

void enqueue(queue *q, int x) {
    
    if (q->count >= QUEUE_SIZE)
        return; /* RRROR */
    
    q->last = (q->last + 1) % QUEUE_SIZE;
    q->q[q->last] = x;
    q->count++;
}

int top(queue *q) {
    
    if (q->count <= 0)
        return -1; /* ERROR */
    
    return q->q[q->first];
}

int dequeue(queue *q) {
    
    int x;
    
    if (q->count <= 0)
        return -1; /* ERROR */
    
    x = q->q[q->first];
    q->first = (q->first + 1) % QUEUE_SIZE;
    q->count--;
    return x;
}

int empty_queue(queue *q) {
    if (q->count <= 0) return (true);
    else return (false);
}

int main() {
    
    int i, test_cases, ferry_length, number_of_cars, car_length, counter, location, total;
    char lane[10];
    queue *left, *right;
    
    left = malloc(sizeof(queue));
    right = malloc(sizeof(queue));
    
    scanf("%d", &test_cases);
    
    while (test_cases--) {
        
        init_queue(left);
        init_queue(right);
        
        scanf("%d %d", &ferry_length, &number_of_cars);
        
        ferry_length = 100 * ferry_length; /* meters to cm */
        
        for (i = 1; i <= number_of_cars; i++) {
            
            scanf("%d %s", &car_length, lane);
            
            if (lane[0] == 'l')
                enqueue(left, car_length);
            else
                enqueue(right, car_length);
        }
        
        counter = 0;
        location = 0; /* initially at left */
        while (!empty_queue(left) || !empty_queue(right)) {

            total = 0;
            
            if (location == 0) { /* take cars from left */
                while (total+top(left) <= ferry_length && top(left) != -1)
                    total += dequeue(left);
            }
            else /* take cars from right */
                while (total+top(right) <= ferry_length && top(right) != -1)
                    total += dequeue(right);
            
            counter++;
            location = !location;
        }
        printf("%d\n", counter);
    }
    return 0;
}