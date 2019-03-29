//
//  main.cpp
//  uhunt
//
//  913 - Joana and the Odd Numbers
//  2017/02/08
//
/*
 This took a while to figure out but eventually found a resource that helped a lot!
 http://math.cmu.edu/~bkell/21110-2010s/formula.html

Let's numbered the lines as follows:
n=0            3 5 7
n=1        9 11 13 15 17
n=2     19 21 23 25 27 29 31
n=3   33 35 37 39 41 43 45 47 49
n=4 51 53 55 57 59 61 63 65 67 69 71

Let's take 7 as an example, the last number in every row is the following sequence
7, 17, 31, 49, 71, 97, ....

Using the resource above. 
Let's take the difference between consecutive terms until we might see a constant term:

7, 17, 31, 49, 71, 97, ....
 10  14  18  22  26
   4   4   4   4
Since we took the difference twice, this will have a polynomial solution of the form
an^2 + bn + c
 
We solve the equation easily if try three of the numbers in the sequence
 f(0) = 7
 f(1) = 17
 f(2) = 31
a = 2, b = 8 and c = 7
 
to get the line number from the (number of odd numbers) is easy
line number = (n - 3) / 2

*/

#include <iostream>

int main() {
    //freopen("sample.in", "r", stdin);
    long int n;
    while (scanf("%ld", &n) != EOF) {
        if (n == 1) { printf("1\n"); }
        long int line = (n - 3) / 2;
        // formula = 2n^2 + 8n + (3 or 5 or 7)
        long int f = 2*line*line + 8*line;
        long int sum = (f + 3) + (f + 5) + (f + 7);
        printf("%ld\n", sum);
    }
    return 0;
}