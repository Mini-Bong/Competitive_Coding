#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<functional>
#include<iostream>
using namespace __gnu_pbds;

using namespace std;

typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>
    new_data_set;
int main()
{
    new_data_set p;
    p.insert(2);
    p.insert(5);
    p.insert(6);
    p.insert(4);
    p.insert(2);
    for(int i=0; i<5; i++)
    {
        cout<<"the at "<<i<<"third Index ::"<<*p.find_by_order(i)<<endl;
    }
    cout<<"The index of number 2::"<<p.order_of_key(2);
    cout<<"The index of number 4::"<<p.order_of_key(4);
    return 0;
}
