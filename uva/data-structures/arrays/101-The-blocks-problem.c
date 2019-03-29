#include <stdio.h>
#include <string.h>

/* 101 - The Blocks Problem
 Sample Input
 10
 move 9 onto 1
 move 8 over 1
 move 7 over 1
 move 6 over 1
 pile 8 over 6
 pile 8 over 5
 move 2 over 1
 move 4 over 9
 quit
 Sample Output
 0: 0
 1: 1 9 2 4
 2:
 3: 3
 4:
 5: 5 8 7 6
 6:
 7:
 8:
 9:
 
 15
 move 10 onto 1
 move 8 over 1
 move 7 over 9
 move 6 over 10
 pile 14 over 6
 pile 8 onto 5
 pile 1 onto 6
 move 12 over 1
 move 14 onto 9
 quit
 
 0: 0
 1:
 2: 2
 3: 3
 4: 4
 5: 5 8 6 1 10 12
 6:
 7: 7
 8:
 9: 9 14
 10:
 11: 11
 12:
 13: 13
 14:
 
 15
 move 10 onto 1
 move 8 over 1
 move 2 over 9
 move 6 over 10
 pile 8 over 6
 pile 8 onto 5
 pile 1 onto 5
 quit
 move 12 over 1
 move 14 onto 9
 quit
 
 0: 0
 1:
 2:
 3: 3
 4: 4
 5: 5 1 10
 6: 6
 7: 7
 8: 8
 9: 9 2
 10:
 11: 11
 12: 12
 13: 13
 14: 14
*/

#define STACK_MAX 100

struct stack {
    int     data[STACK_MAX];
    int     size;
};
typedef struct stack stack;


void init(stack *S) {
    S->size = 0;
}

void empty(stack *S) {
    S->size = 0;
}

void push(stack *S, int d) {
    S->data[S->size++] = d;
}

int pop(stack *S) {
    if (S->size <= 0)
        return -1;
    return S->data[--S->size];
}

void print(stack *S) {
    
    int i;
    if(S->size == 0)
        return;
    
    for(i=0; i<S->size; i++)
        printf(" %d", S->data[i]);
}

stack blocks[25];
int position[25];
int N;


void clear(int element) { /* clear blocks on top of element and push them to their initial position */

    int i;
    while(1) {
        i = pop(&blocks[position[element]]);
        if (i == element) {
            push(&blocks[position[element]], i);
            return;
        }
        else {
            push(&blocks[i], i);
            position[i] = i;
        }
    }
}

void move(int from, int to) {
    
    int i;
    stack temp;
    init(&temp);
    
    do {
        i = pop(&blocks[position[from]]);
        push(&temp, i);
    } while(i != from);
    
    i = pop(&temp);
    
    while(i != -1) {
        push(&blocks[position[to]], i);
        position[i] = position[to];
        i = pop(&temp);
    }
}

void print_all(int N) {
    
    int i;
    for (i=0; i<N; i++) {
        printf("%d:", i);
        print(&blocks[i]);
        printf("\n");
    }
    
}

int main() {
    
	int from, to, i;
    char command[5], orientation[5];

    scanf("%d\n", &N);
    
    for (i=0; i<N; i++) { /* initially contains one block */
        init(&blocks[i]);
        push(&blocks[i], i);
    }
    
    for (i=0; i<N; i++) /* each block, initially at default position */
        position[i] = i;
    
	while (1) {
        
        scanf("%s", command);
        
        if (!strcmp(command, "quit"))
            break;
        
        scanf("%d%s%d", &from, orientation, &to);
        
        if (position[from] == position[to])
            continue;
        
        if (!strcmp(command, "move"))
            clear(from);
        
        if (!strcmp(orientation, "onto"))
            clear(to);
        
        move(from, to);
        }
    
    print_all(N);
    
	return 0;
}