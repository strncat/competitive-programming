/*
 ID: fatima.1
 PROG: transform
 LANG: C++11
 */
//
//  Usaco Training
//  1.2 Transformations
//

#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

#define N 10

void print(char c[N][N], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%c", c[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void rotate90(char c[N][N], int n) {
    // 1 2 3 1
    // 3     2
    // 2     3
    // 1 3 2 1
    int layers = n/2;
    for (int l = 0; l < layers; l++) {
        int first = l;
        int last = n - l - 1;
        for (int i = first; i < last; i++) {
            int offset = i - first;
            int save = c[first][i];

            // save top left
            c[first][i] = c[last - offset][first];

            // bottom left
            c[last - offset][first] = c[last][last - offset];

            // bottom right
            c[last][last - offset] = c[i][last];

            // top right
            c[i][last] = save;
        }
    }
}

void swap(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

void reflectionH(char c[N][N], int n) {
    int layers = n / 2;
    for (int j = 0; j < layers; j++) {
        // swap first column with last column
        for (int i = 0; i < n; i++) {
            swap(&c[i][j], &c[i][n-j-1]);
        }
    }
}

bool equal(char c[N][N], char r[N][N], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (c[i][j] != r[i][j]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    freopen("transform.in", "r", stdin);
    freopen("transform.out", "w", stdout);

    int n; // max 10
    scanf("%d\n", &n);
    char c[N][N], final[N][N];

    // original matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%c", &c[i][j]);
        }
        scanf("\n");
    }

    // final matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%c", &final[i][j]);
        }
        scanf("\n");
    }

    // test for all kinds of transformations
    // print(c, n);
    // print(final,n);

    rotate90(c, n); // #1: 90 Degree Rotation: The pattern was rotated clockwise 90 degrees
    if (equal(c, final, n)) {
        printf("1\n");
        return 0;
    }

    rotate90(c, n); // #2: 180 Degree Rotation: The pattern was rotated clockwise 180 degrees
    if (equal(c, final, n)) {
        printf("2\n");
        return 0;
    }

    rotate90(c, n); // #3: 270 Degree Rotation: The pattern was rotated clockwise 270 degrees
    if (equal(c, final, n)) {
        printf("3\n");
        return 0;
    }

    rotate90(c, n); // back to 0


    // #4: Reflection: The pattern was reflected horizontally (turned into a mirror image of itself
    // itself by reflecting around a vertical line in the middle of the image)
    reflectionH(c, n);
    if (equal(c, final, n)) {
        printf("4\n");
        return 0;
    }

    // #5: Combination: The pattern was reflected horizontally and then subjected to one of the rotations (#1-#3).
    rotate90(c, n);
    if (equal(c, final, n)) {
        printf("5\n");
        return 0;
    }

    rotate90(c, n);
    if (equal(c, final, n)) {
        printf("5\n");
        return 0;
    }

    rotate90(c, n);
    if (equal(c, final, n)) {
        printf("5\n");
        return 0;
    }

    // #6: No Change
    if (equal(c, final, n)) {
        printf("6\n");
        return 0;
    }

    // #7: Invalid Transformation
    printf("7\n");
    return 0;
}
