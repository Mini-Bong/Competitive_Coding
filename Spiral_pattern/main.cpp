#include <iostream>

using namespace std;
int val=1;
int arr[10][10]={{0}};
void Spiral_pattern(int n, int i)
{
    if(n==1 || n==0)
    {
        return;
    }
    else
    {
        // for storing the top values of the grid
        for(int a=i; a<n+i; a++)
        {
            arr[i][a]=val;
            val++;
        }
        // for storing the right side values of the grid
        for(int a=i+1; a<n+i; a++)
        {
            arr[a][n-1+i]=val;
            val++;
        }
        // for storing the bottom values of the grid
        for(int a=n-2+i; a>=i; a--)
        {
            arr[n-1+i][a] = val;
            val++;
        }
        //for storing the left side values of the grid
        for(int a=n-2+i; a>i; a--)
        {
            arr[a][i] = val;
            val++;
        }
    }
    Spiral_pattern(n-2, i+1);
}
int main()
{
    int n;
    cout <<"Enter any number:";
    cin>>n;
    int i=0;
    if(n%2!=0)
    {
        arr[n/2][n/2]=n*n;
    }
    Spiral_pattern(n,i);
    for(int a=0; a<n; a++)
    {
        for(int b=0; b<n; b++)
        {
            cout<<arr[a][b]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
