#include <stdio.h>
#include <stdlib.h>

/* 10015 - Joseph's Cousin
 n <= 3501
 */

/* Linked List Part */
typedef struct people {
    int id;
    struct people *next;
} people;

void insert_people(people **head, int x) { /* insert at the begining */
    
    people *person = (people *)malloc(sizeof(people));
    person->id = x;

    if (*head == NULL) 
        person->next = NULL;
    else 
        person->next = *head;
      
    *head = person;
}

people* delete_people(people *head, int position) { /* delete node at position */
    
    people *del=head, *temp;
    int i=0;

    if (position == 1) {
        temp = head;
        head = head->next;
    }
    else {
        for(i = 1; i < position-1; i++)  
            del = del->next;
            
        temp = del->next;
        del->next = del->next->next;
    }
    free(temp);
    return head;
}

/* Prime Numbers */

#define N 33000
int primes[N+1];

void sieve() {
    
    int flag[N], i, m;
    
    flag[1] = 0;
    for (i = 2; i <= N; i++)
        flag[i] = 1;
    
    for (i = 2; i*i <= N; i++) 
        if (flag[i]) {
            for (m = i*i; m < N; m += 2*i)
                flag[m] = 0;
        }
    
    m=0;
    primes[m++] = 2;
    for (i = 3; i <= N; i += 2)
        if (flag[i])
            primes[m++]=i;
}

int main() {

    int n, i, j;
    people *head;
    
    sieve(); /* generate enough primes */
    
    while (scanf("%d", &n) == 1) {
        
        if (!n)
            break;
        
        head = NULL;
        for (i=n; i>=1; i--)
            insert_people(&head, i);
        
        j=0;
        i=0;
        while ( n > 1 ) {
            
            i = (i + (primes[j++] % n) - 1) % n;
            head = delete_people(head, i+1);
            n--;
        }
        printf("%d\n", head->id);
        free(head);
    }
    
    return 0;
}
