// The following program is the implementation of the stack using template,
// It can take any type of data type and we can push the stack and also can perform pop Operation.


#include <iostream>
using namespace std;
template<class T>
class stack
{
private:
    T *stk;
    int size;
    int top;
public:
    stack(int sz)
    {
        size=sz;
        top=-1;
        stk=new T[size];
    }
    void push(T x);
    T pop();
    void display();
};
template<class T>
void stack<T>::push(T x)
{
    if(top == size-1)
    {
        cout << "Stack is full";
    }
    else{
        top++;
        stk[top] = x;
    }
}
template<class T>
T stack<T>::pop()
{
    T x=0;
    if(top==-1)
    {
        cout<<"Stack is empty";
    }
    else
    {
        x=stk[top];
        top--;
    }
    return x;
}
template<class T>
void stack<T>::display()
{
    for(T i=0; i<=top; i++)
    {
        cout<<stk[i]<<" ";
    }
    cout<<"\n";
}
int main()
{
    stack<int> s(10);
    s.push(10);
    s.push(20);
    s.push(30);
    s.display();
    s.pop();
    s.display();
    return 0;
}
