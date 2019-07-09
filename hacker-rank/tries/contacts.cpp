//
//  main.cpp
//  https://www.hackerrank.com/challenges/contacts/problem
//
//  Created by FB on 7/8/19.
//  Copyright © 2019 FB. All rights reserved.
//

#include <iostream>
#include <queue>

#define SIZE 26

typedef struct node {
    int value;
    bool marker;
    struct node *children[SIZE] = {NULL}; // 26 links / children
} node;

typedef struct trie {
    node *root;
    trie() {
        root = new node();
    }

    // collect matches recursively from all branches
    // save them in q
    void collect(node *current, std::string prefix,
                 std::queue<std::string> &q) {
        if (current == NULL) { return; }
        if (current->value != 0) {
            q.push(prefix);
        }
        for (int i = 0; i < SIZE; i++) {
            if (current->children[i] != NULL) {
                char c = i + 'a';
                collect(current->children[i], prefix + c, q);
            }
        }
    }

    // prefix match: print all possible matches
    int words_with_prefix(std::string prefix) {
        node *current = search(prefix);
        if (current == NULL) { return 0; } // no matches
        /*
        std::queue<std::string> q;
        collect(current, prefix, q);
        while (!q.empty()) {
            //printf("%s\n", q.front().c_str());
            q.pop();
        }
        */
        return current->value;
    }

    // only return true if it's an exact match
    bool exact_match(std::string word) {
        node *current = search(word);
        return current && current->marker;
    }

    // search for any word/prefix
    node* search(std::string word) {
        long m = word.length();
        node *current = root;
        for (int i = 0; i < m; i++) {
            int index = word[i] - 'a';
            if (!current->children[index]) { // null pointer
                return NULL; // not found
            }
            // move to the child
            current = current->children[index];
        }
        current->marker = true;
        return current;
    }

    void insert(std::string word) {
        if (search(word)) { // word exists
            return;
        }
        int length = (int) word.length();
        node *current = root;
        current->value++; // increment word count
        for (int i = 0; i < length; i++) {
            int index = word[i] - 'a';
            if (!current->children[index]) {
                 // this letter doesn't exist, create it
                current->children[index] = new node();
            }
            // this letter has a link already, follow it along
            current = current->children[index];
            current->value++;
        }
    }
} trie;



int main() {
    freopen("in.txt", "r", stdin);

    int tests;
    scanf("%d", &tests);

    trie t;
    std::string op, word;
    while (tests--) {
        std::cin >> op >> word;
        if (op == "add") {
            t.insert(word);
        } else { // find
            printf("%d\n", t.words_with_prefix(word));
        }
    }
    return 0;
}
