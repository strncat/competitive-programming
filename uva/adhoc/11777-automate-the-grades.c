#include <stdio.h>

/* UVa [11777 - Automate the Grades]
 Input
 3
 15 18 25 8 15 17 12
 20 20 30 10 20 20 20
 20 20 30 10 18 0 0
 Output
 Case 1: B
 Case 2: A
 Case 3: B
 
 Term 1 – 20%
 Term 2 – 20%
 Final – 30%
 Attendance – 10%
 Class Tests – 20%
 The letter grades:
 A >= 90%
 B >= 80% & < 90%
 C >= 70% & < 80%
 D >= 60% & < 70%
 F  < 60%
*/

int main() {
    
    int i, cases, term1, term2, final, attendance, test1, test2, test3;
    double avg_test, average;
    
    scanf("%d", &cases);
    
    for (i=1; i<=cases; i++) {
        
        /* Term1  Term2  Final  Attendance  Class_Test1  Class_Test2  Class_Test3 */
        scanf("%d %d %d %d %d %d %d", &term1, &term2, &final, &attendance, &test1, &test2, &test3);
        
        if (test1 <= test2 && test1 <= test3)
            avg_test = (test2+test3)/2.0;
        else if (test2 <= test1 && test2 <= test3)
            avg_test = (test1+test3)/2.0;
        else
            avg_test = (test1+test2)/2.0;
        
        average = term1 + term2 + final + attendance + avg_test;
        
        printf("Case %d: ", i);
        
        if (average >= 90)
            printf("A");
        else if (average >= 80)
            printf("B");
        else if (average >= 70)
            printf("C");
        else if (average >= 60)
            printf("D");
        else
            printf("F");
        printf("\n");
    
    }
    return 0;
}
