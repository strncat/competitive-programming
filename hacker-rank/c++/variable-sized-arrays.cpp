//
//  Hacker Rank
//  Variable Sized Arrays
//
//  Created by Fatima B on 1/23/16.
//  Copyright © 2016 Fatima B. All rights reserved.
//

#include <iostream>

int main() {
    int n = 0, m = 0, q;
    int **array;

    scanf("%d %d", &n, &q);
    array = new int*[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &m);
        array[i] = new int[m];
        for (int j = 0; j < m; j++) {
            scanf("%d", &array[i][j]);
        }
    }

    int a, b;
    for (int i = 0; i < q; i++) {
        scanf("%d %d", &a, &b);
        printf("%d\n", array[a][b]);
    }
    return 0;
}
