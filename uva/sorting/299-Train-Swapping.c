#include <stdio.h>
#include<stdlib.h>

#define MAX 100 /* L is 50 */
#define N 4

int _merge_sort(int arr[], int temp[], int left, int right);
int merge(int arr[], int temp[], int left, int mid, int right);
int merge_sort(int arr[], int array_size);
void print_me(int a[]); /* debug */

int main() {
    
    int inversions=0, test_cases=0, n=0, i=0;
    int x[MAX];
    
    /*print_me(x);*/
    
    scanf("%d", &test_cases);
    
    while(test_cases > 0)
    {
        inversions = 0;
        n = 0;
        
        scanf("%d", &n);
        
        for (i=0; i<n; i++) {
            scanf("%d", &x[i]);
        }
        
        inversions = merge_sort(x, n);
        
        printf("Optimal train swapping takes %d swaps.\n", inversions);
        
        test_cases--;
    }
    

    
    return 0;
    
}

int merge_sort(int arr[], int array_size)
{
    int *temp = (int *)malloc(sizeof(int)*array_size);
    return _merge_sort(arr, temp, 0, array_size - 1);
}

int _merge_sort(int arr[], int temp[], int left, int right)
{
    int mid, inv_count = 0;
    if (right > left)
    {
        mid = (right + left)/2;
        
        /*printf("\nmerge_sort(left=%d  right=%d)\n", left, mid);*/
        inv_count  = _merge_sort(arr, temp, left, mid);
        
        /*printf("\nmerge_sort(left=%d  right=%d)\n", mid+1, right);*/
        inv_count += _merge_sort(arr, temp, mid+1, right);
        
        /*printf("\nmerge(left=%d  mid=%d   right=%d)\n", left, mid+1, right);*/
        inv_count += merge(arr, temp, left, mid+1, right);
    }
    return inv_count;
}

int merge(int arr[], int temp[], int left, int mid, int right)
{
    int i, j, k;
    int count = 0;
    
    i = left;
    j = mid;
    k = left;
    
    while ((i <= mid - 1) && (j <= right))
    {
        if (arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            /*printf("%d is greater than %d,  %d more inversion(s)\n", arr[i], arr[j], mid-i);*/
            temp[k++] = arr[j++];
            
            count += (mid - i);
        }
    }
    
    while (i <= mid - 1)
        temp[k++] = arr[i++];
    
    while (j <= right)
        temp[k++] = arr[j++];
    
    for (i=left; i <= right; i++)
        arr[i] = temp[i];
    
    /*print_me(arr);*/
    
    return count;
}

void print_me(int a[])
{
    int i=0;
    for (i=0; i<N; i++)
        printf("%d  ", a[i]);
    printf("\n");
}


