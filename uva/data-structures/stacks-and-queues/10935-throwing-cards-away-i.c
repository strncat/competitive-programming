#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/* 10935 - Throwing cards away I
 Sample input
 7
 19
 10
 6
 1
 10
 11
 17
 0
 Sample Output
 Discarded cards: 1, 3, 5, 7, 4, 2
 Remaining card: 6
 Discarded cards: 1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 4, 8, 12, 16, 2, 10, 18, 14
 Remaining card: 6
 Discarded cards: 1, 3, 5, 7, 9, 2, 6, 10, 8
 Remaining card: 4
 Discarded cards: 1, 3, 5, 2, 6
 Remaining card: 4
 Discarded cards:
 Remaining card: 1
 Discarded cards: 1, 3, 5, 7, 9, 2, 6, 10, 8
 Remaining card: 4
 Discarded cards: 1, 3, 5, 7, 9, 11, 4, 8, 2, 10
 Remaining card: 6
 Discarded cards: 1, 3, 5, 7, 9, 11, 13, 15, 17, 4, 8, 12, 16, 6, 14, 10
 Remaining card: 2
 */

#define QUEUE_SIZE 60

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
    
    int i, n, insert_back;
    queue *cards, *out;
    
    cards = malloc(sizeof(queue));
    out = malloc(sizeof(out));
    
    while (scanf("%d", &n) == 1 && n) {
        
        init_queue(cards);
        init_queue(out);
        
        for (i = 1; i <= n; i++)
            enqueue(cards, i);
        
        while (!empty_queue(cards)) {
            
            enqueue(out, dequeue(cards));
            insert_back = dequeue(cards);
            
            if (insert_back != -1)
                enqueue(cards, insert_back);
        }
        
        printf("Discarded cards:");
        while (out->count > 2) {
            printf(" %d,", dequeue(out));
        }
        if (out->count == 2)
            printf(" %d", dequeue(out));
        
        printf("\nRemaining card: %d\n", dequeue(out));
    }
    return 0;
}