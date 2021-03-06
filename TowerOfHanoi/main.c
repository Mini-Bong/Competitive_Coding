#include <stdio.h>
#include <stdlib.h>
// In this program tower A is taken as source tower and tower B is taken as
// destination tower and tower C is as taken as auxiliary tower.
void towerOfHanoi(int n, char a, char b, char c)
{
    if(n==1)// If there is only one disk in the tower.
    {
        printf("\nMove disk 1 from tower %c to tower %c",a,b);
        return ;
    }
    towerOfHanoi(n-1, a, c, b); // Move n-1 disks from A to B, using C as auxili
    printf("\nMove disk %d from tower %c to tower %c",n, a, b);
    towerOfHanoi(n-1,c, b,a);
}
int main()
{
    int n;
    printf("Enter the number of disks: ");
    scanf("%d",&n);
    towerOfHanoi(n, 'A', 'B', 'C');
    return 0;
}
