#include <iostream>

using namespace std;

// iterative function to calculate (a^b)mod m in O(log y) time complexity.
int power(int a, unsigned int b, int m){

    int res = 1; // initialize result

    a = a%m; // update a if it is more then or equal to m

    if(a==0) // In case if a is divisible by m then any power of a mod p will be zero
    {
        return 0;
    }
    while(b>0)
    {
        // b is odd, multiply a with result.
        if(b&1){
            res = (res*a)%m;
        }
        // b must be even now
        b = b>>1; // bit operation ie, b = b/2
        a = (a*a)%m;
    }
    return res;
}


int main()
{
    int a = 7;
    int b = 416;
    int m = 645;
    cout<<"power is :"<<power(a, b, m);
    return 0;
}
