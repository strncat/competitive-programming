#include <stdio.h>
#include <string.h>

/* 10800 - Not That Kind of Graph
 
 To avoid headache you have to draw a full test case first on paper
 
 Sample Input
 7
 RCRFCRFFCCRRC
 CCCRRF
 RFCRFC
 FFFCCC
 CCCCCCCCCCCCC
 RRRRRRRR
 FFFFFFFF
 
 Sample Output
 Case #1:
 |             _
 |  _/\_/\    /
 | /      \__/
 +---------------
 
 Case #2:
 |     /\
 | ___/
 +--------
 
 Case #3:
 | /\_/\_
 +--------
 
 Case #4:
 | \
 |  \
 |   \___
 +--------
 
 Case #5:
 | _____________
 +---------------
 
 Case #6:
 |        /
 |       /
 |      /
 |     /
 |    /
 |   /
 |  /
 | /
 +----------
 
 Case #7:
 | \
 |  \
 |   \
 |    \
 |     \
 |      \
 |       \
 +---------

*/

#define N 200
#define minimum(a, b) a > b ? b : a
#define maximum(a, b) a > b ? a : b


 int main() {
    
     int length, i, j, k, test_cases, x, y, min_x, max_x, first;
     char line[60], graph[N][N];
     
     scanf("%d", &test_cases);
    
     for (i = 1; i <= test_cases; i++) {
        
         memset(graph, ' ', sizeof(graph));
         
         scanf("%s", line);
         
         length = (int) strlen(line);
         
         x = max_x = min_x = N / 2; /* starting from the bottom, N - 1 is for the x axis */
         
         first = 1;
         for (y = 0; y < length; y++) {  /* y = 0 is for the y-axis, y = 1 is a space */
             if (line[y] == 'R') { /* Rise */
                 graph[x][y + 2] = '/';
                 min_x = minimum(min_x, x);
                 x--;
                 first = 0;
             }
             else if (line[y] == 'F') { /* Fall */
                 if (!first)
                     x++;
                 max_x = maximum(max_x, x);
                 graph[x][y + 2] = '\\';
                 first = 0;
             }
             else if (line[y] == 'C') { /* Constant */
                 graph[x][y + 2] = '_';
                 max_x = maximum(max_x, x);
                 min_x = minimum(min_x, x);
                 first = 0;

             }
         }

         /* the origin */
         graph[max_x + 1][0] = '+';
         
         /* draw the x-axis */
         for (j = 1; j <= y + 2; j++)
             graph[max_x + 1][j] = '-';
         
         /* draw the y-axis */
         for (j = max_x; j >= min_x - 1; j--)
            graph[j][0] = '|';
         
         /* remove trailing spaces */
         
         for (j = min_x; j <= max_x + 1; j++) {
             for (k = N - 1; k >= 0; k--) {
                 if (graph[j][k] != ' ') {
                     graph[j][k + 1] = '\0';
                     break;
                 }
             }
         }
         printf("Case #%d:\n", i);
         
         for (j = min_x; j <= max_x + 1; j++) {
             for (k = 0; k <= length + 2; k++) {
                 if (graph[j][k] == '\0')
                     break;
                 printf("%c", graph[j][k]);
             }
             printf("\n");
         }
         printf("\n");
     }
     return 0;
}