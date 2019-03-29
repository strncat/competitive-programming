//
//  main.cpp
//  uhunt
//
//  706 - LC-Display
//  2017/02/19
//
// note: after getting Accepted I looked up other solutions and guess what? my solution is ugly
// and there are so many pretty and neat solutions out there!!

#include <iostream>
#include <string.h>

char a[200][200];

void print(int size, int s) {
    for (int i = 0; i < 2*s+3; i++) {
        for (int j = 0; j < (s+2)*size+size-1; j++) {
            printf("%c", a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void zero(int p, int s, int last_column, int last_row) {
    for (int j = p+1; j < last_column; j++) {
        a[0][j] = '-';
    }
    for (int i = 1; i < s+1; i++) { // s vertical lines
        a[i][p] = '|';
        a[i][last_column] = '|';
    }
    for (int i = s+2; i < (s+2)+s; i++) { // s vertical lines
        a[i][last_column] = '|';
        a[i][p] = '|';
    }
    for (int j = p+1; j < last_column; j++) {
        a[last_row][j] = '-';
    }
}
void one(int p, int s, int last_column, int last_row) {
    for (int i = 1; i < s+1; i++) { // s vertical lines
        a[i][last_column] = '|';
    }
    for (int i = s+2; i < (s+2)+s; i++) { // s vertical lines
        a[i][last_column] = '|';
    }
}

void two(int p, int s, int last_column, int last_row) {
    for (int j = p+1; j < last_column; j++) {
        a[0][j] = '-';
    }
    for (int i = 1; i < s+1; i++) { // s vertical lines
        a[i][last_column] = '|';
    }
    for (int j = p+1; j < last_column; j++) {
        a[s+1][j] = '-';
    }
    for (int i = s+2; i < (s+2)+s; i++) { // s vertical lines
        a[i][p] = '|';
    }
    for (int j = p+1; j < last_column; j++) {
        a[last_row][j] = '-';
    }
}

void three(int p, int s, int last_column, int last_row) {
    for (int j = p+1; j < last_column; j++) {
        a[0][j] = '-';
    }
    for (int i = 1; i < s+1; i++) { // s vertical lines
        a[i][last_column] = '|';
    }
    for (int j = p+1; j < last_column; j++) {
        a[s+1][j] = '-';
    }
    for (int i = s+2; i < (s+2)+s; i++) { // s vertical lines
        a[i][last_column] = '|';
    }
    for (int j = p+1; j < last_column; j++) {
        a[last_row][j] = '-';
    }
}

void four(int p, int s, int last_column, int last_row) {
    for (int i = 1; i < s+1; i++) { // s vertical lines
        a[i][p] = '|';
        a[i][last_column] = '|';
    }
    for (int j = p+1; j < last_column; j++) {
        a[s+1][j] = '-';
    }
    for (int i = s+2; i < (s+2)+s; i++) { // s vertical lines
        a[i][last_column] = '|';
    }
}

void five(int p, int s, int last_column, int last_row) {
    for (int j = p+1; j < last_column; j++) {
        a[0][j] = '-';
    }
    for (int i = 1; i < s+1; i++) { // s vertical lines
        a[i][p] = '|';
    }
    for (int j = p+1; j < last_column; j++) {
        a[s+1][j] = '-';
    }
    for (int i = s+2; i < (s+2)+s; i++) { // s vertical lines
        a[i][last_column] = '|';
    }
    for (int j = p+1; j < last_column; j++) {
        a[last_row][j] = '-';
    }
}

void six(int p, int s, int last_column, int last_row) {
    for (int j = p+1; j < last_column; j++) {
        a[0][j] = '-';
    }
    for (int i = 1; i < s+1; i++) { // s vertical lines
        a[i][p] = '|';
    }
    for (int j = p+1; j < last_column; j++) {
        a[s+1][j] = '-';
    }
    for (int i = s+2; i < (s+2)+s; i++) { // s vertical lines
        a[i][last_column] = '|';
        a[i][p] = '|';
    }
    for (int j = p+1; j < last_column; j++) {
        a[last_row][j] = '-';
    }
}

void seven(int p, int s, int last_column, int last_row) {
    for (int j = p+1; j < last_column; j++) {
        a[0][j] = '-';
    }
    for (int i = 1; i < s+1; i++) { // s vertical lines
        a[i][last_column] = '|';
    }
    for (int i = s+2; i < (s+2)+s; i++) { // s vertical lines
        a[i][last_column] = '|';
    }
}

void eight(int p, int s, int last_column, int last_row) {
    for (int j = p+1; j < last_column; j++) {
        a[0][j] = '-';
    }
    for (int i = 1; i < s+1; i++) { // s vertical lines
        a[i][p] = '|';
        a[i][last_column] = '|';
    }
    for (int j = p+1; j < last_column; j++) {
        a[s+1][j] = '-';
    }
    for (int i = s+2; i < (s+2)+s; i++) { // s vertical lines
        a[i][last_column] = '|';
        a[i][p] = '|';
    }
    for (int j = p+1; j < last_column; j++) {
        a[last_row][j] = '-';
    }
}
void nine(int p, int s, int last_column, int last_row) {
    for (int j = p+1; j < last_column; j++) {
        a[0][j] = '-';
    }
    for (int i = 1; i < s+1; i++) { // s vertical lines
        a[i][p] = '|';
        a[i][last_column] = '|';
    }
    for (int j = p+1; j < last_column; j++) {
        a[s+1][j] = '-';
    }
    for (int i = s+2; i < (s+2)+s; i++) { // s vertical lines
        a[i][last_column] = '|';
    }
    for (int j = p+1; j < last_column; j++) {
        a[last_row][j] = '-';
    }
}

int main() {
    //freopen("sample.in", "r", stdin);
    int s;
    char num[10];
    while(scanf("%d %s", &s, num) == 2) {
        if (num[0] == '0' && s == 0) {
            break;
        }

        // reset;
        for (int i = 0; i < 200; i++) {
            for (int j = 0; j < 200; j++) {
                a[i][j] = ' ';
            }
        }

        int size=(int)strlen(num);

        // Each digit occupies exactly s + 2 columns and 2s + 3 rows.
        int p = 0;
        for (int i = 0; i < size; i++) {
            int last_column = p+(s+2)-1; // last column is (start position + length (s+2)) - 1
            int last_row = (2*s+3)-1;
            switch(num[i]) {
                case '0':
                    zero(p, s, last_column, last_row);
                    break;
                case '1':
                    one(p, s, last_column, last_row);
                    break;
                case '2':
                    two(p, s, last_column, last_row);
                    break;
                case '3':
                    three(p, s, last_column, last_row);
                    break;
                case '4':
                    four(p, s, last_column, last_row);
                    break;
                case '5':
                    five(p, s, last_column, last_row);
                    break;
                case '6':
                    six(p, s, last_column, last_row);
                    break;
                case '7':
                    seven(p, s, last_column, last_row);
                    break;
                case '8':
                    eight(p, s, last_column, last_row);
                    break;
                case '9':
                    nine(p, s, last_column, last_row);
                    break;
                default:
                    break;

            }
            p += s+2+1;
        }

        print(size, s);
    }
    return 0;
}