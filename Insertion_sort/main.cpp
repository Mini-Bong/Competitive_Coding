#include <iostream>

using namespace std;
void insertion_sort(int arr[], int n)
{
    int key=0,j,i;
    for(i=0; i<n; i++);
    {
        key=arr[i];
        j=i-1;
        while(j>=0 && arr[j]>key)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
    for(i=0; i<n; i++)
    {
        cout<<arr[i]<<"\n";
    }
}
int main()
{
    int n;
    cout << "Ente the numbr of elements";
    cin>>n;
    int arr[n];
    cout<<"Enter all elements:";
    for(int i=0; i<n; i++)
    {

        cin>>arr[i];
    }
    insertion_sort(arr,n);
    return 0;
}
