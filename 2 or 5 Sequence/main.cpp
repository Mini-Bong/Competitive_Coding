#include <iostream>
#include<vector>
using namespace std;

int main()
{
    int two = 2;
    int five = 5;
    vector<int> arr;
    arr.push_back(two);
    arr.push_back(five);
    vector<int> temp;
    int count = 5;
    cout<<two<<" "<<five<<" ";
    while(count--)//hjj
    {
        for(int i=0; i<arr.size(); i++){
            temp.push_back(arr[i]*10+two);
            temp.push_back(arr[i]*10+five);
        }
        arr.clear();
        arr = temp;
    }
    for(int i=0; i<temp.size(); i++)
    {
        cout<<temp[i]<<" ";
    }
    return 0;
}
