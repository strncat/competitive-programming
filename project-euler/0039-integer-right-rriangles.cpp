//
//
//  Project Euler
//
//  Created by FB on 01/17/25.
//  39 Integer Right Triangles https://projecteuler.net/problem=39
//
//

#include <iostream>
#include <math.h>
#include <algorithm>
#include <sstream>
#include <cassert>

int main(int argc, const char * argv[]) {
    clock_t begin, end;
    double time_spent;
    begin = clock();
    
    int max = 0;
    int max_p = 0;
    for (int p = 1; p <= 1000; p++) {
        int count = 0;
        int limit = p/2;
        for (int a = 1; a <= limit/2; a++) {
            int pa = p - a;
            int c = (a*a + pa*pa) / (2*pa);
            // we want to know if this fraction is an intger (aa + papa) / 2*pa
            if (c * 2 * pa != a*a + pa*pa) {
                // c is not a solution since the fraction isn't an integer
                continue; // choose another a
            }
            //int b = p - a - c;
            //printf("Solution {%d, %d, %d}\n", a, b, c);
            count++;
        }
        if (count > max) {
            max = count;
            max_p = p;
        }
    }
    printf("max = %d, max_p = %d\n", max, max_p);

    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("time spent = %f\n", time_spent);
    
    return 0;
}

