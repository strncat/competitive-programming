//
//  code forces
//  A. Comparing Two Long Integers
//
//  Created by Fatima B on 1/11/16.
//  Copyright © 2016 Fatima B. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <string.h>

int main() {
    char a[1000001], b[1000001];
    scanf("%s %s", a, b);

    // 0000345
    // 034

    int n = (int) strlen(a);
    int i, j;
    for (i=0; i < n; i++) {
        if (a[i] != '0') {
            break;
        }
    }
    int m = (int) strlen(b);
    for (j=0; j < m; j++) {
        if (b[j] != '0') {
            break;
        }
    }

    if (n-i > m-j) {
        printf(">\n");
    } else if (n-i < m-j) {
        printf("<\n");
    } else {
        while (i < n && j < m) {
            if (a[i] > b[j]) {
                printf(">\n");
                return 0;
            } else if (b[j] > a[i]) {
                printf("<\n");
                return 0;
            }
            i++;
            j++;
        }
        printf("=\n");
    }



    return 0;
}
