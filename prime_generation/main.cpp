#include<stdbool.h>
#include<iostream>
#include<stdio.h>
using namespace std;
bool isPrime(int n)
{
	if (n <= 1)
    {
        return false;
    }
	if (n <= 3)
    {
        return true;
    }

	if (n%2 == 0 || n%3 == 0)
    {
        return false;
    }

	for (int i=5; i*i<=n; i=i+6)
	{
		if (n%i == 0 || n%(i+2) == 0)
		{
		    return false;
		}
	}
	return true;
}

int main()
{

    int arr[100000];
    int n;
    printf("Enter the number upto which you want to find all prime number: ");
    scanf("%d",&n);
    int j=0;
	for(int i=2; i<n; i++)
	{
	    if(isPrime(i))
	    {
	        arr[j]=i;
	        j++;
	    }
	}
	for(int i=0; i<j; i++)
	{
	    printf("%d\n",arr[i]);
	}
	return 0;
}
