#include <iostream>

using namespace std;
int gcd(int a, int b)
{
    if(a==0)
    {
        return b;
    }
    return gcd(b%a, a);
}
int main()
{
    int a, b;
    cout<<"Enter any two numbers:";
    cin>>a>>b;
    cout<<"Lcm of tow number is: ";
    int lcm = (a*b)/gcd(a,b);
    cout<<lcm;
    return 0;
}
