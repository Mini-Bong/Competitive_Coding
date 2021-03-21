// This is the code for printing the all binary string of n length
// The main idea behind of this program is backtracking.
#include <stdio.h>
#include <stdlib.h>
char arr[100];
void Binary(int n)
{
    if(n<1)
    {
        printf("%s\n",arr);
    }
    else
    {
        arr[n-1]='5';
        Binary(n-1);
        arr[n-1]='2';
        Binary(n-1);
    }
}
int main()
{
    int n;
    printf("Enter the maximum size of string: ");
    scanf("%d", &n);
    Binary(n);
    return 0;
}
