#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* 10282 - Babelfish
 Sample Input
 
 dog ogday
 cat atcay
 pig igpay
 froot ootfray
 loops oopslay
 
 atcay
 ittenkay
 oopslay
 Output for Sample Input
 
 cat
 eh
 loops
*/
/* -------------------------------- HASH ---------------------------------------- */

struct nlist { /* table entry */
    struct nlist *next;
    char *name;
    char *defn;
};

#define HASHSIZE 100010
static struct nlist *hashtab[HASHSIZE]; /* pointer table */

unsigned hash(char *s) {
    
    unsigned hashval; /* unsigned guarantees non-negativity */
    
    for (hashval = 0; *s != '\0'; s++)
        hashval = *s + 31 * hashval;
    
    return hashval % HASHSIZE;
}

struct nlist *lookup(char *s) {
    
    struct nlist *np;
    
    for (np = hashtab[hash(s)]; np != NULL; np = np->next)
        
        if (strcmp(s, np->name) == 0)
            return np;
    
    return NULL;
}

struct nlist *install(char *name, char *defn) {
    
    struct nlist *np;
    unsigned hash_value;
    
    if ((np = lookup(name)) == NULL) { /* not found so add it */
        
        np = malloc(sizeof(struct nlist));
        
        if (np == NULL || (np->name = strdup(name)) == NULL) /* not allocated or string not copied properly */
            return NULL;
        
        hash_value = hash(name);
        np->next = hashtab[hash_value]; /* added at the begining of the list */
        hashtab[hash_value] = np;
    }
    
    else /* already there */
        free((void *) np->defn); /*free previous defn and replace it with a new one below => */
    
    if ((np->defn = strdup(defn)) == NULL) /* replace it with the new defition => if something went wrong, return null */
        return NULL;
    
    return np;
}

int main() {
    
    char line[100], word1[100], word2[100];
    struct nlist *result;
    
    while (fgets(line, 100, stdin)) {
        if (line[0] == '\n')
            break;
        
        sscanf(line, "%s %s", word1, word2);
        
        install(word2, word1);
    }
    
    while (scanf("%s", line) == 1) {
        
        result = lookup(line);
        
        if (result)
            printf("%s\n", result->defn);
        else
            printf("eh\n");
        
    }

    return 0;
}