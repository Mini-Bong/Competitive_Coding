#include <iostream>
using namespace std;
bool Is_leapyear(int year)
{
    return (((year % 4 == 0) && (year % 100 != 0)) ||
             (year % 400 == 0));
}
int dayofweek(int d, int m, int y)
{
	static int t[] = { 0, 3, 2, 5, 0, 3,
					5, 1, 4, 6, 2, 4 };
	if(m<3)
      y--;
	return ( y + y / 4 - y / 100 +
			y / 400 + t[m - 1] + d) % 7;
}
int main() {
    int t, month1, month2, year1, year2;
    cin>>t;
    while(t--)
    {
        cin>>month1>>year1;
        //cin>>month2>>year2;
        if(month1>2)
        {
            year1++;
        }
        //if(month2<2)
        //{
         //   year2--;
       // }
        for(; year1<=2020; year1++)
        {
            year2 = year1+28;
            int count=0;
        for(int i=year1; i<=year2; i++)
        {
            if(!Is_leapyear(i) && dayofweek(1,2,i)==0)
            {
                count++;
            }
            else if(dayofweek(1,2,i)==6)
            {
                count++;
            }
        }
        cout<<count<<"\n";
    }
    }
	return 0;
}
