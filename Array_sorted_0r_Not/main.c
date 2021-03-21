#include <stdio.h>
#include <stdlib.h>
int isArraySorted(int arr[], int n)
{
    if(n==1)
    {
        return 1;
    }
    return (arr[n-1]<arr[n-2])?0:isArraySorted(arr, n-1);
}
int main()
{
    int n;
    printf("Enter the size of array: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the array elements");
    for(int i=0; i<n; i++)
    {
        scanf("%d", &arr[i]);
    }
    if(isArraySorted(arr, n))
    {
        printf("Yes, Array is sorted\n");
    }
    else
    {
        printf("Array is not sorted");
    }
    return 0;
}




